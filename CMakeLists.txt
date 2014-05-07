cmake_minimum_required (VERSION 2.6)
project (grid)

find_package(OpenGL REQUIRED)
find_package(Boost COMPONENTS system filesystem python REQUIRED)
find_package(PythonLibs 2.7 REQUIRED)
INCLUDE(FindFreetype)
#add_executable(grid src/grid.cpp src/engine.cpp src/engine.h src/shader.cpp src/shader.h)
#add_library(shader src/shader.cpp)
#add_executable(grid src/grid.cpp src/engine.cpp src/engine.h src/shader.cpp src/shader.h)
#link_directories(src)
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${FREETYPE_INCLUDE_DIRS})
add_executable(grid
    src/shader.cpp
    src/texture.cpp
    src/mesh.cpp
    src/model.cpp
    src/textobject.cpp
    src/utils.cpp
    src/event.cpp
    src/keyboardevent.cpp
    src/eventqueue.cpp
    src/gridobject.cpp
    src/objectfactory.cpp
    src/Camera.cpp
    src/keyboardhandler.cpp
    src/camerastate.cpp
    src/cameralistener.cpp
    src/escapelistener.cpp
    src/consolestate.cpp
    src/console.cpp
    src/scriptengine.cpp
    src/engine.cpp
    src/grid.cpp
    )
target_link_libraries(grid GL GLEW glfw assimp IL ILU ILUT ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_PYTHON_LIBRARY} ${PYTHON_LIBRARIES} ${FREETYPE_LIBRARIES})
