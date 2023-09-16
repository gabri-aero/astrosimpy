#include <gtest/gtest.h>
#include <bodies/Body.hpp>

TEST(TestBody, Utils) {
    Body sun{"SUN", 1, std::array<double, 6>{1, 2, 3, 4, 5, 6}};
}