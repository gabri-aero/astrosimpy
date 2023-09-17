#include <utils/Math.hpp>
#include <functional>

#ifndef _BASE_INTEGRATOR_HPP_
#define _BASE_INTEGRATOR_HPP_

class BaseIntegrator {
protected:
    double h; // step size
    double t0;
    math::vector X0;
    std::vector<std::pair<double, math::vector>> data;
public:
    std::function<math::vector(double, math::vector)> dX;
    BaseIntegrator(double step) : h{step} {};
    void set_ic(double t0, math::vector X0) {
        this->t0 = t0;
        this->X0 = X0;
        data.emplace_back(t0, X0);
    };
    void set_dX(std::function<math::vector(double, math::vector)> dX_func) {
        this->dX = dX_func;
    };
    void run(double tf) {
        for(double t=t0; t < tf; t+=h) {
            data.emplace_back(t+h, integrate());
        }
    }
    std::vector<std::pair<double, math::vector>> get_data() const {
        return data;
    }
    virtual math::vector integrate() = 0;
};

#endif // _BASE_INTEGRATOR_HPP_