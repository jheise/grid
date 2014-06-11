cmake_minimum_required (VERSION 2.6)
project (grid)
list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

#Pango_DIR="../cmake"

find_package(OpenGL REQUIRED)
find_package(Pango REQUIRED)
find_package(Cairo REQUIRED)
find_package(PangoCairo REQUIRED)
find_package(Boost COMPONENTS system filesystem python REQUIRED)
find_package(PythonLibs 2.7 REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLIB_PKG glib-2.0)

if (GLIB_PKG_FOUND)
    message(Found glib-2.0)
include_directories(${GLIB_PKG_INCLUDE_DIRS})
endif()
INCLUDE(FindFreetype)
#add_executable(grid src/grid.cpp src/engine.cpp src/engine.h src/shader.cpp src/shader.h)
#add_library(shader src/shader.cpp)
#add_executable(grid src/grid.cpp src/engine.cpp src/engine.h src/shader.cpp src/shader.h)
#link_directories(src)
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(${FREETYPE_INCLUDE_DIRS})
#include_directories(${PANGOCAIRO_INCLUDE_DIRS})
#include_directories(${LIBPANGO_INCLUDE_DIR})
include_directories(${Pango_1_0_INCLUDE_DIR})
#include_directories(/usr/include/pango-1.0)
include_directories(/usr/include/cairo)
add_executable(grid
    src/shader.cpp
    src/texture.cpp
    src/mesh.cpp
    src/light.cpp
    src/model.cpp
    src/textobject.cpp
    src/pangotexture.cpp
    src/textbox.cpp
    src/utils.cpp
    src/event.cpp
    src/keyboardevent.cpp
    src/eventqueue.cpp
    src/gridobject.cpp
    src/lightfactory.cpp
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
target_link_libraries(grid GL GLEW glfw assimp IL ILU ILUT cairo pango-1.0 ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${Boost_PYTHON_LIBRARY} ${PYTHON_LIBRARIES} ${FREETYPE_LIBRARIES} ${Pango_1_0_LIBRARIES} ${PANGOCAIRO_LIBRARY})
