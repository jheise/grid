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

namespace grid {
    namespace textbox{
        class TextBox{

            public:
                TextBox( float, float, float, const std::string&);
                ~TextBox();
                void update(float);
                void render();
                void append(const std::string&);
                void pop_back();
            private:
                PangoTexture*   texture;
                Shader*         textshader;
                GLuint          vao, vertex, utexture;
                float x1, y1, yrange;
                bool needsupdate;
                std::string buffer;
        };
    }
}
