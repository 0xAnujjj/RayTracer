#ifndef CAMERA_H
#define CAMERA_H
#include "headerlist.h"
#include "hitt.h"
using namespace std;

class camera {
    public: 
    double aspect_ratio = 1.0; // ratio of width over height
    int image_width = 100; // rendered img. width in pixel count
    int samples_per_pixel = 10; // count of random samples for each pixel
    
void render(const hittable& world){
        initialize();

    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        clog << "\rScanlines remaining: " << (image_height - j) << ' ' << flush;
        for (int i = 0; i < image_width; i++) {
           color pixel_color(0,0,0);
           for (int sample = 0; sample < samples_per_pixel; sample++) {
                ray r = get_ray(i,j);
                pixel_color += ray_color(r, world);

           }
            write_color(cout, pixel_samples_scale * pixel_color);
        }
    }

        clog << "\rDone.        \n";
    }

    private:
    int image_height; // rendered img. height
    double pixel_samples_scale; // color scale factor for pixel samples sum
    point3 camera_center; //cam center
    point3 pixel00_loc; //0,0 point's location
    vec3 pixel_delta_u; //offset to pixel to right
    vec3 pixel_delta_v; //offset to pixel below

void initialize() {
    // Compute image height from aspect ratio, and clamp to at least 1.
    image_height = int(image_width / aspect_ratio);
    if (image_height < 1) {
        image_height = 1;
    }

    pixel_samples_scale = 1.0 / samples_per_pixel;

    // Viewport dimensions.
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * (double(image_width) / image_height);

    // Camera position.
    camera_center = point3(0, 0, 0);

    // Vectors across the horizontal and down the vertical viewport edges.
    vec3 viewport_u = vec3(viewport_width, 0, 0);
    vec3 viewport_v = vec3(0, -viewport_height, 0);

    // Pixel-to-pixel delta vectors (store in members, not locals).
    pixel_delta_u = viewport_u / image_width;
    pixel_delta_v = viewport_v / image_height;

    // Location of the upper-left pixel (store in member).
    vec3 viewport_upper_left = camera_center - vec3(0, 0, focal_length) - viewport_u/2 - viewport_v/2;
    pixel00_loc = viewport_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

    }

    ray get_ray(int i, int j) const {
        // a cam ray from the origin and is directed at random sampled point around pixel loc. i,j

        auto offset = sample_square();
        auto pixel_sample = pixel00_loc + ((i + offset.x()) * pixel_delta_u)
                                        + ((j + offset.y()) * pixel_delta_v);
        
        auto ray_origin = camera_center;
        auto ray_direction = pixel_sample - ray_origin;

        return ray(ray_origin, ray_direction);
    }

    vec3 sample_square() const {
        //return vector to a rand. point inthe [-0.5, -0.5] - [0.5, 0.5] unit square
        return vec3(random_double() - 0.5, random_double() - 0.5, 0);
    }

color ray_color(const ray& r, const hittable& world) {
        hit_record rec;
       
        if (world.hit(r, interval(0, infinity), rec)) {
        return 0.5 * (rec.normal + color(1,1,1));
        }
       
        vec3 unit_direction  = unit_vector(r.direction());
        auto a = 0.5*(unit_direction.y() + 1.0);
        return (1.0-a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
    }   
};

#endif