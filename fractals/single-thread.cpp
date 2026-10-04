#include "config.hpp"
#include "kernel.hpp"

#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>

// Zero denotes a point that did not escape within the iteration limit.
std::array<unsigned char, 3> get_rgb(std::size_t iterations) {
    if (iterations == 0) return {0, 0, 0};
    const double t = std::sqrt(static_cast<double>(iterations) / max_iterations);
    return {
        static_cast<unsigned char>(255 * 9 * (1 - t) * t * t * t),
        static_cast<unsigned char>(255 * 15 * (1 - t) * (1 - t) * t * t),
        static_cast<unsigned char>(255 * 8.5 * (1 - t) * (1 - t) * (1 - t) * t)
    };
}


int main(int argc, char* argv[]) {
    const std::string type = argc > 1 ? argv[1] : "mandelbrot";
    if (argc > 2 || (type != "mandelbrot" && type != "julia")) {
        std::cerr << "Usage: " << argv[0] << " [mandelbrot|julia]\n";
        return 1;
    }
    const auto compute_pixel = type == "mandelbrot" ? mandelbrot : julia;
    const std::string filename = "image_serial_" + type + ".ppm";
    std::ofstream image(filename, std::ios::binary);
    if (!image) {
        std::cerr << "Cannot open " << filename << '\n';
        return 1;
    }
    // P6 is binary RGB Portable Pixmap. Write rows from top to bottom.
    image << "P6\n" << size_x << ' ' << size_y << "\n255\n";
    for (std::size_t y = 0; y < size_y; ++y) {
        for (std::size_t x = 0; x < size_x; ++x) {
            const std::complex<double> point(
                4.0 * (x + 0.5) / size_x - 2.0,
                2.0 - 4.0 * (y + 0.5) / size_y);
            const auto color = get_rgb(compute_pixel(point));
            image.write(reinterpret_cast<const char*>(color.data()), color.size());
        }
    }
    image.close();
    if (!image) {
        std::cerr << "Failed to write " << filename << '\n';
        return 1;
    }
    std::cout << "Saved " << filename << " (" << size_x << 'x' << size_y << ")\n";
}
