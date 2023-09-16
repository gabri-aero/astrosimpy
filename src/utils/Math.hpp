#include <math.h>
#include <array>

#ifndef _MATH_HPP_
#define _MATH_HPP_

namespace math {

template<std::size_t N>
class vector : public std::array<double, N> {
public:
    vector<N> operator+(const vector<N>& v2) {
        vector<N> sum;
        for(int i=0; i<N; i++) {
            sum.at(i) = this->at(i) + v2.at(i);
        }
        return sum;
    }
    
    vector<N> operator-(const vector<N>& v2) {
        vector<N> sum;
        for(int i=0; i<N; i++) {
            sum.at(i) = this->at(i) - v2.at(i);
        }
        return sum;
    }
};

};

double norm(math::vector<3> vec);

double dot(math::vector<3> v1, math::vector<3> v2);

math::vector<3> crossp(math::vector<3> v1, math::vector<3> v2);

#endif //_MATH_HPP_