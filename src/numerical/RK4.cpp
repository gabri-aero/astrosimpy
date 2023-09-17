#include "RK4.hpp"

math::vector RK4::integrate() {
    double t = data.back().first;
    math::vector X = data.back().second;
    math::vector k1 = dX(t, X)*h;
    math::vector k2 = dX(t+h/2, X+k1/2)*h;
    math::vector k3 = dX(t+h/2, X+k2/2)*h;
    math::vector k4 = dX(t+h, X+k3)*h;
    return X + (k1+2*k2+2*k3+k4)/6;
};