#include "OrbitalElements.hpp"
#include "StateVector.hpp"
#include <iomanip>
#include <math/Utils.hpp>

OrbitalElements::OrbitalElements(double a, double e, double raan, double i, double aop, double ta) 
    : oe{math::vector{a, e, raan, i, aop, ta}}{

}

StateVector to_sv() {
    StateVector sv{0,0,0,0,0,0};
    return sv;
}

std::ostream& operator<<(std::ostream& os, const OrbitalElements& obj) {
    os << "a : " << std::fixed << std::setprecision(3) << obj.oe[0] * 1e-3 << " km" << std::endl;
    os << "e : " << std::fixed << std::setprecision(5) << obj.oe[1] << std::endl;
    os << "RAAN : " << std::fixed << std::setprecision(2) << rad2deg(obj.oe[2]) << " deg" << std::endl;
    os << "i : " << std::fixed << rad2deg(obj.oe[3]) << " deg" << std::endl;
    os << "aop : " << std::fixed << rad2deg(obj.oe[4]) << " deg" << std::endl;
    os << "ta : " << std::fixed << rad2deg(obj.oe[5]) << " deg" << std::endl;
    return os;
}


