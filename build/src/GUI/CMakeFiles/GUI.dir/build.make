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
include src/GUI/CMakeFiles/GUI.dir/depend.make

# Include the progress variables for this target.
include src/GUI/CMakeFiles/GUI.dir/progress.make

# Include the compile flags for this target's objects.
include src/GUI/CMakeFiles/GUI.dir/flags.make

src/GUI/CMakeFiles/GUI.dir/button_element.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/button_element.cpp.o: ../src/GUI/button_element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/GUI/CMakeFiles/GUI.dir/button_element.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/button_element.cpp.o -c /home/mingle/circuit-simulator/src/GUI/button_element.cpp

src/GUI/CMakeFiles/GUI.dir/button_element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/button_element.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/button_element.cpp > CMakeFiles/GUI.dir/button_element.cpp.i

src/GUI/CMakeFiles/GUI.dir/button_element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/button_element.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/button_element.cpp -o CMakeFiles/GUI.dir/button_element.cpp.s

src/GUI/CMakeFiles/GUI.dir/button_menu.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/button_menu.cpp.o: ../src/GUI/button_menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/GUI/CMakeFiles/GUI.dir/button_menu.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/button_menu.cpp.o -c /home/mingle/circuit-simulator/src/GUI/button_menu.cpp

src/GUI/CMakeFiles/GUI.dir/button_menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/button_menu.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/button_menu.cpp > CMakeFiles/GUI.dir/button_menu.cpp.i

src/GUI/CMakeFiles/GUI.dir/button_menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/button_menu.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/button_menu.cpp -o CMakeFiles/GUI.dir/button_menu.cpp.s

src/GUI/CMakeFiles/GUI.dir/component_element.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/component_element.cpp.o: ../src/GUI/component_element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/GUI/CMakeFiles/GUI.dir/component_element.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/component_element.cpp.o -c /home/mingle/circuit-simulator/src/GUI/component_element.cpp

src/GUI/CMakeFiles/GUI.dir/component_element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/component_element.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/component_element.cpp > CMakeFiles/GUI.dir/component_element.cpp.i

src/GUI/CMakeFiles/GUI.dir/component_element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/component_element.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/component_element.cpp -o CMakeFiles/GUI.dir/component_element.cpp.s

src/GUI/CMakeFiles/GUI.dir/component_menu.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/component_menu.cpp.o: ../src/GUI/component_menu.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/GUI/CMakeFiles/GUI.dir/component_menu.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/component_menu.cpp.o -c /home/mingle/circuit-simulator/src/GUI/component_menu.cpp

src/GUI/CMakeFiles/GUI.dir/component_menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/component_menu.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/component_menu.cpp > CMakeFiles/GUI.dir/component_menu.cpp.i

src/GUI/CMakeFiles/GUI.dir/component_menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/component_menu.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/component_menu.cpp -o CMakeFiles/GUI.dir/component_menu.cpp.s

src/GUI/CMakeFiles/GUI.dir/element.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/element.cpp.o: ../src/GUI/element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/GUI/CMakeFiles/GUI.dir/element.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/element.cpp.o -c /home/mingle/circuit-simulator/src/GUI/element.cpp

src/GUI/CMakeFiles/GUI.dir/element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/element.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/element.cpp > CMakeFiles/GUI.dir/element.cpp.i

src/GUI/CMakeFiles/GUI.dir/element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/element.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/element.cpp -o CMakeFiles/GUI.dir/element.cpp.s

src/GUI/CMakeFiles/GUI.dir/gui.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/gui.cpp.o: ../src/GUI/gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/GUI/CMakeFiles/GUI.dir/gui.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/gui.cpp.o -c /home/mingle/circuit-simulator/src/GUI/gui.cpp

src/GUI/CMakeFiles/GUI.dir/gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/gui.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/gui.cpp > CMakeFiles/GUI.dir/gui.cpp.i

src/GUI/CMakeFiles/GUI.dir/gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/gui.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/gui.cpp -o CMakeFiles/GUI.dir/gui.cpp.s

src/GUI/CMakeFiles/GUI.dir/image_element.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/image_element.cpp.o: ../src/GUI/image_element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/GUI/CMakeFiles/GUI.dir/image_element.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/image_element.cpp.o -c /home/mingle/circuit-simulator/src/GUI/image_element.cpp

src/GUI/CMakeFiles/GUI.dir/image_element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/image_element.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/image_element.cpp > CMakeFiles/GUI.dir/image_element.cpp.i

src/GUI/CMakeFiles/GUI.dir/image_element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/image_element.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/image_element.cpp -o CMakeFiles/GUI.dir/image_element.cpp.s

src/GUI/CMakeFiles/GUI.dir/text_element.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/text_element.cpp.o: ../src/GUI/text_element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object src/GUI/CMakeFiles/GUI.dir/text_element.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/text_element.cpp.o -c /home/mingle/circuit-simulator/src/GUI/text_element.cpp

src/GUI/CMakeFiles/GUI.dir/text_element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/text_element.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/text_element.cpp > CMakeFiles/GUI.dir/text_element.cpp.i

src/GUI/CMakeFiles/GUI.dir/text_element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/text_element.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/text_element.cpp -o CMakeFiles/GUI.dir/text_element.cpp.s

