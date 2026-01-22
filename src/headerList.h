#ifndef HEADERLIST_H
#define HEADERLIST_H

#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

//standard usings
using std::make_shared;
using std::shared_ptr;

//constants used
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897;

//utility funcntions used
inline double degrees_to_radians(double degrees) {
    return degrees*pi / 180.0;
}

//common headers used
#include "color.h"
#include "ray.h"
#include "vec3.h"

#endif 