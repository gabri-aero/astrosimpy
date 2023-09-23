#include <stdexcept>

#ifndef _UTILS_HPP_
#define _UTILS_HPP_

unsigned long long factorial(int n) {
    return n <= 1 ? 1LL : n*factorial(n-1);
}

int C(int n, int k) {
    if (n<k) {
        throw std::invalid_argument( "Unexisting combinatorial number: k cannot be larger than n" );
    }
    return factorial(n) / (factorial(k) * factorial(n-k));
}

#endif //_UTILS_HPP_