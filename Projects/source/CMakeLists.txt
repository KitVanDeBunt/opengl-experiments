cmake_minimum_required(VERSION 2.6)
project(myproject)


set(EXT_LIB_PATH "../../dependencies/")

# set(SFML_STATIC_LIBRARIES TRUE)
if(SFML_STATIC_LIBRARIES)
	# sfml dependencies vs
	set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${EXT_LIB_PATH}SFML-source/extlibs/libs-msvc/x86")
	# sfml dependencies
	set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${EXT_LIB_PATH}SFML-source/extlibs/headers")
	set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${EXT_LIB_PATH}SFML-source/extlibs/bin/x86")

	# sfml path
	set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${EXT_LIB_PATH}SFML-build-static-vs/lib/Debug")
	#set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "../../lib/SFML-source/include")
else()
	# sfml path
	# set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "C:/Development/project/sfml/lib/SFML-build/lib")
	set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${EXT_LIB_PATH}SFML-build-vs/lib/Release")
endif()
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${EXT_LIB_PATH}SFML-source/include")

# build path
set(EXECUTABLE_OUTPUT_PATH "../bin")
# GLM path
set(GLM_INCLUDE_DIR "${EXT_LIB_PATH}includes")

# glew path
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${EXT_LIB_PATH}glew-1.12.0")
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} "${EXT_LIB_PATH}glew-1.12.0/lib/Release/Win32")

# include  GLM
include_directories(${GLM_INCLUDE_DIR})

# find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
set(OPENGL_LIBRARIES ${OPENGL_LIBRARIES})

# find glew
find_package(GLEW REQUIRED)
if (GLEW_FOUND)
    include_directories(${GLEW_INCLUDE_DIRS})
    link_libraries(${GLEW_LIBRARIES})
endif()

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()
# (you can also set it on the command line: -D CMAKE_BUILD_TYPE=Release)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)

configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
  
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(PLANE_EXECUTABLE_NAME "PlaneProject")
add_executable(${PLANE_EXECUTABLE_NAME} plane.cpp)


# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
if(SFML_STATIC_LIBRARIES)
	find_package(SFML 2 COMPONENTS system window graphics network audio)
else()
	find_package(SFML 2 REQUIRED system window graphics network audio)
endif()

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${PLANE_EXECUTABLE_NAME} ${SFML_LIBRARIES}  ${OPENGL_LIBRARIES})
endif()

# Install target
install(TARGETS ${PLANE_EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)

if(SFML_FOUND)
	add_subdirectory(projects)
endif()















