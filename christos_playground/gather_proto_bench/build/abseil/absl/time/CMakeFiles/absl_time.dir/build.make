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
CMAKE_SOURCE_DIR = /home/christos/protobuf/christos_playground/gather_proto_bench

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/christos/protobuf/christos_playground/gather_proto_bench/build

# Include any dependencies generated for this target.
include abseil/absl/time/CMakeFiles/absl_time.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include abseil/absl/time/CMakeFiles/absl_time.dir/compiler_depend.make

# Include the progress variables for this target.
include abseil/absl/time/CMakeFiles/absl_time.dir/progress.make

# Include the compile flags for this target's objects.
include abseil/absl/time/CMakeFiles/absl_time.dir/flags.make

abseil/absl/time/CMakeFiles/absl_time.dir/civil_time.cc.o: abseil/absl/time/CMakeFiles/absl_time.dir/flags.make
abseil/absl/time/CMakeFiles/absl_time.dir/civil_time.cc.o: /home/christos/protobuf/third_party/abseil-cpp/absl/time/civil_time.cc
abseil/absl/time/CMakeFiles/absl_time.dir/civil_time.cc.o: abseil/absl/time/CMakeFiles/absl_time.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christos/protobuf/christos_playground/gather_proto_bench/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object abseil/absl/time/CMakeFiles/absl_time.dir/civil_time.cc.o"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT abseil/absl/time/CMakeFiles/absl_time.dir/civil_time.cc.o -MF CMakeFiles/absl_time.dir/civil_time.cc.o.d -o CMakeFiles/absl_time.dir/civil_time.cc.o -c /home/christos/protobuf/third_party/abseil-cpp/absl/time/civil_time.cc

abseil/absl/time/CMakeFiles/absl_time.dir/civil_time.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/absl_time.dir/civil_time.cc.i"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christos/protobuf/third_party/abseil-cpp/absl/time/civil_time.cc > CMakeFiles/absl_time.dir/civil_time.cc.i

abseil/absl/time/CMakeFiles/absl_time.dir/civil_time.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/absl_time.dir/civil_time.cc.s"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christos/protobuf/third_party/abseil-cpp/absl/time/civil_time.cc -o CMakeFiles/absl_time.dir/civil_time.cc.s

abseil/absl/time/CMakeFiles/absl_time.dir/clock.cc.o: abseil/absl/time/CMakeFiles/absl_time.dir/flags.make
abseil/absl/time/CMakeFiles/absl_time.dir/clock.cc.o: /home/christos/protobuf/third_party/abseil-cpp/absl/time/clock.cc
abseil/absl/time/CMakeFiles/absl_time.dir/clock.cc.o: abseil/absl/time/CMakeFiles/absl_time.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christos/protobuf/christos_playground/gather_proto_bench/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object abseil/absl/time/CMakeFiles/absl_time.dir/clock.cc.o"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT abseil/absl/time/CMakeFiles/absl_time.dir/clock.cc.o -MF CMakeFiles/absl_time.dir/clock.cc.o.d -o CMakeFiles/absl_time.dir/clock.cc.o -c /home/christos/protobuf/third_party/abseil-cpp/absl/time/clock.cc

abseil/absl/time/CMakeFiles/absl_time.dir/clock.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/absl_time.dir/clock.cc.i"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christos/protobuf/third_party/abseil-cpp/absl/time/clock.cc > CMakeFiles/absl_time.dir/clock.cc.i

abseil/absl/time/CMakeFiles/absl_time.dir/clock.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/absl_time.dir/clock.cc.s"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christos/protobuf/third_party/abseil-cpp/absl/time/clock.cc -o CMakeFiles/absl_time.dir/clock.cc.s

abseil/absl/time/CMakeFiles/absl_time.dir/duration.cc.o: abseil/absl/time/CMakeFiles/absl_time.dir/flags.make
abseil/absl/time/CMakeFiles/absl_time.dir/duration.cc.o: /home/christos/protobuf/third_party/abseil-cpp/absl/time/duration.cc
abseil/absl/time/CMakeFiles/absl_time.dir/duration.cc.o: abseil/absl/time/CMakeFiles/absl_time.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christos/protobuf/christos_playground/gather_proto_bench/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object abseil/absl/time/CMakeFiles/absl_time.dir/duration.cc.o"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT abseil/absl/time/CMakeFiles/absl_time.dir/duration.cc.o -MF CMakeFiles/absl_time.dir/duration.cc.o.d -o CMakeFiles/absl_time.dir/duration.cc.o -c /home/christos/protobuf/third_party/abseil-cpp/absl/time/duration.cc

abseil/absl/time/CMakeFiles/absl_time.dir/duration.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/absl_time.dir/duration.cc.i"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christos/protobuf/third_party/abseil-cpp/absl/time/duration.cc > CMakeFiles/absl_time.dir/duration.cc.i

abseil/absl/time/CMakeFiles/absl_time.dir/duration.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/absl_time.dir/duration.cc.s"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christos/protobuf/third_party/abseil-cpp/absl/time/duration.cc -o CMakeFiles/absl_time.dir/duration.cc.s

