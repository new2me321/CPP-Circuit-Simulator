# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/mingle/.local/lib/python2.7/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/mingle/.local/lib/python2.7/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mingle/circuit-simulator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mingle/circuit-simulator/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/UnitTests.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/UnitTests.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/UnitTests.dir/flags.make

tests/CMakeFiles/UnitTests.dir/netlist_tests.cpp.o: tests/CMakeFiles/UnitTests.dir/flags.make
tests/CMakeFiles/UnitTests.dir/netlist_tests.cpp.o: ../tests/netlist_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/UnitTests.dir/netlist_tests.cpp.o"
	cd /home/mingle/circuit-simulator/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UnitTests.dir/netlist_tests.cpp.o -c /home/mingle/circuit-simulator/tests/netlist_tests.cpp

tests/CMakeFiles/UnitTests.dir/netlist_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTests.dir/netlist_tests.cpp.i"
	cd /home/mingle/circuit-simulator/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/tests/netlist_tests.cpp > CMakeFiles/UnitTests.dir/netlist_tests.cpp.i

tests/CMakeFiles/UnitTests.dir/netlist_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTests.dir/netlist_tests.cpp.s"
	cd /home/mingle/circuit-simulator/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/tests/netlist_tests.cpp -o CMakeFiles/UnitTests.dir/netlist_tests.cpp.s

tests/CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.o: tests/CMakeFiles/UnitTests.dir/flags.make
tests/CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.o: ../tests/circuit_load_tests.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.o"
	cd /home/mingle/circuit-simulator/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.o -c /home/mingle/circuit-simulator/tests/circuit_load_tests.cpp

tests/CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.i"
	cd /home/mingle/circuit-simulator/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/tests/circuit_load_tests.cpp > CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.i

tests/CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.s"
	cd /home/mingle/circuit-simulator/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/tests/circuit_load_tests.cpp -o CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.s

tests/CMakeFiles/UnitTests.dir/circuit_test.cpp.o: tests/CMakeFiles/UnitTests.dir/flags.make
tests/CMakeFiles/UnitTests.dir/circuit_test.cpp.o: ../tests/circuit_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/UnitTests.dir/circuit_test.cpp.o"
	cd /home/mingle/circuit-simulator/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UnitTests.dir/circuit_test.cpp.o -c /home/mingle/circuit-simulator/tests/circuit_test.cpp

tests/CMakeFiles/UnitTests.dir/circuit_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UnitTests.dir/circuit_test.cpp.i"
	cd /home/mingle/circuit-simulator/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/tests/circuit_test.cpp > CMakeFiles/UnitTests.dir/circuit_test.cpp.i

tests/CMakeFiles/UnitTests.dir/circuit_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UnitTests.dir/circuit_test.cpp.s"
	cd /home/mingle/circuit-simulator/build/tests && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/tests/circuit_test.cpp -o CMakeFiles/UnitTests.dir/circuit_test.cpp.s

# Object files for target UnitTests
UnitTests_OBJECTS = \
"CMakeFiles/UnitTests.dir/netlist_tests.cpp.o" \
"CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.o" \
"CMakeFiles/UnitTests.dir/circuit_test.cpp.o"

# External object files for target UnitTests
UnitTests_EXTERNAL_OBJECTS =

UnitTests: tests/CMakeFiles/UnitTests.dir/netlist_tests.cpp.o
UnitTests: tests/CMakeFiles/UnitTests.dir/circuit_load_tests.cpp.o
UnitTests: tests/CMakeFiles/UnitTests.dir/circuit_test.cpp.o
UnitTests: tests/CMakeFiles/UnitTests.dir/build.make
UnitTests: lib/libgtest_main.a
UnitTests: src/Circuit/libCircuit.a
UnitTests: src/Solver/libSolver.a
UnitTests: src/GUI/libGUI.a
UnitTests: lib/libgtest.a
UnitTests: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
UnitTests: /usr/lib/x86_64-linux-gnu/libboost_system.so
UnitTests: tests/CMakeFiles/UnitTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../UnitTests"
	cd /home/mingle/circuit-simulator/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UnitTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/UnitTests.dir/build: UnitTests

.PHONY : tests/CMakeFiles/UnitTests.dir/build

tests/CMakeFiles/UnitTests.dir/clean:
	cd /home/mingle/circuit-simulator/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/UnitTests.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/UnitTests.dir/clean

tests/CMakeFiles/UnitTests.dir/depend:
	cd /home/mingle/circuit-simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mingle/circuit-simulator /home/mingle/circuit-simulator/tests /home/mingle/circuit-simulator/build /home/mingle/circuit-simulator/build/tests /home/mingle/circuit-simulator/build/tests/CMakeFiles/UnitTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/UnitTests.dir/depend
