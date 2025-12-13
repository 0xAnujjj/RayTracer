#include <iostream>
#include <fstream>

#ifdef _WIN32
#include <windows.h>
#endif

int main() {

#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::ofstream output_file{"image.ppm", std::ios::out | std::ios::binary};
    if (!output_file) {
        std::cerr << "Error: Could not open file for writing.\n";
        return EXIT_FAILURE;
    }

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    output_file << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; j++) {
        for (int i = 0; i < image_width; i++) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.0;

            int ir = int(255.999 * r);
            int ig = int(255.999 * g);
            int ib = int(255.999 * b);

            output_file << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
    
    output_file.flush();
    output_file.close();

    return EXIT_SUCCESS;
}