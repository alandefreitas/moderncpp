#include <async++.h>
#include <iostream>

int main() {
    //[launch Launch tasks
    auto task1 = async::spawn(
        [] { std::cout << "Task 1 executes asynchronously" << '\n'; });

    auto task2 = async::spawn([]() -> int {
        std::cout << "Task 2 executes in parallel with task 1" << '\n';
        return 42;
    });
    //]

    //[then Task continuation
    auto task3 = task2.then([](int value) -> int {
        std::cout << "Task 3 executes after task 2, which returned " << value
                  << '\n';
        return value * 3;
    });
    //]

    //[conj Task conjunctions
    auto task4 = async::when_all(task1, task3);
    auto task5 =
        task4.then([](std::tuple<async::task<void>, async::task<int>> results) {
            std::cout << "Task 5 executes after tasks 1 and 3. Task 3 returned "
                      << std::get<1>(results).get() << '\n';
        });
    //]

    //[get Get task results
    task5.get();
    std::cout << "Task 5 has completed" << '\n';
    //]

    //[par_invoke Parallel invoke
    async::parallel_invoke(
        [] { std::cout << "This is executed in parallel..." << '\n'; },
        [] { std::cout << "with this" << '\n'; });
    //]

    //[par_for Parallel for
    async::parallel_for(async::irange(0, 5), [](int x) { std::cout << x; });
    std::cout << '\n';
    //]

    //[par_reduce Parallel reduce
    int r = async::parallel_reduce({1, 2, 3, 4}, 0,
                                   [](int x, int y) { return x + y; });
    std::cout << "The sum of {1, 2, 3, 4} is " << r << '\n';
    //]
}
