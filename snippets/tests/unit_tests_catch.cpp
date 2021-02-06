#include <catch2/catch_test_macros.hpp>

static int Factorial(int number) {
    return number <= 1 ? number : Factorial(number - 1) * number; // fail
    // return number <= 1 ? 1      : Factorial( number - 1 ) * number;  // pass
}

TEST_CASE("Factorial of 0 is 1 (fail)", "[single-file]") {
    REQUIRE(Factorial(0) == 1);
}

TEST_CASE("Factorials of 1 and higher are computed (pass)", "[single-file]") {
    REQUIRE(Factorial(1) == 1);
    REQUIRE(Factorial(2) == 2);
    REQUIRE(Factorial(3) == 6);
    REQUIRE(Factorial(10) == 3628800);
}