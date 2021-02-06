#include <asio.hpp>
#include <future>
#include <iostream>

template <class T> auto make_ready_future(T &&value) {
    std::promise<std::decay_t<T>> result_promise;
    std::future<std::decay_t<T>> result_future = result_promise.get_future();
    result_promise.set_value(value);
    return result_future;
}

template <class FN, class Iterator>
auto parallel_reduce(auto ex, Iterator begin, Iterator end, FN fn) {
    auto second = std::next(begin);
    const bool is_single_element = second == end;
    const bool is_single_pair =
        !is_single_element && (std::next(second) == end);
    if (is_single_element) {
        return make_ready_future(*begin);
    } else if (is_single_pair) {
        return asio::post(ex, asio::use_future([begin, second, &fn] {
                              return fn(*begin, *second);
                          }));
    } else {
        // we would probably add an heuristic here for small ranges
        size_t n = std::distance(begin, end);
        auto half = std::next(begin, n / 2);
        auto lhs = parallel_reduce(ex, begin, half, fn);
        auto rhs = parallel_reduce(ex, half, end, fn);
        return make_ready_future(lhs.get() + rhs.get());
    }
}

int main() {
    // Some references:
    // - https://think-async.com/Asio/
    // - https://think-async.com/Asio/asio-1.18.1/doc/asio/std_executors.html
    // - https://github.com/chriskohlhoff/executors
    // - https://taskflow.github.io/taskflow/index.html
    // - Read the unit tests, such as asio/src/tests/unit/thread_pool.cpp

    /*
     * Executors and execution contexts
     */
    // Creating an execution context: a thread pool
    // - Execution context: place where we can execute functions
    // - A thread pool is an execution context.
    // An execution context is:
    // - Usually long lived.
    // - Non-copyable.
    // - May contain additional state, such as timers, and threads
    asio::thread_pool pool;

    // Creating an executor from an executor context
    // - Executor: set of rules governing where, when and how to run
    // a function object
    // - A thread pool has an executor.
    // - Its executor rule is: Run function objects in the pool and nowhere
    // else. An executor is:
    // - May be long or short lived.
    // - Lightweight and copyable.
    // - May be customized on a fine-grained basis, such as exception behavior,
    // and order
    auto ex = pool.executor();
    std::cout << (&pool == &ex.context()) << std::endl;

    // Executing simple function
    ex.execute([&ex] {
        std::cout << "Task in executor" << std::endl;
        std::cout << "ex.running_in_this_thread(): "
                  << ex.running_in_this_thread() << std::endl;
    });
    std::cout << "ex.running_in_this_thread(): " << ex.running_in_this_thread()
              << std::endl;

    /*
     * Queueing tasks
     */

    // Executing directly in the thread pool
    // Execution behaviour according to eagerness:
    // - https://github.com/chriskohlhoff/executors
    // - Dispatch: Run the function object immediately if possible.
    //             Most eager operation.
    //             Might run before dispatch returns.
    //             If inside pool, run immediately.
    //             If outside pool, add to queue.
    asio::dispatch(ex, [&ex] {
        // This runs before finishing the function
        asio::dispatch(ex, [] { std::cout << "dispatch b" << std::endl; });
        std::cout << "dispatch a" << std::endl;
    });

    // - Post: Submit the function for later execution.
    //         Never immediately in the same thread.
    //         Always adds to pool queue.
    //         Never blocking.
    asio::post(ex, [&ex] {
        // This will all run in parallel
        asio::post(ex, [] { std::cout << "post b" << std::endl; });
        asio::post(ex, [] { std::cout << "post c" << std::endl; });
        std::cout << "post a" << std::endl;
    });

    // - Defer: Submit the function for later execution.
    //          Least eager.
    //          Implies relationship between calling thread and function.
    //          Used when function is a continuation to the calling function.
    //          The function is added to the queue after the current function
    //          ends. If inside pool, adds to a thread local queue. If outside
    //          pool, add to queue. Thread posting might immediately run it.
    //          Potentially blocking.
    asio::defer(ex, [&ex] {
        // This will all run only when this function is over
        asio::defer(ex, [] { std::cout << "defer b" << std::endl; });
        std::cout << "defer a" << std::endl;
    });

    /*
     * Returning values or waiting on tasks
     */
    // Returning value
    std::future<int> r1 = asio::post(ex, asio::use_future([]() { return 2; }));
    std::cout << "Result = " << r1.get() << std::endl;

    // Just waiting for task
    std::future<void> r2 = asio::post(
        ex, asio::use_future([]() { std::cout << "Print message"; }));
    r2.get();
    std::cout << " -> Message printed" << std::endl;

    /*
     * Limiting concurrency
     */
    // Create an strand executor
    // - A strand is an executor and an executor adapter
    // - Its rule is: Run function objects according to the underlying
    //   executor’s rules, but also run them in FIFO order and not
    //   concurrently.
    asio::strand<asio::thread_pool::executor_type> ex2(ex);
    ex2.execute([] { std::cout << "FIFO-1a" << std::endl; });
    asio::post(ex2, [] { std::cout << "FIFO-1b" << std::endl; });
    auto fifo_r = asio::post(
        ex2, asio::use_future([] { std::cout << "FIFO-1c" << std::endl; }));
    fifo_r.wait();
    std::cout << "FIFO tasks done" << std::endl;

    // Creating a promise
    std::promise<int> function_promise;
    std::future<int> function_future_result = function_promise.get_future();
    auto fn2 = [&] {
        std::cout << "Task 2 executes asynchronously" << std::endl;
        // "return" 2 by setting the promise value
        function_promise.set_value(2);
    };
    ex.execute(fn2);
    std::cout << "function_future_result.get(): "
              << function_future_result.get() << std::endl;

    // Automating the process of creating a promise
    auto fn3 = [&] {
        std::cout << "Task 3 executes asynchronously" << std::endl;
        return 3;
    };
    std::promise<int> function_promise2;
    std::future<int> function_future2 = function_promise2.get_future();
    auto package = [&](auto fn) {
        return [fn, &function_promise2] { function_promise2.set_value(fn()); };
    };
    ex.execute(package(fn3));
    std::cout << "function_future2.get(): " << function_future2.get()
              << std::endl;

    /*
     * Ordering tasks
     */
    auto task1 = asio::post(asio::use_future(
        [] { std::cout << "Task 1 executes asynchronously" << std::endl; }));

    auto task2 = asio::post(asio::use_future([]() {
        std::cout << "Task 2 executes in parallel with task 1" << std::endl;
        return 42;
    }));

    // something like task3 = task2.then([](int task2_output){...});
    auto task3 = asio::post(asio::use_future([&]() {
        int task2_output = task2.get();
        std::cout << "Task 3 executes after task 2, which returned "
                  << task2_output << std::endl;
        return task2_output * 3;
    }));

    // something like task4 = when_all(task1, task3);
    auto task4 = asio::post(asio::use_future([&]() {
        task1.wait();
        auto task3_output = task3.get();
        return task3_output;
    }));

    // something like task5 = task4.then([](std::tuple<void, int>))
    auto task5 = asio::post(asio::use_future([&]() {
        auto task4_output = task4.get();
        std::cout << "Task 5 executes after tasks 1 and 3. Task 3 returned "
                  << task4_output << "." << std::endl;
    }));
    task5.get();
    std::cout << "Task 5 has completed" << std::endl;

    /*
     * Making threads sleep
     */
    // When the threads are sleeping, they do not open room for another
    // thread in the thread pool.
    // Thus, it's sometimes useful to have extra threads depending on
    // what they are doing.
    for (int i = 0; i < 20; ++i) {
        asio::post(ex, [i] {
            std::cout << "Thread " << i << " going to sleep" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Thread " << i << " awake" << std::endl;
        });
    }

    /*
     * Parallel algorithms
     */
    auto parallel_invoke = [](auto ex, auto fn1, auto fn2) {
        asio::post(ex, fn1);
        asio::post(ex, fn2);
    };
    parallel_invoke(
        ex, [] { std::cout << "parallel_invoke a" << std::endl; },
        [] { std::cout << "parallel_invoke b" << std::endl; });

    auto parallel_for = [](auto ex, auto begin, auto end, auto fn) {
        while (begin != end) {
            asio::post(ex, [begin, &fn] { fn(*begin); });
            ++begin;
        }
    };

    std::vector<int> v = {0, 1, 2, 3, 4, 5};
    parallel_for(ex, v.begin(), v.end(), [](int x) { std::cout << x; });
    std::cout << std::endl;

    std::future<int> r = parallel_reduce(ex, v.begin(), v.end(),
                                         [](int x, int y) { return x + y; });
    std::cout << "The sum of {0, 1, 2, 3, 4, 5} is " << r.get() << std::endl;
}
