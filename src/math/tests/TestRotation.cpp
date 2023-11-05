#include <gtest/gtest.h>
#include <math/Rotation.hpp>
#include <math/Vector.hpp>


void assert_near_vector(math::vector v1, math::vector v2, double tol) {
    ASSERT_NEAR(norm(v1-v2), 0, tol);
}

TEST(RotationTest, RotationMatrix) {
    math::vector v{1, -3, 4};
    double angle = M_PI/6;

    math::vector v_xrot{1, -4.598076211353, 1.964101615138};
    math::vector v_yrot{2.866025403784, -3, 2.964101615138};
    math::vector v_zrot{2.366025403784, -2.098076211353, 4};

    assert_near_vector(R1(angle)*v, v_xrot, 1e-12);
    assert_near_vector(R2(angle)*v, v_yrot, 1e-12);
    assert_near_vector(R3(angle)*v, v_zrot, 1e-12);
}