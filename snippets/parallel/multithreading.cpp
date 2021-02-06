#include <algorithm>
#include <functional>
#include <future>
#include <iostream>
#include <numeric>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename RAIter> int parallel_sum(RAIter beg, RAIter end) {
    typename RAIter::difference_type len = end - beg;
    // Solve small problems in one thread
    if (len < 1000) {
        return std::accumulate(beg, end, 0);
    }

    // Split large problems into two threads
    RAIter mid = beg + len / 2;
    std::future<int> handle =
        std::async(std::launch::async, parallel_sum<RAIter>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}

int main() {
    // Simple algorithms
    std::vector<int> a(10000, 1);
    std::cout << "The sum is " << std::accumulate(a.begin(), a.end(), 0)
              << '\n';

    // Simple threads
    thread t1([]() { cout << "function 1" << endl; });
    thread t2([](int x) { cout << "function 2: number " << x << endl; }, 10);
    auto fn = [](int x) { cout << "function 3: number " << x << endl; };
    thread t3(fn, 2);
    cout << "main, t1, t2, and t3 now execute concurrently...\n";
    t1.join();
    t2.join();
    t3.join();

    // Thread vector
    // - A vector can store lots of reusable threads
    // - This is probably inefficient because the cost of
    //   creating threads is higher than the work they will do
    vector<thread> workers;
    for (int i = 0; i < 5; i++) {
        workers.emplace_back([i]() { cout << "Thread function " << i; });
    }
    cout << "Main thread\n";
    for_each(workers.begin(), workers.end(), [](thread &t) { t.join(); });

    // Future task
    // - Unfortunately, async does not necessarily go to a thread pool
    // - It's best to use a library if you need async(...) a lot
    // - A proposal is https://github.com/Amanieu/asyncplusplus
    future<int> f2 = async(launch::async, [] { return 8; });
    while (!f2.valid()) {
        // do some other stuff
        this_thread::sleep_for(chrono::seconds(1));
    }
    // wait until it's f2 ready to return
    f2.wait();
    // wait and get value
    cout << f2.get() << endl;

    // Parallel algorithm with async
    // - Same overhead applies here
    std::vector<int> v(10000, 1);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';

    return 0;
}