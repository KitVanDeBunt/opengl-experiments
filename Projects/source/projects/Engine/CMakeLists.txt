
set(SRCROOT ${PROJECT_SOURCE_DIR}/projects/Engine)

# - engine source files
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/ComponentSprite.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/ComponentSprite.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/ComponentTransform.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/ComponentTransform.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/ComponentBase.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/ComponentBase.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Engine.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Engine.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Entity.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Entity.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/SystemBase.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/SystemBase.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/SystemDisplay.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/SystemDisplay.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/SystemInput.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/SystemInput.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Vector2.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Vector2.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Vector3.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Vector3.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/KECS.h)

# - engine utils source filse
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Utils/EngineTime.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Utils/EngineTime.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Utils/Common.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Utils/Common.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Utils/OpenGLUtil.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/Engine/Utils/OpenGLUtil.h)

# - shader source files
# set(SRCFILES ${SRCFILES} ${SRCROOT}/Assets/Shaders/shader.fs.txt)
# set(SRCFILES ${SRCFILES} ${SRCROOT}/Assets/Shaders/shader.vs.txt)

# - game source files
set(SRCFILES ${SRCFILES} ${SRCROOT}/ComponentPlayer.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/ComponentPlayer.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/ComponentEnemy.cpp)
set(SRCFILES ${SRCFILES} ${SRCROOT}/ComponentEnemy.h)

set(SRCFILES ${SRCFILES} ${SRCROOT}/main.cpp)


#set(SRCFILES ${SRCROOT}/main.h)

#file(GLOB SRCFILES
 #   "${SRCROOT}/*.h"
 #  "${SRCROOT}/*.cpp"
#)


configure_file(${SRCROOT}/Assets/Shaders/shader.fs.txt shader.fs.txt COPYONLY)
configure_file(${SRCROOT}/Assets/Shaders/shader.vs.txt shader.vs.txt COPYONLY)

#configure_file(${SRCROOT}/Assets/Shaders/shader.fs.txt ../../../bin/Debug/shader.fs.txt COPYONLY)
#configure_file(${SRCROOT}/Assets/Shaders/shader.vs.txt ../../../bin/Debug/shader.vs.txt COPYONLY)

# Define sources and executable
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../../bin)
set(EXECUTABLE_NAME "Engine")
add_executable(${EXECUTABLE_NAME} ${SRCFILES})

if(SFML_FOUND)
  include_directories(${SFML_INCLUDE_DIR})
  target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES}  ${OPENGL_LIBRARIES})
endif()
  
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)
