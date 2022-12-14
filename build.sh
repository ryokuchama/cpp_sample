#!/usr/sh
rm -rf build/
cmake -B build -G Ninja
ninja -C build