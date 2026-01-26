#ifndef MATERIAL_H
#define MATERIAL_H

#include "headerList.h"
#include "hitt.h"

class material {
    public:
        virtual ~material() = default;

        virtual bool scatter( const ray& rIN, const hit_record& rec, color& attenuation, 
            ray& scattered) const {
                return false;
            }
};

#endif