#pragma once

//C++ libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>

//openGL libs
#include <GL/glew.h>
#include <GL/glfw.h>

//pango
#include <pango/pangocairo.h>

class PangoTexture{
    public:
        PangoTexture(const std::string&);
        ~PangoTexture();
        void generate(const std::string&);
        void bind(GLuint);
        void unbind();
        int get_height();
        int get_width();

    private:
        GLuint texture_id;
        PangoLayout* layout;
        std::string font;
        int height, width;

};
