#include "Euler.hpp"

math::vector Euler::integrate() {
    double t = data.back().first;
    math::vector X = data.back().second;
    math::vector Xn = X + dX(t, X)*h;
    return Xn;
};