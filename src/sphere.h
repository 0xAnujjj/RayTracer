#ifndef SPHERE_H
#define SPHERE_H

#include "hitt.h"
#include "vec3.h"
using namespace std;
class sphere: public hittable {
    public:
    sphere(const point3& center, double radius): center(center), radius(fmax(0,radius)) {}

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        vec3 oc = center - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius*radius;
        auto discriminant = h*h - a*c;

        if(discriminant < 0)
            return false;
        
        auto squared = sqrt(discriminant);
        
        // nearest root that lies in the range...
        auto root = (h - squared) / a;
        if(root <= ray_tmin || ray_tmax <= root) {
            root = (h + squared) / a;
            if(root <= ray_tmin || ray_tmax <= root)
                return false;
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        rec.normal = (rec.p - center) / radius;

        return true;
    }

    private:
    point3 center;
    double radius;
};

#endif

/*
    sphere class inherited from hittable class(from hitt.h file) represents a spherical object in the scene.
    
    hit() method takes an incoming ray and checks if it intersects the sphere and then using formula for intersection
    points, it returns true if intersection happens within range...otherwise, false
    
*/
// t_min to t_max only since we assume the ray's direction to be positive i.e. in negative z-axis...

// fmax() returns the maximum of the two floting-point args...
// fmin() returns the minimum of ,, ...