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

template <std::size_t N>
double norm(math::vector<N> vec) {
    double sum;
    for(auto i: vec) {
        sum += i*i;
    }
    return sqrt(sum);
}

template <std::size_t N>
double dot(math::vector<N> v1, math::vector<N> v2) {
    double sum;
    for(int i=0; i<N; i++) {
        sum += v1[i]*v2[i];
    }
    return sum;
}

math::vector<3> cross(math::vector<3> v1, math::vector<3> v2) {
    return math::vector<3>{
        v1[1] * v2[2] - v2[1] * v1[2],
        -v1[0] * v2[2] + v2[0] * v1[2],
        v1[0] * v2[1] - v2[0] * v1[1]
    };
}

#endif //_MATH_HPP_