abseil/absl/time/CMakeFiles/absl_time.dir/format.cc.o: abseil/absl/time/CMakeFiles/absl_time.dir/flags.make
abseil/absl/time/CMakeFiles/absl_time.dir/format.cc.o: /home/christos/protobuf/third_party/abseil-cpp/absl/time/format.cc
abseil/absl/time/CMakeFiles/absl_time.dir/format.cc.o: abseil/absl/time/CMakeFiles/absl_time.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christos/protobuf/christos_playground/gather_proto_bench/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object abseil/absl/time/CMakeFiles/absl_time.dir/format.cc.o"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT abseil/absl/time/CMakeFiles/absl_time.dir/format.cc.o -MF CMakeFiles/absl_time.dir/format.cc.o.d -o CMakeFiles/absl_time.dir/format.cc.o -c /home/christos/protobuf/third_party/abseil-cpp/absl/time/format.cc

abseil/absl/time/CMakeFiles/absl_time.dir/format.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/absl_time.dir/format.cc.i"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christos/protobuf/third_party/abseil-cpp/absl/time/format.cc > CMakeFiles/absl_time.dir/format.cc.i

abseil/absl/time/CMakeFiles/absl_time.dir/format.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/absl_time.dir/format.cc.s"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christos/protobuf/third_party/abseil-cpp/absl/time/format.cc -o CMakeFiles/absl_time.dir/format.cc.s

abseil/absl/time/CMakeFiles/absl_time.dir/time.cc.o: abseil/absl/time/CMakeFiles/absl_time.dir/flags.make
abseil/absl/time/CMakeFiles/absl_time.dir/time.cc.o: /home/christos/protobuf/third_party/abseil-cpp/absl/time/time.cc
abseil/absl/time/CMakeFiles/absl_time.dir/time.cc.o: abseil/absl/time/CMakeFiles/absl_time.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christos/protobuf/christos_playground/gather_proto_bench/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object abseil/absl/time/CMakeFiles/absl_time.dir/time.cc.o"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT abseil/absl/time/CMakeFiles/absl_time.dir/time.cc.o -MF CMakeFiles/absl_time.dir/time.cc.o.d -o CMakeFiles/absl_time.dir/time.cc.o -c /home/christos/protobuf/third_party/abseil-cpp/absl/time/time.cc

abseil/absl/time/CMakeFiles/absl_time.dir/time.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/absl_time.dir/time.cc.i"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christos/protobuf/third_party/abseil-cpp/absl/time/time.cc > CMakeFiles/absl_time.dir/time.cc.i

abseil/absl/time/CMakeFiles/absl_time.dir/time.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/absl_time.dir/time.cc.s"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christos/protobuf/third_party/abseil-cpp/absl/time/time.cc -o CMakeFiles/absl_time.dir/time.cc.s

# Object files for target absl_time
absl_time_OBJECTS = \
"CMakeFiles/absl_time.dir/civil_time.cc.o" \
"CMakeFiles/absl_time.dir/clock.cc.o" \
"CMakeFiles/absl_time.dir/duration.cc.o" \
"CMakeFiles/absl_time.dir/format.cc.o" \
"CMakeFiles/absl_time.dir/time.cc.o"

# External object files for target absl_time
absl_time_EXTERNAL_OBJECTS =

abseil/absl/time/libabsl_time.a: abseil/absl/time/CMakeFiles/absl_time.dir/civil_time.cc.o
abseil/absl/time/libabsl_time.a: abseil/absl/time/CMakeFiles/absl_time.dir/clock.cc.o
abseil/absl/time/libabsl_time.a: abseil/absl/time/CMakeFiles/absl_time.dir/duration.cc.o
abseil/absl/time/libabsl_time.a: abseil/absl/time/CMakeFiles/absl_time.dir/format.cc.o
abseil/absl/time/libabsl_time.a: abseil/absl/time/CMakeFiles/absl_time.dir/time.cc.o
abseil/absl/time/libabsl_time.a: abseil/absl/time/CMakeFiles/absl_time.dir/build.make
abseil/absl/time/libabsl_time.a: abseil/absl/time/CMakeFiles/absl_time.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christos/protobuf/christos_playground/gather_proto_bench/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libabsl_time.a"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && $(CMAKE_COMMAND) -P CMakeFiles/absl_time.dir/cmake_clean_target.cmake
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/absl_time.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
abseil/absl/time/CMakeFiles/absl_time.dir/build: abseil/absl/time/libabsl_time.a
.PHONY : abseil/absl/time/CMakeFiles/absl_time.dir/build

abseil/absl/time/CMakeFiles/absl_time.dir/clean:
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time && $(CMAKE_COMMAND) -P CMakeFiles/absl_time.dir/cmake_clean.cmake
.PHONY : abseil/absl/time/CMakeFiles/absl_time.dir/clean

abseil/absl/time/CMakeFiles/absl_time.dir/depend:
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christos/protobuf/christos_playground/gather_proto_bench /home/christos/protobuf/third_party/abseil-cpp/absl/time /home/christos/protobuf/christos_playground/gather_proto_bench/build /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/time/CMakeFiles/absl_time.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : abseil/absl/time/CMakeFiles/absl_time.dir/depend

