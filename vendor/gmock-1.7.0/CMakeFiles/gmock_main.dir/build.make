# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/julesy/workspace/moo-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/julesy/workspace/moo-cpp

# Include any dependencies generated for this target.
include vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/depend.make

# Include the progress variables for this target.
include vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/progress.make

# Include the compile flags for this target's objects.
include vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/flags.make

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/flags.make
vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o: vendor/gmock-1.7.0/gtest/src/gtest-all.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/julesy/workspace/moo-cpp/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o"
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && /usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o -c /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0/gtest/src/gtest-all.cc

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.i"
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0/gtest/src/gtest-all.cc > CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.i

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.s"
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0/gtest/src/gtest-all.cc -o CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.s

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.requires:
.PHONY : vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.requires

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.provides: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.requires
	$(MAKE) -f vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/build.make vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.provides.build
.PHONY : vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.provides

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.provides.build: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/flags.make
vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o: vendor/gmock-1.7.0/src/gmock-all.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/julesy/workspace/moo-cpp/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o"
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && /usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock-all.cc.o -c /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0/src/gmock-all.cc

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock-all.cc.i"
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0/src/gmock-all.cc > CMakeFiles/gmock_main.dir/src/gmock-all.cc.i

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock-all.cc.s"
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0/src/gmock-all.cc -o CMakeFiles/gmock_main.dir/src/gmock-all.cc.s

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires:
.PHONY : vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires
	$(MAKE) -f vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/build.make vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides.build
.PHONY : vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.provides.build: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/flags.make
vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o: vendor/gmock-1.7.0/src/gmock_main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/julesy/workspace/moo-cpp/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && /usr/bin/g++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.o -c /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0/src/gmock_main.cc

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gmock_main.dir/src/gmock_main.cc.i"
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0/src/gmock_main.cc > CMakeFiles/gmock_main.dir/src/gmock_main.cc.i

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gmock_main.dir/src/gmock_main.cc.s"
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && /usr/bin/g++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0/src/gmock_main.cc -o CMakeFiles/gmock_main.dir/src/gmock_main.cc.s

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires:
.PHONY : vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires
	$(MAKE) -f vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/build.make vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides.build
.PHONY : vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.provides.build: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o

# Object files for target gmock_main
gmock_main_OBJECTS = \
"CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o" \
"CMakeFiles/gmock_main.dir/src/gmock-all.cc.o" \
"CMakeFiles/gmock_main.dir/src/gmock_main.cc.o"

# External object files for target gmock_main
gmock_main_EXTERNAL_OBJECTS =

vendor/gmock-1.7.0/libgmock_main.a: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o
vendor/gmock-1.7.0/libgmock_main.a: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o
vendor/gmock-1.7.0/libgmock_main.a: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o
vendor/gmock-1.7.0/libgmock_main.a: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/build.make
vendor/gmock-1.7.0/libgmock_main.a: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libgmock_main.a"
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean_target.cmake
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gmock_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/build: vendor/gmock-1.7.0/libgmock_main.a
.PHONY : vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/build

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/requires: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/gtest/src/gtest-all.cc.o.requires
vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/requires: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock-all.cc.o.requires
vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/requires: vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/src/gmock_main.cc.o.requires
.PHONY : vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/requires

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/clean:
	cd /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 && $(CMAKE_COMMAND) -P CMakeFiles/gmock_main.dir/cmake_clean.cmake
.PHONY : vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/clean

vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/depend:
	cd /home/julesy/workspace/moo-cpp && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/julesy/workspace/moo-cpp /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 /home/julesy/workspace/moo-cpp /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0 /home/julesy/workspace/moo-cpp/vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vendor/gmock-1.7.0/CMakeFiles/gmock_main.dir/depend
