#pragma once

#include <complex>
#include <cstddef>

// Return the one-based escape iteration, or zero if escape was not detected.
std::size_t mandelbrot(std::complex<double> c);
std::size_t julia(std::complex<double> z);
