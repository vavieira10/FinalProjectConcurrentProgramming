# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/victor/UnB/Semestre9/PC/Trabalho/FinalProjectConcurrentProgramming

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/victor/UnB/Semestre9/PC/Trabalho/FinalProjectConcurrentProgramming

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/victor/UnB/Semestre9/PC/Trabalho/FinalProjectConcurrentProgramming/CMakeFiles /home/victor/UnB/Semestre9/PC/Trabalho/FinalProjectConcurrentProgramming/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/victor/UnB/Semestre9/PC/Trabalho/FinalProjectConcurrentProgramming/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named main

# Build rule for target.
main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 main
.PHONY : main

# fast build rule for target.
main/fast:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/build
.PHONY : main/fast

src/auxiliar.o: src/auxiliar.c.o

.PHONY : src/auxiliar.o

# target to build an object file
src/auxiliar.c.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/auxiliar.c.o
.PHONY : src/auxiliar.c.o

src/auxiliar.i: src/auxiliar.c.i

.PHONY : src/auxiliar.i

# target to preprocess a source file
src/auxiliar.c.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/auxiliar.c.i
.PHONY : src/auxiliar.c.i

src/auxiliar.s: src/auxiliar.c.s

.PHONY : src/auxiliar.s

# target to generate assembly for a file
src/auxiliar.c.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/auxiliar.c.s
.PHONY : src/auxiliar.c.s

src/delivery.o: src/delivery.c.o

.PHONY : src/delivery.o

# target to build an object file
src/delivery.c.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/delivery.c.o
.PHONY : src/delivery.c.o

src/delivery.i: src/delivery.c.i

.PHONY : src/delivery.i

# target to preprocess a source file
src/delivery.c.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/delivery.c.i
.PHONY : src/delivery.c.i

src/delivery.s: src/delivery.c.s

.PHONY : src/delivery.s

# target to generate assembly for a file
src/delivery.c.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/delivery.c.s
.PHONY : src/delivery.c.s

src/drivethru.o: src/drivethru.c.o

.PHONY : src/drivethru.o

# target to build an object file
src/drivethru.c.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/drivethru.c.o
.PHONY : src/drivethru.c.o

src/drivethru.i: src/drivethru.c.i

.PHONY : src/drivethru.i

# target to preprocess a source file
src/drivethru.c.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/drivethru.c.i
.PHONY : src/drivethru.c.i

src/drivethru.s: src/drivethru.c.s

.PHONY : src/drivethru.s

# target to generate assembly for a file
src/drivethru.c.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/drivethru.c.s
.PHONY : src/drivethru.c.s

src/main.o: src/main.c.o

.PHONY : src/main.o

# target to build an object file
src/main.c.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.c.o
.PHONY : src/main.c.o

src/main.i: src/main.c.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.c.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.c.i
.PHONY : src/main.c.i

src/main.s: src/main.c.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.c.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/main.c.s
.PHONY : src/main.c.s

src/restaurant.o: src/restaurant.c.o

.PHONY : src/restaurant.o

# target to build an object file
src/restaurant.c.o:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/restaurant.c.o
.PHONY : src/restaurant.c.o

src/restaurant.i: src/restaurant.c.i

.PHONY : src/restaurant.i

# target to preprocess a source file
src/restaurant.c.i:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/restaurant.c.i
.PHONY : src/restaurant.c.i

src/restaurant.s: src/restaurant.c.s

.PHONY : src/restaurant.s

# target to generate assembly for a file
src/restaurant.c.s:
	$(MAKE) -f CMakeFiles/main.dir/build.make CMakeFiles/main.dir/src/restaurant.c.s
.PHONY : src/restaurant.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... main"
	@echo "... src/auxiliar.o"
	@echo "... src/auxiliar.i"
	@echo "... src/auxiliar.s"
	@echo "... src/delivery.o"
	@echo "... src/delivery.i"
	@echo "... src/delivery.s"
	@echo "... src/drivethru.o"
	@echo "... src/drivethru.i"
	@echo "... src/drivethru.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/restaurant.o"
	@echo "... src/restaurant.i"
	@echo "... src/restaurant.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

