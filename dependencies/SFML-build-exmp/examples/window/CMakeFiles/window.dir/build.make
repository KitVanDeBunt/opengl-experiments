# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.0

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Development\project\sfml\SFML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Development\project\sfml\SFML-build-exmp

# Include any dependencies generated for this target.
include examples/window/CMakeFiles/window.dir/depend.make

# Include the progress variables for this target.
include examples/window/CMakeFiles/window.dir/progress.make

# Include the compile flags for this target's objects.
include examples/window/CMakeFiles/window.dir/flags.make

examples/window/CMakeFiles/window.dir/Window.cpp.obj: examples/window/CMakeFiles/window.dir/flags.make
examples/window/CMakeFiles/window.dir/Window.cpp.obj: examples/window/CMakeFiles/window.dir/includes_CXX.rsp
examples/window/CMakeFiles/window.dir/Window.cpp.obj: C:/Development/project/sfml/SFML/examples/window/Window.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report C:\Development\project\sfml\SFML-build-exmp\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/window/CMakeFiles/window.dir/Window.cpp.obj"
	cd /d C:\Development\project\sfml\SFML-build-exmp\examples\window && C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\window.dir\Window.cpp.obj -c C:\Development\project\sfml\SFML\examples\window\Window.cpp

examples/window/CMakeFiles/window.dir/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/window.dir/Window.cpp.i"
	cd /d C:\Development\project\sfml\SFML-build-exmp\examples\window && C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Development\project\sfml\SFML\examples\window\Window.cpp > CMakeFiles\window.dir\Window.cpp.i

examples/window/CMakeFiles/window.dir/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/window.dir/Window.cpp.s"
	cd /d C:\Development\project\sfml\SFML-build-exmp\examples\window && C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Development\project\sfml\SFML\examples\window\Window.cpp -o CMakeFiles\window.dir\Window.cpp.s

examples/window/CMakeFiles/window.dir/Window.cpp.obj.requires:
.PHONY : examples/window/CMakeFiles/window.dir/Window.cpp.obj.requires

examples/window/CMakeFiles/window.dir/Window.cpp.obj.provides: examples/window/CMakeFiles/window.dir/Window.cpp.obj.requires
	$(MAKE) -f examples\window\CMakeFiles\window.dir\build.make examples/window/CMakeFiles/window.dir/Window.cpp.obj.provides.build
.PHONY : examples/window/CMakeFiles/window.dir/Window.cpp.obj.provides

examples/window/CMakeFiles/window.dir/Window.cpp.obj.provides.build: examples/window/CMakeFiles/window.dir/Window.cpp.obj

# Object files for target window
window_OBJECTS = \
"CMakeFiles/window.dir/Window.cpp.obj"

# External object files for target window
window_EXTERNAL_OBJECTS =

examples/window/window.exe: examples/window/CMakeFiles/window.dir/Window.cpp.obj
examples/window/window.exe: examples/window/CMakeFiles/window.dir/build.make
examples/window/window.exe: lib/libsfml-main.a
examples/window/window.exe: lib/libsfml-window.a
examples/window/window.exe: lib/libsfml-system.a
examples/window/window.exe: examples/window/CMakeFiles/window.dir/objects1.rsp
examples/window/window.exe: examples/window/CMakeFiles/window.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable window.exe"
	cd /d C:\Development\project\sfml\SFML-build-exmp\examples\window && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\window.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/window/CMakeFiles/window.dir/build: examples/window/window.exe
.PHONY : examples/window/CMakeFiles/window.dir/build

examples/window/CMakeFiles/window.dir/requires: examples/window/CMakeFiles/window.dir/Window.cpp.obj.requires
.PHONY : examples/window/CMakeFiles/window.dir/requires

examples/window/CMakeFiles/window.dir/clean:
	cd /d C:\Development\project\sfml\SFML-build-exmp\examples\window && $(CMAKE_COMMAND) -P CMakeFiles\window.dir\cmake_clean.cmake
.PHONY : examples/window/CMakeFiles/window.dir/clean

examples/window/CMakeFiles/window.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Development\project\sfml\SFML C:\Development\project\sfml\SFML\examples\window C:\Development\project\sfml\SFML-build-exmp C:\Development\project\sfml\SFML-build-exmp\examples\window C:\Development\project\sfml\SFML-build-exmp\examples\window\CMakeFiles\window.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : examples/window/CMakeFiles/window.dir/depend
