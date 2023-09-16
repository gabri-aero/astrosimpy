#include <math.h>
#include <vector>
#include <iostream>
#include <initializer_list>
#include <stdexcept> 

#ifndef _MATH_HPP_
#define _MATH_HPP_

namespace math {

class vector : public std::vector<double> {
public:
    using std::vector<double>::vector;


    static vector from_initializer_list(std::initializer_list<double> ilist) {
        math::vector v;
        std::copy(ilist.begin(), ilist.end(), v.begin());
        return v;
    }
    
    vector(std::initializer_list<double> ilist) : std::vector<double>(ilist) {}

    vector operator+(const vector& v2) {
        if(this->size() != v2.size()) {
            throw std::runtime_error("Vectors to be added have different dimensions");
        }
        vector sum;
        for(int i=0; i<this->size(); i++) {
            sum.push_back(this->at(i) + v2.at(i));
        }
        return sum;
    }
    
    vector operator-(const vector& v2) {
        if(this->size() != v2.size()) {
            throw std::runtime_error("Vectors to be added have different dimensions");
        }
        vector sum;
        for(int i=0; i<this->size(); i++) {
            sum.push_back(this->at(i) - v2.at(i));
        }
        return sum;
    }

    friend vector operator*(double scalar, const vector& v) {
        math::vector result;
        for(int i=0; i<v.size(); i++) {
            result.push_back(v.at(i)*scalar);
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const vector& v) {
        os << "[ ";
        for(auto i: v) {
            os << i << " ";
        }
        os << "]";
        return os;
    }

};

};

double norm(math::vector vec);

double dot(math::vector v1, math::vector v2);

math::vector cross(math::vector v1, math::vector v2);

#endif //_MATH_HPP_