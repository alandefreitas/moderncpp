# Executors

!!! note "Executors"

    A standard executor represents a policy as to how, when, and where a piece of code should be executed.
    The standard library does not include executors for parallel algorihms.
    
    [Boost.Asio](https://www.boost.org/doc/libs/1_78_0/doc/html/boost_asio/std_executors.html) provides a complete
    implementation of the proposed standard executors.

    Creating an execution context, such as a thread pool

    - Execution context: place where we can execute functions
    - A thread pool is an execution context.
    
    An execution context is:

    - Usually long lived.
    - Non-copyable.
    - May contain additional state, such as timers, and threads

    Creating an executor from an executor context:

    - Executor: set of rules governing where, when and how to run a function object
    - A thread pool _has_ executors that send tasks to it.
    - Its executor rule is: Run function objects in the pool and nowhere else. 

    An executor is:

    - May be long or short lived.
    - Lightweight and copyable.
    - May be customized on a fine-grained basis, such as exception behavior,
    and order
    
    Some references:

    - https://think-async.com/Asio/
    - https://think-async.com/Asio/asio-1.18.1/doc/asio/std_executors.html
    - https://github.com/chriskohlhoff/executors
    - https://taskflow.github.io/taskflow/index.html
    - Read the unit tests, such as asio/src/tests/unit/thread_pool.cpp

{{ code_snippet("snippets/parallel/CMakeLists.txt", "find_asio", "cmake") }}

<hr>

{{ code_snippet("snippets/parallel/CMakeLists.txt", "executors", "cmake") }}

<hr>

{{ all_code_snippets("snippets/parallel/executors.cpp") }}

