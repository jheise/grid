cmake_minimum_required (VERSION 2.6)
project (grid)

find_package(OpenGL REQUIRED)
find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(PythonLibs 2.7 REQUIRED)
#add_executable(grid src/grid.cpp src/engine.cpp src/engine.h src/shader.cpp src/shader.h)
#add_library(shader src/shader.cpp)
#add_executable(grid src/grid.cpp src/engine.cpp src/engine.h src/shader.cpp src/shader.h)
#link_directories(src)
include_directories(${PYTHON_INCLUDE_DIRS})
add_executable(grid
    src/shader.cpp
    src/texture.cpp
    src/mesh.cpp
    src/model.cpp
    src/utils.cpp
    src/gridobject.cpp
    src/Camera.cpp
    src/engine.cpp
    src/grid.cpp
    )
target_link_libraries(grid GL GLEW glfw assimp IL ILU ILUT ${Boost_SYSTEM_LIBRARY} ${Boost_FILESYSTEM_LIBRARY} ${PYTHON_LIBRARIES})
