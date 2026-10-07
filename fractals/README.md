# Fractal renderer

A single-threaded C++ renderer for the Mandelbrot and Julia sets.

## Rendering process

1. Select the Mandelbrot or Julia kernel from the command-line argument.
2. Open the output PPM image and write its header.
3. Visit every pixel, one row at a time:
   - Map the pixel's center to a complex coordinate.
   - Pass that coordinate to the selected kernel.
   - Iterate until escape or the iteration limit.
   - Convert the returned escape count into an RGB color.
   - Write the color to the image.
4. Close the image file.

```text
Pixel (x, y) → Complex coordinate → Kernel → Escape count → RGB → Image file
```

One thread processes all pixels sequentially.

## Kernels

Both kernels repeatedly calculate `z = z * z + c`.

| Kernel | Pixel supplies | Fixed value |
| --- | --- | --- |
| Mandelbrot | Parameter `c` | Initial `z = 0` |
| Julia | Initial `z` | Parameter `c = -0.4 + 0.6i` |

Escape is detected when `std::norm(z) > 4.0`, meaning the magnitude of `z`
exceeds 2. The kernel returns the one-based escape iteration, or `0` when
no escape is detected within the limit. A return value of `0` is rendered
as black; it does not prove membership in the mathematical set.

## Build and run

From the `hpc` directory:

```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --target single-thread
./build/single-thread mandelbrot
./build/single-thread julia
```

With no argument, the renderer selects Mandelbrot. Images are saved in the
current directory as `image_serial_mandelbrot.ppm` or `image_serial_julia.ppm`.
Open them with an image viewer that supports PPM.

## Files and configuration

- `single-thread.cpp`: kernel selection, pixel traversal, coloring, and image output.
- `kernel.cpp`: Mandelbrot and Julia escape calculations.
- `kernel.hpp`: kernel declarations and return-value contract.
- `config.hpp`: image dimensions and iteration limit.

Defaults are **800 × 800 pixels** and **1,000 iterations per pixel**. Edit
`config.hpp` and rebuild to change them. Pixel centers sample approximately
`[-2, 2]` on both axes, with positive imaginary values at the top of the image.
