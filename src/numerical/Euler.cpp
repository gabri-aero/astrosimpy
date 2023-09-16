#include "Euler.hpp"

math::vector Euler::integrate() {
    double t = data.back().first;
    math::vector X = data.back().second;
    return X + dX(t, X)*h;
};