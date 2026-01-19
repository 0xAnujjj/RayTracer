#ifndef HITT_H
#define HITT_H

#include "ray.h"

class hit_record {
    public:
    point3 p;
    vec3 normal;
    double t;
};

class hittable {
    public:
    virtual ~hittable() = default;

    virtual bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const = 0;
};

#endif

/*
    this hittable class as a abstract base class, provides a common way to interact with
    any object that a ray can intersect with in the scene.
*/