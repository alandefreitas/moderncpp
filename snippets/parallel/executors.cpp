#include <asio.hpp>
#include <future>
#include <iostream>

template <class FN, class Iterator>
std::future<typename Iterator::value_type>
parallel_reduce(auto ex, Iterator begin, Iterator end, FN fn);

int main() {
    //[ex_context Create a thread pool execution context
    asio::thread_pool pool;
    //]

    //[executor_construct Create an executor for the thread pool
    auto ex = pool.executor();
    //]

    //[access_context Access executor context
    std::cout << (&pool == &ex.context()) << '\n';
    //]

    //[dispatch Dispatch functions
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
        asio::dispatch(ex, [] { std::cout << "dispatch b" << '\n'; });
        std::cout << "dispatch a" << '\n';
    });
    //]

    //[post Post function
    // - Post: Submit the function for later execution.
    //         Never immediately in the same thread.
    //         Always adds to pool queue.
    //         Never blocking.
    asio::post(ex, [&ex] {
        // This will all run in parallel
        asio::post(ex, [] { std::cout << "post b" << '\n'; });
        asio::post(ex, [] { std::cout << "post c" << '\n'; });
        std::cout << "post a" << '\n';
    });
    //]

    //[defer Defer function
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
        asio::defer(ex, [] { std::cout << "defer b" << '\n'; });
        std::cout << "defer a" << '\n';
    });
    //]

    /*
     * Returning values or waiting on tasks
     */

    //[future Returning value from task
    std::future<int> r1 = asio::post(ex, asio::use_future([]() { return 2; }));
    std::cout << "Result = " << r1.get() << '\n';
    //]

    //[wait Waiting for task
    std::future<void> r2 = asio::post(
        ex, asio::use_future([]() { std::cout << "Print message"; }));
    r2.get();
    std::cout << " -> Message printed" << '\n';
    //]

    /*
     * Limiting concurrency
     */

    //[strand Create an strand executor
    // A strand is an executor and an executor adapter.
    // Its rule is: Run function objects according to the underlying
    // executor’s rules, but also run them in FIFO order and not
    // concurrently.
    asio::strand<asio::thread_pool::executor_type> st(ex);
    //]

    //[execute_strand Execute function in strand
    st.execute([] { std::cout << "FIFO-1a" << '\n'; });
    //]

    //[post_strand Post function to strand
    asio::post(st, [] { std::cout << "FIFO-1b" << '\n'; });
    //]

    //[future_strand Wait for strand result
    auto fifo_r = asio::post(
        st, asio::use_future([] { std::cout << "FIFO-1c" << '\n'; }));
    fifo_r.wait();
    std::cout << "FIFO tasks done" << '\n';
    //]

    {
        //[promise Creating a promise
        std::promise<int> p;
        std::future<int> f = p.get_future();
        auto fn = [&p]() {
            std::cout << "Task 2 executes asynchronously" << '\n';
            // "return" 2 by setting the promise value
            p.set_value(2);
        };
        asio::post(fn);
        std::cout << "f.get(): " << f.get() << '\n';
        //]
    }

    {
        //[promise Set promise from function result
        auto fn3 = [] {
            std::cout << "Task 3 executes asynchronously" << '\n';
            return 3;
        };
        std::promise<int> p;
        std::future<int> f = p.get_future();
        auto package = [&p](auto fn) {
            return [fn, &p] { p.set_value(fn()); };
        };
        asio::post(package(fn3));
        std::cout << "f.get(): " << f.get() << '\n';
        //]
    }


    /*
     * Ordering tasks
     */
    //[poll Polling task continuations
    auto task1 = asio::post(asio::use_future(
        [] { std::cout << "Task 1 executes asynchronously" << '\n'; }));

    auto task2 = asio::post(asio::use_future([]() {
        std::cout << "Task 2 executes in parallel with task 1" << '\n';
        return 42;
    }));

    // something like task3 = task2.then([](int task2_output){...});
    auto task3 = asio::post(asio::use_future([&]() {
        // poll task2 for its results
        int task2_output = task2.get();
        std::cout << "Task 3 executes after task 2, which returned "
                  << task2_output << '\n';
        return task2_output * 3;
    }));
    //]

    //[conjunction Polling task conjunctions
    // something like task4 = when_all(task1, task3);
    auto task4 = asio::post(asio::use_future([&]() {
        task1.wait();
        auto task3_output = task3.get();
        return task3_output;
    }));
    //]

    //[conjunction_cont Polling conjunction continuations
    // something like task5 = task4.then([](std::tuple<void, int>))
    auto task5 = asio::post(asio::use_future([&]() {
        auto task4_output = task4.get();
        std::cout << "Task 5 executes after tasks 1 and 3. Task 3 returned "
                  << task4_output << "." << '\n';
    }));
    task5.get();
    std::cout << "Task 5 has completed" << '\n';
    //]

    /*
     * Making threads sleep
     */

    // When the threads are sleeping, they do not open room for another
    // thread in the thread pool.
    // Thus, it's sometimes useful to have extra threads depending on
    // what they are doing.
    //[thread_sleep Making threads sleep
    for (int i = 0; i < 20; ++i) {
        asio::post(ex, [i] {
            std::cout << "Thread " << i << " going to sleep" << '\n';
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "Thread " << i << " awake" << '\n';
        });
    }
    //]

    /*
     * Parallel algorithms
     */
    //[par_invoke Parallel invoke functions
    auto parallel_invoke = [](auto ex, auto fn1, auto fn2) {
        asio::post(ex, fn1);
        asio::post(ex, fn2);
    };
    //]
    //[par_invoke_call Call parallel invoke functions
    parallel_invoke(
        ex, [] { std::cout << "parallel_invoke a" << '\n'; },
        [] { std::cout << "parallel_invoke b" << '\n'; });
    //]

    //[par_for Parallel for with 1 task per element
    auto parallel_for = [](auto ex, auto begin, auto end, auto fn) {
        while (begin != end) {
            asio::post(ex, [begin, &fn] { fn(*begin); });
            ++begin;
        }
    };
    //]

    //[par_for_call Call parallel for with 1 task per element
    std::vector<int> v = {0, 1, 2, 3, 4, 5};
    parallel_for(ex, v.begin(), v.end(), [](int x) { std::cout << x; });
    std::cout << '\n';
    //]

    std::future<int> r = parallel_reduce(ex, v.begin(), v.end(),
                                         [](int x, int y) { return x + y; });
    std::cout << "The sum of {0, 1, 2, 3, 4, 5} is " << r.get() << '\n';
}

//[make_ready_future Function to make a ready future
template <class T> auto make_ready_future(T &&value) {
    std::promise<std::decay_t<T>> result_promise;
    std::future<std::decay_t<T>> result_future = result_promise.get_future();
    result_promise.set_value(value);
    return result_future;
}
//]

//[par_reduce Parallel reduce function
template <class FN, class Iterator>
std::future<typename Iterator::value_type>
parallel_reduce(auto ex, Iterator begin, Iterator end, FN fn) {
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
        // we would probably add a heuristic here for small ranges
        size_t n = std::distance(begin, end);
        auto half = std::next(begin, n / 2);
        auto lhs = parallel_reduce(ex, begin, half, fn);
        auto rhs = parallel_reduce(ex, half, end, fn);
        return make_ready_future(lhs.get() + rhs.get());
    }
}
//]