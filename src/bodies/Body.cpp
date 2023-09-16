#include "Body.hpp"

// Body constructor
Body::Body(std::string name, double mass, std::array<double, 6> sv)
: name{name}, mass{mass}, sv{std::make_shared<std::array<double, 6>>(sv)} {
};

Body::Body(double mass, std::array<double, 6> sv) {
    Body{"UNKNOWN", mass, sv};
};

// Body setters

void Body::set_name(std::string name) {
    this->name = name;
}


// Body getters

std::array<double, 3> Body::get_pos() const {
    return std::array<double, 3>{sv->at(0), sv->at(1), sv->at(2)};
}

std::array<double, 3> Body::get_vel() const {
    return std::array<double, 3>{sv->at(3), sv->at(4), sv->at(5)};
};

std::array<double, 6> Body::get_sv() const{
    return *sv;
};

double Body::get_mass() const {
    return mass;
}

std::string Body::get_name() const {
    return name;
};