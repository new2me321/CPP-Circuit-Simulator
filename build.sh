#!/bin/sh

rm -f ./build/UnitTests
rm -f ./build/circuit-simulator

# build file for Linux
mkdir -p build
cmake -B build -S . -DRESOURCES_PATH="resources/" -DSAVEFILES_PATH="savefiles/"
cmake --build build -j8

# prevent resources from an error, requires read access
chmod u+x resources/Ubuntu-R.ttf
chmod u+x resources/components.png

./build/UnitTests
./build/circuit-simulator
# valgrind ./circuit-simulator
