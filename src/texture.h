#pragma once
//C++ libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>

//openGL libs
#include <GL/glew.h>
#include <GL/glfw.h>

//DevIL libs
#define ILUT_USE_OPENGL
#include <IL/il.h>
#include <IL/ilu.h>
#include <IL/ilut.h>

class Texture {
    public:
        Texture(const std::string&);

        ~Texture();

        void bind(GLuint);

        void unbind();

    private:
        GLuint texture_id;
        std::string filename;
};
