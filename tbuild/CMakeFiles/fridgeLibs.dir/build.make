# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kneel/repos/taleOfFridge

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kneel/repos/taleOfFridge/tbuild

# Include any dependencies generated for this target.
include CMakeFiles/fridgeLibs.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fridgeLibs.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fridgeLibs.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fridgeLibs.dir/flags.make

CMakeFiles/fridgeLibs.dir/src/player.cpp.o: CMakeFiles/fridgeLibs.dir/flags.make
CMakeFiles/fridgeLibs.dir/src/player.cpp.o: ../src/player.cpp
CMakeFiles/fridgeLibs.dir/src/player.cpp.o: CMakeFiles/fridgeLibs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kneel/repos/taleOfFridge/tbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fridgeLibs.dir/src/player.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fridgeLibs.dir/src/player.cpp.o -MF CMakeFiles/fridgeLibs.dir/src/player.cpp.o.d -o CMakeFiles/fridgeLibs.dir/src/player.cpp.o -c /home/kneel/repos/taleOfFridge/src/player.cpp

CMakeFiles/fridgeLibs.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fridgeLibs.dir/src/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kneel/repos/taleOfFridge/src/player.cpp > CMakeFiles/fridgeLibs.dir/src/player.cpp.i

CMakeFiles/fridgeLibs.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fridgeLibs.dir/src/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kneel/repos/taleOfFridge/src/player.cpp -o CMakeFiles/fridgeLibs.dir/src/player.cpp.s

CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.o: CMakeFiles/fridgeLibs.dir/flags.make
CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.o: ../src/fileLoader.cpp
CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.o: CMakeFiles/fridgeLibs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kneel/repos/taleOfFridge/tbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.o -MF CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.o.d -o CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.o -c /home/kneel/repos/taleOfFridge/src/fileLoader.cpp

CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kneel/repos/taleOfFridge/src/fileLoader.cpp > CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.i

CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kneel/repos/taleOfFridge/src/fileLoader.cpp -o CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.s

CMakeFiles/fridgeLibs.dir/src/item.cpp.o: CMakeFiles/fridgeLibs.dir/flags.make
CMakeFiles/fridgeLibs.dir/src/item.cpp.o: ../src/item.cpp
CMakeFiles/fridgeLibs.dir/src/item.cpp.o: CMakeFiles/fridgeLibs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kneel/repos/taleOfFridge/tbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/fridgeLibs.dir/src/item.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fridgeLibs.dir/src/item.cpp.o -MF CMakeFiles/fridgeLibs.dir/src/item.cpp.o.d -o CMakeFiles/fridgeLibs.dir/src/item.cpp.o -c /home/kneel/repos/taleOfFridge/src/item.cpp

CMakeFiles/fridgeLibs.dir/src/item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fridgeLibs.dir/src/item.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kneel/repos/taleOfFridge/src/item.cpp > CMakeFiles/fridgeLibs.dir/src/item.cpp.i

CMakeFiles/fridgeLibs.dir/src/item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fridgeLibs.dir/src/item.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kneel/repos/taleOfFridge/src/item.cpp -o CMakeFiles/fridgeLibs.dir/src/item.cpp.s

CMakeFiles/fridgeLibs.dir/src/controller.cpp.o: CMakeFiles/fridgeLibs.dir/flags.make
CMakeFiles/fridgeLibs.dir/src/controller.cpp.o: ../src/controller.cpp
CMakeFiles/fridgeLibs.dir/src/controller.cpp.o: CMakeFiles/fridgeLibs.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kneel/repos/taleOfFridge/tbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/fridgeLibs.dir/src/controller.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fridgeLibs.dir/src/controller.cpp.o -MF CMakeFiles/fridgeLibs.dir/src/controller.cpp.o.d -o CMakeFiles/fridgeLibs.dir/src/controller.cpp.o -c /home/kneel/repos/taleOfFridge/src/controller.cpp

CMakeFiles/fridgeLibs.dir/src/controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fridgeLibs.dir/src/controller.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kneel/repos/taleOfFridge/src/controller.cpp > CMakeFiles/fridgeLibs.dir/src/controller.cpp.i

CMakeFiles/fridgeLibs.dir/src/controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fridgeLibs.dir/src/controller.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kneel/repos/taleOfFridge/src/controller.cpp -o CMakeFiles/fridgeLibs.dir/src/controller.cpp.s

# Object files for target fridgeLibs
fridgeLibs_OBJECTS = \
"CMakeFiles/fridgeLibs.dir/src/player.cpp.o" \
"CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.o" \
"CMakeFiles/fridgeLibs.dir/src/item.cpp.o" \
"CMakeFiles/fridgeLibs.dir/src/controller.cpp.o"

# External object files for target fridgeLibs
fridgeLibs_EXTERNAL_OBJECTS =

libfridgeLibs.a: CMakeFiles/fridgeLibs.dir/src/player.cpp.o
libfridgeLibs.a: CMakeFiles/fridgeLibs.dir/src/fileLoader.cpp.o
libfridgeLibs.a: CMakeFiles/fridgeLibs.dir/src/item.cpp.o
libfridgeLibs.a: CMakeFiles/fridgeLibs.dir/src/controller.cpp.o
libfridgeLibs.a: CMakeFiles/fridgeLibs.dir/build.make
libfridgeLibs.a: CMakeFiles/fridgeLibs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kneel/repos/taleOfFridge/tbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libfridgeLibs.a"
	$(CMAKE_COMMAND) -P CMakeFiles/fridgeLibs.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fridgeLibs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fridgeLibs.dir/build: libfridgeLibs.a
.PHONY : CMakeFiles/fridgeLibs.dir/build

CMakeFiles/fridgeLibs.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fridgeLibs.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fridgeLibs.dir/clean

CMakeFiles/fridgeLibs.dir/depend:
	cd /home/kneel/repos/taleOfFridge/tbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kneel/repos/taleOfFridge /home/kneel/repos/taleOfFridge /home/kneel/repos/taleOfFridge/tbuild /home/kneel/repos/taleOfFridge/tbuild /home/kneel/repos/taleOfFridge/tbuild/CMakeFiles/fridgeLibs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fridgeLibs.dir/depend

