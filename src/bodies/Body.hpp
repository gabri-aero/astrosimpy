#ifndef _BODY_HPP_
#define _BODY_HPP_

#include <string>
#include <stdlib.h>
#include <array>
#include <memory>


class Body {
protected:
    std::string name;
    double mass;
    std::shared_ptr<std::array<double, 6>> sv;
public:
    Body(double mass, std::array<double, 6> sv);
    Body(std::string name, double mass, std::array<double, 6> sv);
    // Setters
    void set_name(std::string);
    // Getters
    std::array<double, 3> get_pos() const;
    std::array<double, 3> get_vel() const;
    std::array<double, 6> get_sv() const;
    double get_mass() const;
    std::string get_name() const;
};



# endif // _BODY_HPP