#include <gtest/gtest.h>
#include <accelerations/Gravity.hpp>
#include <utils/Math.hpp>

TEST(GravityTest, SinglePoint) {
    math::vector<6> sv1 = {7.682, 0.845, 2.946, 4.512, 9.073, 1.234};
    Body b1{1, sv1};

    math::vector<6> sv2 = {6.789, 3.421, 8.765, 5.678, 0.123, 9.231};
    Body b2{3, sv2};

    math::vector<3> gi = gravity(b1, b2);
    math::vector<3> result = {-6.7369550815993487e-13, 1.943381443471434e-12, 4.3899598678417227e-12};

    ASSERT_EQ(gi, result);
}