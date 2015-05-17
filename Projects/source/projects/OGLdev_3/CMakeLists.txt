
set(SRCROOT ${PROJECT_SOURCE_DIR}/projects/OGLdev_3)

# all source files
set(SRCFILES ${SRCFILES} ${SRCROOT}/main.cpp)

# Define sources and executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../../bin)
set(EXECUTABLE_NAME "OGLdev_3")
add_executable(${EXECUTABLE_NAME} ${SRCFILES})

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES}  ${OPENGL_LIBRARIES})
endif()
  
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
