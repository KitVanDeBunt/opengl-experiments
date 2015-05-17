
set(SRCROOT ${PROJECT_SOURCE_DIR}/projects/ModelLoading)

# all source files
set(SRCFILES ${SRCFILES} ${SRCROOT}/entity.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/game.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/main.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/object.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/vector2D.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/vectorTest.cpp)

set(SRCFILES ${SRCFILES} ${SRCROOT}/entity.h)
set(SRCFILES ${SRCFILES} ${SRCROOT}/game.h)
set(SRCFILES ${SRCFILES} ${SRCROOT}/myTypes.h)
set(SRCFILES ${SRCFILES} ${SRCROOT}/object.h)
set(SRCFILES ${SRCFILES} ${SRCROOT}/vector2D.h)

# Define sources and executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../../bin)
set(EXECUTABLE_NAME "ModelLoading")
add_executable(${EXECUTABLE_NAME} ${SRCFILES})

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES}  ${OPENGL_LIBRARIES})
endif()

install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
