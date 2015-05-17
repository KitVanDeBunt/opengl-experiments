::@echo off
::cmake C:\Development\project\sfml\Project1\source -G "MinGW Makefiles"
::cmake C:\Development\project\sfml\Project1\source
mkdir build-code-block
cd build-code-block
cmake ../source -G "CodeBlocks - MinGW Makefiles"
::cmake C:\Development\project\sfml\Project1\source -G "Visual Studio 12"




::cd C:\Development\project\sfml\Project1\buildVS
::cmake C:\Development\project\sfml\Project1\source -G "Visual Studio 12"
::cd C:\Development\project\sfml\Project1\source
::cmake -g C:\Development\project\sfml\Project1\buildVS
pause