src/GUI/CMakeFiles/GUI.dir/text_field_element.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/text_field_element.cpp.o: ../src/GUI/text_field_element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object src/GUI/CMakeFiles/GUI.dir/text_field_element.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/text_field_element.cpp.o -c /home/mingle/circuit-simulator/src/GUI/text_field_element.cpp

src/GUI/CMakeFiles/GUI.dir/text_field_element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/text_field_element.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/text_field_element.cpp > CMakeFiles/GUI.dir/text_field_element.cpp.i

src/GUI/CMakeFiles/GUI.dir/text_field_element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/text_field_element.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/text_field_element.cpp -o CMakeFiles/GUI.dir/text_field_element.cpp.s

src/GUI/CMakeFiles/GUI.dir/wire_element.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/wire_element.cpp.o: ../src/GUI/wire_element.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object src/GUI/CMakeFiles/GUI.dir/wire_element.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/wire_element.cpp.o -c /home/mingle/circuit-simulator/src/GUI/wire_element.cpp

src/GUI/CMakeFiles/GUI.dir/wire_element.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/wire_element.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/wire_element.cpp > CMakeFiles/GUI.dir/wire_element.cpp.i

src/GUI/CMakeFiles/GUI.dir/wire_element.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/wire_element.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/wire_element.cpp -o CMakeFiles/GUI.dir/wire_element.cpp.s

src/GUI/CMakeFiles/GUI.dir/wire_node.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/wire_node.cpp.o: ../src/GUI/wire_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object src/GUI/CMakeFiles/GUI.dir/wire_node.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/wire_node.cpp.o -c /home/mingle/circuit-simulator/src/GUI/wire_node.cpp

src/GUI/CMakeFiles/GUI.dir/wire_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/wire_node.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/wire_node.cpp > CMakeFiles/GUI.dir/wire_node.cpp.i

src/GUI/CMakeFiles/GUI.dir/wire_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/wire_node.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/wire_node.cpp -o CMakeFiles/GUI.dir/wire_node.cpp.s

src/GUI/CMakeFiles/GUI.dir/workspace.cpp.o: src/GUI/CMakeFiles/GUI.dir/flags.make
src/GUI/CMakeFiles/GUI.dir/workspace.cpp.o: ../src/GUI/workspace.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object src/GUI/CMakeFiles/GUI.dir/workspace.cpp.o"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/GUI.dir/workspace.cpp.o -c /home/mingle/circuit-simulator/src/GUI/workspace.cpp

src/GUI/CMakeFiles/GUI.dir/workspace.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GUI.dir/workspace.cpp.i"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mingle/circuit-simulator/src/GUI/workspace.cpp > CMakeFiles/GUI.dir/workspace.cpp.i

src/GUI/CMakeFiles/GUI.dir/workspace.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GUI.dir/workspace.cpp.s"
	cd /home/mingle/circuit-simulator/build/src/GUI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mingle/circuit-simulator/src/GUI/workspace.cpp -o CMakeFiles/GUI.dir/workspace.cpp.s

# Object files for target GUI
GUI_OBJECTS = \
"CMakeFiles/GUI.dir/button_element.cpp.o" \
"CMakeFiles/GUI.dir/button_menu.cpp.o" \
"CMakeFiles/GUI.dir/component_element.cpp.o" \
"CMakeFiles/GUI.dir/component_menu.cpp.o" \
"CMakeFiles/GUI.dir/element.cpp.o" \
"CMakeFiles/GUI.dir/gui.cpp.o" \
"CMakeFiles/GUI.dir/image_element.cpp.o" \
"CMakeFiles/GUI.dir/text_element.cpp.o" \
"CMakeFiles/GUI.dir/text_field_element.cpp.o" \
"CMakeFiles/GUI.dir/wire_element.cpp.o" \
"CMakeFiles/GUI.dir/wire_node.cpp.o" \
"CMakeFiles/GUI.dir/workspace.cpp.o"

# External object files for target GUI
GUI_EXTERNAL_OBJECTS =

src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/button_element.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/button_menu.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/component_element.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/component_menu.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/element.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/gui.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/image_element.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/text_element.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/text_field_element.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/wire_element.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/wire_node.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/workspace.cpp.o
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/build.make
src/GUI/libGUI.a: src/GUI/CMakeFiles/GUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mingle/circuit-simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX static library libGUI.a"
	cd /home/mingle/circuit-simulator/build/src/GUI && $(CMAKE_COMMAND) -P CMakeFiles/GUI.dir/cmake_clean_target.cmake
	cd /home/mingle/circuit-simulator/build/src/GUI && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GUI.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/GUI/CMakeFiles/GUI.dir/build: src/GUI/libGUI.a

.PHONY : src/GUI/CMakeFiles/GUI.dir/build

src/GUI/CMakeFiles/GUI.dir/clean:
	cd /home/mingle/circuit-simulator/build/src/GUI && $(CMAKE_COMMAND) -P CMakeFiles/GUI.dir/cmake_clean.cmake
.PHONY : src/GUI/CMakeFiles/GUI.dir/clean

src/GUI/CMakeFiles/GUI.dir/depend:
	cd /home/mingle/circuit-simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mingle/circuit-simulator /home/mingle/circuit-simulator/src/GUI /home/mingle/circuit-simulator/build /home/mingle/circuit-simulator/build/src/GUI /home/mingle/circuit-simulator/build/src/GUI/CMakeFiles/GUI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/GUI/CMakeFiles/GUI.dir/depend
