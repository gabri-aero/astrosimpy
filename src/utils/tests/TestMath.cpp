#include <gtest/gtest.h>
#include <utils/Math.hpp>

TEST(MathTest, Sum) {
    math::vector<3> v1{-1., 1., 2.};
    math::vector<3> v2{0., 1., -2.};

    math::vector<3> result{-1., 2., 0.};

    ASSERT_EQ(v1+ v2, result);
}

TEST(MathTest, Difference) {
    math::vector<3> v1{-1., 1., 2.};
    math::vector<3> v2{0., 1., -2.};

    math::vector<3> result{-1., 0., 4.};

    ASSERT_EQ(v1-v2, result);
}

TEST(MathTest, ScalarProduct) {
    math::vector<3> v{-1., 1., 2.};

    math::vector<3> result{4., -4., -8.};

    ASSERT_EQ(-4*v, result);
}

TEST(MathTest, Norm) {
    math::vector<3> v{3, 4, 5};
    ASSERT_EQ(norm(v), sqrt(9 + 16 + 25));
}

TEST(MathTest, Dot) {
    math::vector<3> v1{3, 4, 5};
    math::vector<3> v2{-1, 3, 4};
    ASSERT_EQ(dot(v1, v2), 29);
}

TEST(MathTest, Cross) {
    math::vector<3> v1{3, 4, 5};
    math::vector<3> v2{-1, 3, 4};

    math::vector<3> result{1, -17, 13};

    ASSERT_EQ(crossp(v1, v2), result);
}

TEST(MathTest, Ostream) {
    math::vector<3> v1{3, 4, 5};
    std::cout << v1 << std::endl;
}
