Fract'ol - 42 Project
========

Fract'ol is a small fractal exploration program that offers the Julia set and the Mandelbrot set. It uses the MiniLibX library to display the images in a window and allows for zooming in and out using the mouse wheel. The program can create different Julia sets by passing different parameters to the program.

Installation
------------

>Currently there is a script to install all the dependencies such as glfw and MLX42 library. \
The script will only work for mac, if you want to compile on linux you will have to manually \
install cmake and build MLX42 and GLFW.

### For MacOS a simple make should fetch all dependencies and compile the project.
```bash
  make
```

### For Linux

#### In the fractol makefile remove the deps dependency from the all rule
```bash
  all:  deps  libft $(NAME) < ----- > all: libft $(NAME)
```
#### Install cmake
```bash
  sudo apt-get install -y cmake
```
#### Install the dependencies for MLX42
```bash
  sudo apt-get install build-essential libx11-dev libglfw3-dev libglfw3 xorg-dev
```
#### Compile the MLX42 library from inside the fractol directory
```bash
  cd ./MLX42/ && cmake -B build && cmake --build build -j4 && cd ..
```
#### Change LDLFLAGS and CFLAGS and compile Fract'ol
```bash
  LDLFLAGS = -lft -L ./libft/ -lmlx42 -L ./MLX42/build -ldl -lglfw -pthread
  CFLAGS = -Ofast -march=native -flto 
  make
```

Usage
-----

To use the program, run the following command:

```bash
./fractol [fractal_type] [rendering_options]
```
If no parameter is provided, or if the parameter is invalid, the program will display a list of available parameters and exit properly.

The program supports the following fractal types:

*   Mandelbrot set
*   Julia set

Rendering Approach
=================

>For the rendering approach, I have used the distance estimation method to plot the Julia and Mandelbrot sets. This method allows for more efficient and accurate rendering of complex shapes compared to the traditional method of iterating over each pixel in the image.

#### Distance Estimation Method

>The distance estimation method works by estimating the distance of a point in the complex plane to the nearest point on the boundary of the fractal. This is done by iteratively applying the fractal formula until the distance is below a certain threshold, indicating that the point is close enough to the boundary.

#### Benefits of Distance Estimation Method

>This method offers several benefits over traditional methods, such as faster rendering times and smoother edges. Additionally, it allows for zooming in on the fractals without loss of detail, as the formula can be iteratively applied at higher levels of magnification.

Optimizations
=============

#### Analytic formula for cardiod bulb for the Mandelbrot set

>I have optimized the Mandelbrot set by implementing the analytic formula for the cardiod bulb. This formula allows us
to skip the computation of points  that are inside the cardiod bulb, significantly reducing the number of iterations 
needed to generate the set.

#### Period checking every 20 iterations for the Mandelbrot set

>I have also optimized the computation time the Mandelbrot set by performing period checking every 20 iterations. This technique allows us to determine whether a point will diverge to infinity without having to perform the maximum number of iterations for every point, further reducing computation time.

Controls
--------

The following controls are available in the program:

*   Zoom in/out: Use the mouse wheel
*   Moving the view: Press the arrow keys
*   Quit: Press ESC or click the cross on the window's frame

Bonus Features
--------------

The program also supports the following bonus features:

*   One additional fractal type
*   Zoom follows the actual mouse position
*   Color range shift

Conclusion
----------

Fract'ol is a small and simple program that offers a fun and interactive way to explore fractals. With its easy-to-use controls and customizable options, it is sure to provide hours of entertainment for users of all skill levels.

## Warning Against Blindly Copying Code
> Copying code without understanding it is not a good practice. While it may help you pass a project or assignment, 
it won't help you learn and grow as a programmer. It's important to take the time to understand the code you're working 
with, as it will help you catch errors, make improvements, and build better solutions in the future. Additionally, copying 
code without attribution or permission can be a violation of academic integrity and may result in penalties. \
So, take the time to learn and understand the code you're working with, and use it as a starting point to build your own solutions.
