
mkdir build-make
cd build-make
cmake ../source -G "MinGW Makefiles"
pause

cd build-make
mingw32-make
pause

cd ../bin
myproject.exe
pause