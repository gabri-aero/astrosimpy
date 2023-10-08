#include <math/Vector.hpp>
#include <iostream>

#ifndef _ORBITAL_ELEMENTS_HPP
#define _ORBITAL_ELEMENTS_HPP

class StateVector; // forward class

enum OrbitType {
    ELLIPTICAL,
    PARABOLIC,
    HYPERBOLIC
};

class OrbitalElements {
    OrbitType type;
    math::vector oe;
public:
    OrbitalElements(double a, double e, double raan, double i, double aop, double ta);
    friend std::ostream& operator<<(std::ostream& os, const OrbitalElements& obj);
};

#endif // _ORBITAL_ELEMENTS_HPP