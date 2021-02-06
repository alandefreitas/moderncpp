#include <boost/ut.hpp>

#include <vector>

/*
 * Test suites
 */
boost::ut::suite errors = [] {
    using namespace boost::ut;
    "exception"_test = [] {
        expect(throws([] { throw 0; })) << "throws any exception";
    };

    "failure"_test = [] { expect(aborts([] { expect(false); })); };
};

int main() {
    using namespace boost::ut;
    /*
     * Requirements
     */
    expect(true);
    expect(1 == 2);
    expect(1_i == 2);            // UDL syntax
    expect(1 == 2_i);            // UDL syntax
    expect(that % 1 == 2);       // Matcher syntax
    expect(eq(1, 2));            // eq/neq/gt/ge/lt/le
    expect((1 == 1_i) >> fatal); // fatal assertion
    expect(1_i == 2);            // not executed
    expect(42l == 42_l and 1 == 2_i) << "additional info\n";

    /*
     * Test groups
     */
    "hello world"_test = [] {
        int i = 42;
        expect(42_i == i);
    };

    "[vector]"_test = [] {
        std::vector<int> v(5);

        expect((5_ul == std::size(v)) >> fatal);

        should("resize bigger") = [v] { // or "resize bigger"_test
            mut(v).resize(10);
            expect(10_ul == std::size(v));
        };

        expect((5_ul == std::size(v)) >> fatal);

        should("resize smaller") = [=]() mutable { // or "resize smaller"_test
            v.resize(0);
            expect(0_ul == std::size(v));
        };
    };

    /*
     * Behaviour Driven development
     */
    using namespace boost::ut::bdd;
    "vector"_test = [] {
        given("I have a vector") = [] {
            std::vector<int> v(5);
            expect((5_ul == std::size(v)) >> fatal);

            when("I resize bigger") = [=] {
                mut(v).resize(10);

                then("The size should increase") = [=] {
                    expect(10_ul == std::size(v));
                };
            };
        };
    };

    /*
     * BBD: feature / scenario
     */
    feature("vector") = [] {
        scenario("size") = [] {
            given("I have a vector") = [] {
                std::vector<int> v(5);
                expect((5_ul == std::size(v)) >> fatal);

                when("I resize bigger") = [=] {
                    mut(v).resize(10);

                    then("The size should increase") = [=] {
                        expect(10_ul == std::size(v));
                    };
                };
            };
        };
    };

    /*
     * Same test / different parameters
     * (Catch2 does not support that)
     */
    for (auto i : std::vector{1, 2, 3}) {
        test("parameterized " + std::to_string(i)) = [i] { // 3 tests
            expect(that % i > 0);                          // 3 asserts
        };
    }

    /*
     * Same test / different parameters
     */
    "args"_test = [](const auto &arg) {
        expect(arg > 0_i) << "all values greater than 0";
    } | std::vector{1, 2, 3};

    /*
     * Nested tests
     */
    "vector"_test = [] {
        std::vector<int> v(5);
        expect((5_ul == std::size(v)) >> fatal);
        "samesize"_test = [&] {
            std::vector<int> v2(5);
            expect(eq(v.size(), v2.size()));
        };
    };

    /*
     * Logging
     */
    "logging"_test = [] {
        log << "pre";
        expect(42_i == 43) << "message on failure";
        log << "post";
    };

    return 0;
}
