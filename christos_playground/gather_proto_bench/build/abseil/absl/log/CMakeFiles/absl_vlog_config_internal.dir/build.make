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
include abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/compiler_depend.make

# Include the progress variables for this target.
include abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/progress.make

# Include the compile flags for this target's objects.
include abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/flags.make

abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.o: abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/flags.make
abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.o: /home/christos/protobuf/third_party/abseil-cpp/absl/log/internal/vlog_config.cc
abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.o: abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/christos/protobuf/christos_playground/gather_proto_bench/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.o"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.o -MF CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.o.d -o CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.o -c /home/christos/protobuf/third_party/abseil-cpp/absl/log/internal/vlog_config.cc

abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.i"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/christos/protobuf/third_party/abseil-cpp/absl/log/internal/vlog_config.cc > CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.i

abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.s"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/log && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/christos/protobuf/third_party/abseil-cpp/absl/log/internal/vlog_config.cc -o CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.s

# Object files for target absl_vlog_config_internal
absl_vlog_config_internal_OBJECTS = \
"CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.o"

# External object files for target absl_vlog_config_internal
absl_vlog_config_internal_EXTERNAL_OBJECTS =

abseil/absl/log/libabsl_vlog_config_internal.a: abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/internal/vlog_config.cc.o
abseil/absl/log/libabsl_vlog_config_internal.a: abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/build.make
abseil/absl/log/libabsl_vlog_config_internal.a: abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/christos/protobuf/christos_playground/gather_proto_bench/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libabsl_vlog_config_internal.a"
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/log && $(CMAKE_COMMAND) -P CMakeFiles/absl_vlog_config_internal.dir/cmake_clean_target.cmake
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/log && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/absl_vlog_config_internal.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/build: abseil/absl/log/libabsl_vlog_config_internal.a
.PHONY : abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/build

abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/clean:
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/log && $(CMAKE_COMMAND) -P CMakeFiles/absl_vlog_config_internal.dir/cmake_clean.cmake
.PHONY : abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/clean

abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/depend:
	cd /home/christos/protobuf/christos_playground/gather_proto_bench/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/christos/protobuf/christos_playground/gather_proto_bench /home/christos/protobuf/third_party/abseil-cpp/absl/log /home/christos/protobuf/christos_playground/gather_proto_bench/build /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/log /home/christos/protobuf/christos_playground/gather_proto_bench/build/abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : abseil/absl/log/CMakeFiles/absl_vlog_config_internal.dir/depend

