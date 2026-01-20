#ifndef HITT_H
#define HITT_H

#include "ray.h"

class hit_record {
    public:
    point3 p;
    vec3 normal;
    double t;
    bool front_face;

    void set_faceNormal(const ray& r, const vec3& outwardNormal ) {
        //outwardNormal assumed to have unitLength
        front_face = dot(r.direction(),outwardNormal) < 0;
        if (front_face)
        { normal = outwardNormal;}
        else { normal = -outwardNormal; }
    }
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

/*
  **front faces vs Back faces:**
   a ray from outside the sphere is opp. to the outside normal (ray.normal < 0)
   a ray from inside the sphere is similar to outside normal's dir. (dot prod. of ray and normal > 0{so we flip it by -normal})
*/