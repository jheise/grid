cmake_minimum_required (VERSION 2.6)
project (grid)

find_package(OpenGL REQUIRED)
#add_executable(grid src/grid.cpp src/engine.cpp src/engine.h src/shader.cpp src/shader.h)
#add_library(shader src/shader.cpp)
#add_executable(grid src/grid.cpp src/engine.cpp src/engine.h src/shader.cpp src/shader.h)
#link_directories(src)
add_executable(grid
    src/shader.cpp
    src/texture.cpp
    src/gridobject.cpp
    src/Camera.cpp
    src/engine.cpp
    src/grid.cpp
    )
target_link_libraries(grid GL GLEW glfw assimp IL ILU ILUT)
