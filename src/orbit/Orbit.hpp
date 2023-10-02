#include <math/Vector.hpp>
#include <bodies/Body.hpp>

#ifndef _ORBIT_HPP_
#define _ORBIT_HPP

enum OrbitType {
    ELLIPTICAL,
    PARABOLIC,
    HYPERBOLIC
};

enum Representation {
    STATE_VECTOR,
    KEPLERIAN_ELEMENTS
};

class Orbit {
    math::vector state; // either state vector or orbital elements
    OrbitType type;
    Representation representation;
    Body central;
    // private functions
    OrbitType compute_type();
public:
    Orbit(math::vector initial_state, Representation representation);
    Orbit(double a, double e, double i, double raan, double aop, double ta);
    Orbit to_keplerian();
    Orbit to_sv();
    math::vector get_state();
    double get_energy();
};

#endif // _ORBIT_HPP_