#pragma once
//C++ libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

//opengl libs
#include <GL/glew.h>
#include <GL/glfw.h>

//grid files
#include "shader.h"
#include "pangotexture.h"

class PangoTest {

    public:
        PangoTest();
        ~PangoTest();
        void render();
    private:
        PangoTexture*   ptexture;
        Shader*         ptextshader;
        GLuint          vao, vertex, ptext;
};
