#include "kernel.hpp"
#include "config.hpp"

//kernel to compute the mandelbrot set
std::size_t mandelbrot (std::complex<double> c){
    std::complex<double> z(0, 0);
    for (std::size_t i = 0; i < max_iterations; i++){
        z = z * z + c;
        if (std::norm(z) > 4.0){
            return i + 1;
        }
    }
    return 0;
}

//kernel to compute the julia set
std::size_t julia (std::complex<double> z){
    std::complex<double> c(-0.4, 0.6);
    for (std::size_t i = 0; i < max_iterations; i++){
        z = z * z + c;
        if (std::norm(z) > 4.0){
            return i + 1;
        }
    }
    return 0;
}

