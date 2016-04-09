#pragma once
//standard libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <fstream>
#include <vector>

//opengl libs
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>

//assimp libs
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

//grid files
#include "shader.h"
#include "texture.h"

class Mesh{
    public:
        Mesh();

        Mesh(aiMesh*);

        ~Mesh();

        void display(glm::mat4&, const std::vector<Texture*>&);

    private:
        /*Texture* texture;*/
        GLuint vao, index, vertex, uv, normal, count, umodel, ucamera, utexture;
        unsigned int material;

};
