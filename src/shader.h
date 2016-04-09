#pragma once
#include <string>
#include <stdio.h>
#include <stdexcept>
#include <fstream>
#include <sstream>

//opengl libs
#include <GL/glew.h>
#include <GL/glfw.h>

class Shader{
    public:
        Shader();

        Shader( const std::string&, const std::string& );

        ~Shader();

        GLuint handleShader( const std::string&, GLenum);

        void assemble();

        GLuint handleUniform( const std::string&);

        GLuint handleAttribute( const std::string&);

        void processLightUniform( const std::string&, const GLfloat*);

        void activate();

    private:
        std::string vertex_path;
        std::string fragment_path;
        GLuint shaderprogram;

};
