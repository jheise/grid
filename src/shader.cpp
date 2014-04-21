#include "shader.h"

Shader::Shader(){
    vertex_path = std::string("not a vertex shader");
    fragment_path = std::string("not a fragment shader");
}

Shader::Shader( const std::string& vertexpath, const std::string& fragpath){
    vertex_path = vertexpath;
    fragment_path = fragpath;

}

Shader::~Shader(){
    printf( "Shader Unloaded\n");
}

void Shader::assemble(){
    GLuint vertshader, fragshader;
    vertshader = Shader::handleShader(vertex_path, GL_VERTEX_SHADER);
    fragshader = Shader::handleShader(fragment_path, GL_FRAGMENT_SHADER);

    //printf("Assemble: shaderprogram is %d\n", shaderprogram);
    shaderprogram = glCreateProgram();
    if(shaderprogram == 0){
        throw std::runtime_error("glCreateProgram failed");
    }
    //printf("Assemble: shaderprogram is %d\n", shaderprogram);

    glAttachShader(shaderprogram, vertshader);
    glAttachShader(shaderprogram, fragshader);

    glLinkProgram(shaderprogram);
    GLint status;
    glGetProgramiv(shaderprogram, GL_LINK_STATUS, &status);
    if(status == GL_FALSE){
        std::string msg("Program linking failure: ");

        GLint infologlen;
        glGetProgramiv(shaderprogram, GL_INFO_LOG_LENGTH, &infologlen);
        char* strinfolog = new char[infologlen + 1];
        glGetProgramInfoLog(shaderprogram, infologlen, NULL, strinfolog);
        msg += strinfolog;
        delete[] strinfolog;

        glDeleteProgram(shaderprogram);
        throw std::runtime_error(msg);
    }

    printf("Shader Assembled!\n");
}

GLuint Shader::handleShader( const std::string& shaderpath, GLenum shaderType){
    printf("assembling %s\n", shaderpath.c_str());
    std::ifstream f;
    f.open(shaderpath.c_str(), std::ios::in | std::ios::binary);
    if(!f.is_open()){
        throw std::runtime_error(std::string("Failed to open file: ") + shaderpath);
    }

    std::stringstream buffer;
    buffer << f.rdbuf();
    std::string bufferstr = buffer.str();
    GLuint shader;
    shader = glCreateShader(shaderType);
    if(shader == 0){
        throw std::runtime_error("glCreateShader failed");
    }
    const char* code = bufferstr.c_str();
    glShaderSource(shader, 1, (const GLchar**)&code, NULL);
    glCompileShader(shader);

    GLint status;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if(status == GL_FALSE){
        std::string msg("Failed to compile shader:\n");

        GLint infologlen;
        glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &infologlen);
        char* strinfolog = new char[infologlen + 1];
        glGetShaderInfoLog( shader, infologlen, NULL, strinfolog);
        msg += strinfolog;
        delete[] strinfolog;

        glDeleteShader(shader);
        shader = 0;
        throw std::runtime_error(msg);
    }

    return shader;
}


GLuint Shader::handleUniform( const std::string& uniform){
    printf("handling Uniform %s\n", uniform.c_str());
    GLuint uniform_value = -1;
    uniform_value = glGetUniformLocation(shaderprogram, uniform.c_str());
    //printf("shaderprogram is %d\n", shaderprogram);
    //printf("%s is value %d\n",uniform.c_str(), uniform_value);
    if(uniform_value == -1){
        throw std::runtime_error(std::string("program uniform not found:"));
    }
    return uniform_value;
}

GLuint Shader::handleAttribute( const std::string& attribute){
    GLuint retval = -1;
    retval = glGetAttribLocation(shaderprogram, attribute.c_str());
    if(retval == -1){
        throw std::runtime_error(std::string("program attribute not found:"));
    }
    return retval;
}

void Shader::activate(){
    glUseProgram(shaderprogram);
}
