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
include examples/sound_capture/CMakeFiles/sound-capture.dir/depend.make

# Include the progress variables for this target.
include examples/sound_capture/CMakeFiles/sound-capture.dir/progress.make

# Include the compile flags for this target's objects.
include examples/sound_capture/CMakeFiles/sound-capture.dir/flags.make

examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj: examples/sound_capture/CMakeFiles/sound-capture.dir/flags.make
examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj: examples/sound_capture/CMakeFiles/sound-capture.dir/includes_CXX.rsp
examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj: C:/Development/project/sfml/SFML/examples/sound_capture/SoundCapture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report C:\Development\project\sfml\SFML-build-exmp\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj"
	cd /d C:\Development\project\sfml\SFML-build-exmp\examples\sound_capture && C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\sound-capture.dir\SoundCapture.cpp.obj -c C:\Development\project\sfml\SFML\examples\sound_capture\SoundCapture.cpp

examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sound-capture.dir/SoundCapture.cpp.i"
	cd /d C:\Development\project\sfml\SFML-build-exmp\examples\sound_capture && C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Development\project\sfml\SFML\examples\sound_capture\SoundCapture.cpp > CMakeFiles\sound-capture.dir\SoundCapture.cpp.i

examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sound-capture.dir/SoundCapture.cpp.s"
	cd /d C:\Development\project\sfml\SFML-build-exmp\examples\sound_capture && C:\PROGRA~2\CODEBL~1\MinGW\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Development\project\sfml\SFML\examples\sound_capture\SoundCapture.cpp -o CMakeFiles\sound-capture.dir\SoundCapture.cpp.s

examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj.requires:
.PHONY : examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj.requires

examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj.provides: examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj.requires
	$(MAKE) -f examples\sound_capture\CMakeFiles\sound-capture.dir\build.make examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj.provides.build
.PHONY : examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj.provides

examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj.provides.build: examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj

# Object files for target sound-capture
sound__capture_OBJECTS = \
"CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj"

# External object files for target sound-capture
sound__capture_EXTERNAL_OBJECTS =

examples/sound_capture/sound-capture.exe: examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj
examples/sound_capture/sound-capture.exe: examples/sound_capture/CMakeFiles/sound-capture.dir/build.make
examples/sound_capture/sound-capture.exe: lib/libsfml-audio.a
examples/sound_capture/sound-capture.exe: lib/libsfml-system.a
examples/sound_capture/sound-capture.exe: C:/Development/project/sfml/SFML/extlibs/libs-mingw/x86/libopenal32.a
examples/sound_capture/sound-capture.exe: C:/Development/project/sfml/SFML/extlibs/libs-mingw/x86/libvorbisenc.a
examples/sound_capture/sound-capture.exe: C:/Development/project/sfml/SFML/extlibs/libs-mingw/x86/libvorbisfile.a
examples/sound_capture/sound-capture.exe: C:/Development/project/sfml/SFML/extlibs/libs-mingw/x86/libvorbis.a
examples/sound_capture/sound-capture.exe: C:/Development/project/sfml/SFML/extlibs/libs-mingw/x86/libogg.a
examples/sound_capture/sound-capture.exe: C:/Development/project/sfml/SFML/extlibs/libs-mingw/x86/libFLAC.a
examples/sound_capture/sound-capture.exe: examples/sound_capture/CMakeFiles/sound-capture.dir/objects1.rsp
examples/sound_capture/sound-capture.exe: examples/sound_capture/CMakeFiles/sound-capture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sound-capture.exe"
	cd /d C:\Development\project\sfml\SFML-build-exmp\examples\sound_capture && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sound-capture.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/sound_capture/CMakeFiles/sound-capture.dir/build: examples/sound_capture/sound-capture.exe
.PHONY : examples/sound_capture/CMakeFiles/sound-capture.dir/build

examples/sound_capture/CMakeFiles/sound-capture.dir/requires: examples/sound_capture/CMakeFiles/sound-capture.dir/SoundCapture.cpp.obj.requires
.PHONY : examples/sound_capture/CMakeFiles/sound-capture.dir/requires

examples/sound_capture/CMakeFiles/sound-capture.dir/clean:
	cd /d C:\Development\project\sfml\SFML-build-exmp\examples\sound_capture && $(CMAKE_COMMAND) -P CMakeFiles\sound-capture.dir\cmake_clean.cmake
.PHONY : examples/sound_capture/CMakeFiles/sound-capture.dir/clean

examples/sound_capture/CMakeFiles/sound-capture.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Development\project\sfml\SFML C:\Development\project\sfml\SFML\examples\sound_capture C:\Development\project\sfml\SFML-build-exmp C:\Development\project\sfml\SFML-build-exmp\examples\sound_capture C:\Development\project\sfml\SFML-build-exmp\examples\sound_capture\CMakeFiles\sound-capture.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : examples/sound_capture/CMakeFiles/sound-capture.dir/depend

