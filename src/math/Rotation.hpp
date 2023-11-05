#include <math/Matrix.hpp>

math::matrix R1(double a) {
    return math::matrix{
        {1, 0, 0},
        {0, cos(a), -sin(a)},
        {0, sin(a), cos(a)}
    };
}

math::matrix R2(double a) {
    return math::matrix{
        {cos(a), 0, sin(a)},
        {0, 1, 0},
        {-sin(a), 0, cos(a)}
    };
}

math::matrix R3(double a) {
    return math::matrix{
        {cos(a), -sin(a), 0},
        {sin(a), cos(a), 0},
        {0, 0, 1}
    };
}