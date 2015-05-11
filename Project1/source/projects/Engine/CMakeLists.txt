
set(SRCROOT ${PROJECT_SOURCE_DIR}/projects/Engine)

# all source files
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Entity.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/main.cpp)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine.h)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Entity.h)
#set(SRCFILES ${SRCROOT}/main.h)

#file(GLOB SRCFILES
 #   "${SRCROOT}/*.h"
 #  "${SRCROOT}/*.cpp"
#)

# Define sources and executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../../bin)
set(EXECUTABLE_NAME "Engine")
add_executable(${EXECUTABLE_NAME} ${SRCFILES})

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES}  ${OPENGL_LIBRARIES})
endif()
  
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
