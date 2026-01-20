#ifndef HITT_LIST_H
#define HITT_LIST_H

#include "hitt.h"

#include<memory>
#include <vector>
using namespace std;

using std::make_shared;
using std::shared_ptr;

class hitt_list : public hittable {
    public:
    vector<shared_ptr<hittable>> objects;

    hitt_list() {}
    hitt_list(shared_ptr<hittable> object) { add(object); }

    void clear() { objects.clear();}

    void add(shared_ptr<hittable> object) {
        objects.push_back(object);
    }

    bool hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec) const override {
        hit_record temp_rec;
        bool hit_anything = false;
        auto closest_so_far = ray_tmax;

        for(const auto& object : objects) {
            if (object->hit(r,ray_tmin, closest_so_far, temp_rec)) {
                hit_anything = true;
                closest_so_far = temp_rec.t;
                rec = temp_rec;
            }
        } return hit_anything;
    }
};
#endif

/*
    here, world --> consider as an object of objects
    shared_ptr --> prevents memory leaks—objects are deleted automatically when no longer needed.
    hitt_list --> efficient for checking group of objects(can be plane, spheres, etc...)
*/

/*
    allocating object as:
    shared_ptr<double> double_ptr = make_shared<double>(0.37);

    easy way using auto type specifier:
    auto double_ptr = make_shared<double>(0.37);
*/