#include <gtest/gtest.h>
#include <math/Utils.hpp>

TEST(TestUtils, Factorial) {
    ASSERT_EQ(factorial(5), 120);
    ASSERT_EQ(factorial(10), 3628800);
}

TEST(TestUtils, BinomialNumbers) {
    ASSERT_EQ(C(15, 12), 455);
}