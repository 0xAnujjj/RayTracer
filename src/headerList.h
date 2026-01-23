#ifndef HEADERLIST_H
#define HEADERLIST_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>
#include <cstdlib>
#include <random>
//standard usings
using std::make_shared;
using std::shared_ptr;

//constants used
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897;

//utility funcntions used

// inline double random_double() {
//     static std::uniform_real_distribution<double> distribution(0.0,1.0);
//     static std::mt19937 generator;
//     return distribution(generator);
// }

inline double degrees_to_radians(double degrees) {
    return degrees*pi / 180.0;
}
inline double random_double() {
    //returns a random in [0,1)
    return std::rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    // random in [min, max)
    return min + (max-min)*random_double();
}

//common headers used
#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "interval.h"

#endif 