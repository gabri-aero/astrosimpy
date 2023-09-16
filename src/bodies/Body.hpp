#ifndef _BODY_HPP_
#define _BODY_HPP_

#include <string>
#include <stdlib.h>
#include <memory>
#include <initializer_list>

#include <utils/Math.hpp>


class Body {
protected:
    std::string name;
    double mass;
    std::shared_ptr<math::vector<6>> sv;
public:
    Body(double mass, math::vector<6> sv);
    Body(std::string name, double mass, math::vector<6> sv);
    // Allow list initialization as well
    Body(double mass, std::initializer_list<double> sv);
    Body(std::string name, double mass, std::initializer_list<double> sv);
    // Setters
    void set_name(std::string);
    // Getters
    math::vector<3> get_pos() const;
    math::vector<3> get_vel() const;
    math::vector<6> get_sv() const;
    double get_mass() const;
    std::string get_name() const;
};


# endif // _BODY_HPP