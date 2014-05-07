#pragma once
//standard libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>
#include <boost/filesystem.hpp>

//opengl libs
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//text processing
#include <ft2build.h>
#include FT_FREETYPE_H

//grid files
#include "shader.h"
#include "utils.h"

class TextObject {
    public:
        TextObject();
        ~TextObject();
        void render_text(const char*, float, float, float, float);

    private:
        //FreeType related entries
        FT_Library      ft;
        FT_Face         face;
        FT_GlyphSlot    g;
        Shader*         textshader;
        GLuint          vao, vertex, texture;
};
