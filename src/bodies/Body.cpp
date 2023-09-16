#include "Body.hpp"

// Body constructor

Body::Body(std::string name, double mass, math::vector<6> sv)
: name{name}, mass{mass}, sv{std::make_shared<math::vector<6>>(sv)} {
};

Body::Body(double mass, math::vector<6> sv)
: Body{"UNKNOWN", mass, sv} {
};

Body::Body(double mass, std::initializer_list<double> init_sv)
: Body(mass, math::vector<6>::from_initializer_list(init_sv)) {
};

Body::Body(std::string name, double mass, std::initializer_list<double> init_sv)
: Body(name, mass, math::vector<6>::from_initializer_list(init_sv)) {
};

// Body setters
void Body::set_name(std::string name) {
    this->name = name;
}


// Body getters

math::vector<3> Body::get_pos() const {
    return math::vector<3>{sv->at(0), sv->at(1), sv->at(2)};
}

math::vector<3> Body::get_vel() const {
    return math::vector<3>{sv->at(3), sv->at(4), sv->at(5)};
};

math::vector<6> Body::get_sv() const{
    return *sv;
};

double Body::get_mass() const {
    return mass;
}

std::string Body::get_name() const {
    return name;
};