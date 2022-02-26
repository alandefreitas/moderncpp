# Signals

!!! note "Signals"

    Signals might be important to properly stop asynchronous operations, such as servers.

    [Boost.Asio](https://www.boost.org/doc/libs/1_78_0/doc/html/boost_asio/overview/signals.html) supports signal 
    handling using a class called `signal_set`. Programs may add one or more signals to the set, and then perform an
    `async_wait()` operation. 

    The specified handler will be called when one of the signals occurs. The same signal number may be registered
    with multiple `signal_set` objects, however the signal number must be used only with `Boost.Asio`.

{{ code_snippet("snippets/parallel/CMakeLists.txt", "find_asio", "cmake") }}

<hr>

{{ code_snippet("snippets/parallel/CMakeLists.txt", "signals", "cmake") }}

<hr>

{{ all_code_snippets("snippets/parallel/signals.cpp") }}

