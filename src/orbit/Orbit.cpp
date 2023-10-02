#include "Orbit.hpp"
#include <stdexcept>

Orbit::Orbit(math::vector initial_state, Representation representation) 
    : state{initial_state}, representation{representation}, central{1, math::vector{0,0,0,0,0,0}} {
    type = compute_type();
};
    
    
Orbit::Orbit(double a, double e, double i, double raan, double aop, double ta) 
: state{math::vector{a, e, i, raan, aop, ta}}, representation{KEPLERIAN_ELEMENTS}, central{0, math::vector{0,0,0,0,0,0}} {
    type = compute_type();
}

OrbitType Orbit::compute_type() {
    double energy = get_energy();
    if(energy > 0) {
        return HYPERBOLIC;
    } else if (energy < 0) { 
        return ELLIPTICAL;
    } else {
        return PARABOLIC;
    }
};

double Orbit::get_energy() {
    if(representation == KEPLERIAN_ELEMENTS) {
        double a = state[0];
        return -central.get_mu() / (2*a);
    } else if(representation == STATE_VECTOR) {
        double r = norm(state.subvec(0, 3));
        double v = norm(state.subvec(3, 6));
        double mu = central.get_mu();
        return pow(v, 2)/2 - mu/r;
    } else {
        return 0.;
    }
};