# Circuit simulator

Welcome to our circuit simulator! The simulator is capable of simulating DC circuits with capacitors, resistors, inductors and constant DC power supplies. The user-friendly interface, built with SFML, allows for easy construction and manipulation of circuits. The flexible implementation of the GUI assures a future extensible platform for many types of analyzers. The repository is built with CMake and has automatic unit testing using Google's gtest library. All headers are equipped with Doxygen documentation to assure easy readability. Saving and loading circuits is done with Netlist which is a popular fileformat used by many circuit simulators like LTSpice.

Note:
- There are two (hard coded) solver examples
- We did not have time to integrate the solver into the GUI :(
- You can simulate circuits by creating new circuits inside a function (examples in main.cpp)


# Group
- Toikka Henrik
- Akuamoah Boateng Kwasi
- Linnanen Patrick
- Arpiainen Unna

# Advicer
- Dinh Trong Minh

# Used libraries
- Boost
- SFML
- gtest


# About the GUI
- Inspired by LTSpice simulator
- Can easily be extended to other types of circuit simulators (e.g. logic circuits to simulate digital computers)

# Building and compiling

## Linux (recommended) or WSL

- Tested on Ubuntu 22.04

### 0. Quick note about WSL
#### - You will be able to compile but running the program is up to your system and WSL setup. This is a bug with WSL.

### 1. Clone repository

```
git clone https://version.aalto.fi/gitlab/toikkah2/circuit-simulator
cd circuit-simulator/
```

### 2. Install required packages

```
sudo apt-get update && sudo apt-get install libboost-all-dev libsfml-dev build-essential cmake
```

### 3. Compile and Run
```
./build.sh
```

## Windows 10 (could work for Windows 11)

- Tested on Windows 10

### 1. Install vcpkg and boost (https://vcpkg.io/en/getting-started.html)

```
cd ~
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.bat
./vcpkg.exe install boost
```

### 2. Install CMake (https://cmake.org/download/)

Download "Windows x64 Installer" for example.

#### Remember to add it to PATH (selection box in installer)

### 3. Install MSYS2 and Mingw32 (https://www.msys2.org/)

a) Follow the installer and run MSYS2

b) Update packages

```
pacman -Syu
```

c) Re-open MSYS2 and update again. Install required packages

```
pacman -Su
pacman -S --needed base-devel mingw-w64-x86_64-toolchain
```

d) Add MinGW compiler to your PATH variable
- Navigate to "Environment Variables"
- Add "C:\msys64\mingw64\bin" to System PATH variable

e) Check installation

- Open cmd.exe and run:

```
g++ --version
```

### 4. Clone the repository

```
git clone https://version.aalto.fi/gitlab/toikkah2/circuit-simulator
cd circuit-simulator/
```

### 5. Compile and Run

```
./build.bat
```
