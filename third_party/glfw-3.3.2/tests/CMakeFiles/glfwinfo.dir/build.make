# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/cammy/git/ARES/third_party/glfw-3.3.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cammy/git/ARES/third_party/glfw-3.3.2

# Include any dependencies generated for this target.
include tests/CMakeFiles/glfwinfo.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/glfwinfo.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/glfwinfo.dir/flags.make

tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o: tests/CMakeFiles/glfwinfo.dir/flags.make
tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o: tests/glfwinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cammy/git/ARES/third_party/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/glfwinfo.c.o   -c /home/cammy/git/ARES/third_party/glfw-3.3.2/tests/glfwinfo.c

tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/glfwinfo.c.i"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cammy/git/ARES/third_party/glfw-3.3.2/tests/glfwinfo.c > CMakeFiles/glfwinfo.dir/glfwinfo.c.i

tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/glfwinfo.c.s"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cammy/git/ARES/third_party/glfw-3.3.2/tests/glfwinfo.c -o CMakeFiles/glfwinfo.dir/glfwinfo.c.s

tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires:

.PHONY : tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires

tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides: tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires
	$(MAKE) -f tests/CMakeFiles/glfwinfo.dir/build.make tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides.build
.PHONY : tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides

tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.provides.build: tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o


tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o: tests/CMakeFiles/glfwinfo.dir/flags.make
tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o: deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cammy/git/ARES/third_party/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o   -c /home/cammy/git/ARES/third_party/glfw-3.3.2/deps/getopt.c

tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cammy/git/ARES/third_party/glfw-3.3.2/deps/getopt.c > CMakeFiles/glfwinfo.dir/__/deps/getopt.c.i

tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cammy/git/ARES/third_party/glfw-3.3.2/deps/getopt.c -o CMakeFiles/glfwinfo.dir/__/deps/getopt.c.s

tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires:

.PHONY : tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires

tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides: tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires
	$(MAKE) -f tests/CMakeFiles/glfwinfo.dir/build.make tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides.build
.PHONY : tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides

tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.provides.build: tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o


tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o: tests/CMakeFiles/glfwinfo.dir/flags.make
tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o: deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cammy/git/ARES/third_party/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o   -c /home/cammy/git/ARES/third_party/glfw-3.3.2/deps/glad_gl.c

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cammy/git/ARES/third_party/glfw-3.3.2/deps/glad_gl.c > CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cammy/git/ARES/third_party/glfw-3.3.2/deps/glad_gl.c -o CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.s

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.requires:

.PHONY : tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.requires

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.provides: tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.requires
	$(MAKE) -f tests/CMakeFiles/glfwinfo.dir/build.make tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.provides.build
.PHONY : tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.provides

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.provides.build: tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o


tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o: tests/CMakeFiles/glfwinfo.dir/flags.make
tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o: deps/glad_vulkan.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cammy/git/ARES/third_party/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o   -c /home/cammy/git/ARES/third_party/glfw-3.3.2/deps/glad_vulkan.c

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/cammy/git/ARES/third_party/glfw-3.3.2/deps/glad_vulkan.c > CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.i

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/cammy/git/ARES/third_party/glfw-3.3.2/deps/glad_vulkan.c -o CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.s

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.requires:

.PHONY : tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.requires

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.provides: tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.requires
	$(MAKE) -f tests/CMakeFiles/glfwinfo.dir/build.make tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.provides.build
.PHONY : tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.provides

tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.provides.build: tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o


# Object files for target glfwinfo
glfwinfo_OBJECTS = \
"CMakeFiles/glfwinfo.dir/glfwinfo.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o" \
"CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o"

# External object files for target glfwinfo
glfwinfo_EXTERNAL_OBJECTS =

tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o
tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o
tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o
tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o
tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/build.make
tests/glfwinfo: src/libglfw3.a
tests/glfwinfo: /usr/lib/x86_64-linux-gnu/libm.so
tests/glfwinfo: /usr/lib/x86_64-linux-gnu/librt.so
tests/glfwinfo: /usr/lib/x86_64-linux-gnu/libm.so
tests/glfwinfo: /usr/lib/x86_64-linux-gnu/libX11.so
tests/glfwinfo: tests/CMakeFiles/glfwinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cammy/git/ARES/third_party/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable glfwinfo"
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glfwinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/glfwinfo.dir/build: tests/glfwinfo

.PHONY : tests/CMakeFiles/glfwinfo.dir/build

tests/CMakeFiles/glfwinfo.dir/requires: tests/CMakeFiles/glfwinfo.dir/glfwinfo.c.o.requires
tests/CMakeFiles/glfwinfo.dir/requires: tests/CMakeFiles/glfwinfo.dir/__/deps/getopt.c.o.requires
tests/CMakeFiles/glfwinfo.dir/requires: tests/CMakeFiles/glfwinfo.dir/__/deps/glad_gl.c.o.requires
tests/CMakeFiles/glfwinfo.dir/requires: tests/CMakeFiles/glfwinfo.dir/__/deps/glad_vulkan.c.o.requires

.PHONY : tests/CMakeFiles/glfwinfo.dir/requires

tests/CMakeFiles/glfwinfo.dir/clean:
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2/tests && $(CMAKE_COMMAND) -P CMakeFiles/glfwinfo.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/glfwinfo.dir/clean

tests/CMakeFiles/glfwinfo.dir/depend:
	cd /home/cammy/git/ARES/third_party/glfw-3.3.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cammy/git/ARES/third_party/glfw-3.3.2 /home/cammy/git/ARES/third_party/glfw-3.3.2/tests /home/cammy/git/ARES/third_party/glfw-3.3.2 /home/cammy/git/ARES/third_party/glfw-3.3.2/tests /home/cammy/git/ARES/third_party/glfw-3.3.2/tests/CMakeFiles/glfwinfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/glfwinfo.dir/depend

