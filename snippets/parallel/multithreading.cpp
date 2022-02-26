#include <algorithm>
#include <functional>
#include <future>
#include <iostream>
#include <numeric>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

template <typename Iter> int parallel_sum(Iter beg, Iter end);

int main() {
    //[thread Launch thread
    std::thread t1([]() { std::cout << "function 1\n"; });
    //]

    //[thread_param Launch thread with function parameter
    std::thread t2(
        [](int x) { std::cout << "function 2: number " << x << '\n'; }, 10);
    //]

    //[thread_lambda Launch lambda function
    auto fn = [](int x) { std::cout << "function 3: number " << x << '\n'; };
    std::thread t3(fn, 2);
    //]

    std::cout << "main, t1, t2, and t3 now execute concurrently...\n";
    //[thread_join Wait for threads
    t1.join();
    t2.join();
    t3.join();
    //]

    //[vector Thread vector
    // - A vector can store reusable threads
    // - The cost of creating threads might be higher than their work
    std::vector<std::thread> workers;
    for (int i = 0; i < 5; i++) {
        workers.emplace_back([i]() { std::cout << "Thread function " << i; });
    }
    //]
    std::cout << "Main thread\n";

    //[vector_wait Wait for thread vector
    std::for_each(workers.begin(), workers.end(),
                  [](std::thread &t) { t.join(); });
    //]

    //[future Future value
    // - Unfortunately, async does not necessarily go to a thread pool
    // - It's best to use a library if you need async(...) a lot
    std::future<int> f2 = async(std::launch::async, [] { return 8; });
    while (f2.wait_for(std::chrono::milliseconds(100)) !=
           std::future_status::ready) {
        // do some other work
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    //]

    //[wait_Future Wait until future is ready
    f2.wait();
    //]

    //[get_future Wait and get value from the future
    std::cout << f2.get() << '\n';
    //]

    //[par_algo Call parallel algorithm
    // - Same overhead applies here
    std::vector<int> v(10000, 1);
    std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
    //]

    return 0;
}

//[par_algo_sum Parallel algorithm with one thread per subproblem
template <typename Iter> int parallel_sum(Iter beg, Iter end) {
    typename Iter::difference_type len = end - beg;

    // Solve small problems in one thread
    if (len < 1000) {
        return std::accumulate(beg, end, 0);
    }

    // Split large problems into two threads
    Iter mid = beg + len / 2;
    std::future<int> handle =
        std::async(std::launch::async, parallel_sum<Iter>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}
//]