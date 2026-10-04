# HPC — C++ computational exercises

A collection of numerical and container exercises, including a single-threaded
Mandelbrot and Julia fractal renderer. The renderer provides a baseline for future
parallel-performance experiments; it does not currently use CPU threading or GPUs.

## Build

Requires CMake 3.10 or newer and a C++11 compiler.

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

## Render fractals

```sh
./build/single-thread mandelbrot
./build/single-thread julia
```

With no argument, the renderer selects Mandelbrot. Each command saves an RGB PPM
image in the current directory (`image_serial_mandelbrot.ppm` or
`image_serial_julia.ppm`). Open it with an image viewer that supports PPM.

Edit `fractals/config.hpp` to change the default 800×800 resolution or 1,000-iteration
limit, then rebuild. Pixels sample the complex plane from approximately -2 to 2 on
each axis. Escape counts determine color; no detected escape is shown as black.

## Project layout

- `fractals/kernel.cpp` and `kernel.hpp`: Mandelbrot and Julia escape calculations.
- `fractals/single-thread.cpp`: pixel traversal, coloring, and PPM output.
- `fractals/config.hpp`: image dimensions and iteration limit.
- `containers/vectors/`: averages using loops and accumulation.
- `containers/lists/`: median example.
- `Algos/taylor.cpp`: Taylor-series approximation of ln(1 + x).
- `CMakeLists.txt`: executable targets and the fractal kernel library.

Run the other examples with `./build/average`, `./build/average2`,
`./build/median`, and `./build/taylor`.

Build directories and generated fractal images are excluded from Git.
