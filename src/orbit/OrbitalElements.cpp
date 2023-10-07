#include "OrbitalElements.hpp"
#include "StateVector.hpp"

OrbitalElements::OrbitalElements(double a, double e, double raan, double i, double aop, double ta) 
    : oe{math::vector{a, e, raan, i, aop, ta}}{

}

StateVector to_sv() {
    StateVector sv{0,0,0,0,0,0};
    return sv;
}