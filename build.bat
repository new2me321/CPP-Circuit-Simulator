@REM Build file for windows
@REM You may need to modify vcpkg path below, if you have an untraditional installation
@REM This assumes you have installed boost (with vcpkg) and mingw build tools (e.g. with msys64)

mkdir build
cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE="~/vcpkg/scripts/buildsystems/vcpkg.cmake" -G "MinGW Makefiles" -DBUILD_SHARED_LIBS=OFF
cmake --build build -j8

"./build/tests/UnitTests.exe"
"./build/src/circuit-simulator.exe"
