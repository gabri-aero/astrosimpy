#include "Math.hpp"

double norm(math::vector<3> vec) {
    double sum=0;
    for(auto i: vec) {
        sum += i*i;
    }
    return sqrt(sum);
}

double dot(math::vector<3> v1, math::vector<3> v2) {
    double sum=0;
    for(int i=0; i<v1.size(); i++) {
        sum += v1[i]*v2[i];
    }
    return sum;
}

math::vector<3> crossp(math::vector<3> v1, math::vector<3> v2) {
    return math::vector<3>{
        v1[1] * v2[2] - v2[1] * v1[2],
        -v1[0] * v2[2] + v2[0] * v1[2],
        v1[0] * v2[1] - v2[0] * v1[1]
    };
}