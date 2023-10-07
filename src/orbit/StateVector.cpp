#include "StateVector.hpp"
#include "OrbitalElements.hpp"

StateVector::StateVector(double rx, double ry, double rz, double vx, double vy, double vz) 
    : sv{math::vector{rx, ry, rz, vx, vy, vz}} {
}

StateVector::StateVector(math::vector sv) 
    : sv{sv} {
}

OrbitalElements StateVector::to_oe() {
    OrbitalElements oe{0,0,0,0,0,0};
    return OrbitalElements;
}