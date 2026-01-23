#include "headerlist.h"
#include "camera.h"
#include "hitt.h"
#include "hitt_list.h"
#include "sphere.h"


using namespace std;
        int main() {
    // Image

    auto aspect_ratio = 16.0 / 9.0;
    int image_width = 400;

    //world

    hitt_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;
    cam.aspect_ratio = 16.9/9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 100;
    cam.render(world);

}


/* right handed coordinates:the camera's y-axis go up, x-axis go to the right,
 negative z-axis point in viewing direction(direction towards viewport) */