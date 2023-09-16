#include "BaseIntegrator.hpp"

#ifndef _EULER_HPP_
#define _EULER_HPP_

class Euler: public BaseIntegrator {
public:
    using BaseIntegrator::BaseIntegrator;

    math::vector integrate() override;
};

#endif // _EULER_HPP_
