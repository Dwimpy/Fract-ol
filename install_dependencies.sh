#!/bin/bash

MLX42_LIBRARY="MLX42/build/libmlx42.a"
GLFW_LIBRARY="glfw/src/libglfw3.a"
echo "Getting submodules..."
git submodule update --init --recursive
if [ -z `which brew` ]; then
	echo "Installing Homebrew..."
	ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"
	else
	echo "Homebrew found"
fi

echo "Updating Homebrew, please wait..."
brew update

if [ -z `which cmake` ]; then
	echo "CMake not found, installing..."
	install cmake
	else
	echo "CMake installed. Creating GLFW..."
fi

if [ ! -d GLFW_LIBRARY ]; then
	echo "GLFW not found, installing..."
	cd ./glfw && cmake -B build && cmake --build build -j4 && cd ..
	else
	echo "GLFW installed. Creating MLX42..."
fi

if [ ! -d MLX42_LIBRARY ]; then
	echo "MLX42 not found, installing..."
	cd ./MLX42 && cmake -B build && cmake --build build -j4 && cd ..
	else
	echo "MLX42 found. Making fractol..."
fi

