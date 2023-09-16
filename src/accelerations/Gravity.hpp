#include <bodies/Body.cpp>

#ifndef _GRAVITY_HPP_
#define _GRAVITY_HPP_

const float G = 6.673e-11;

// Body i is the body where the gravity acceleration is computed
math::vector<3> gravity(Body i, Body j) {
    math::vector<3> rij = j.get_pos() - i.get_pos();
    double mi = i.get_mass();   
    double mj = j.get_mass();
    return G*mi*mj/pow(norm(rij), 3)*rij;
}

#endif // _GRAVITY_HPP_
