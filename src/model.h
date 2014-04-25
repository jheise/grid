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
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

//assimp libs
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

//grid files
#include "shader.h"
#include "texture.h"
#include "mesh.h"
#include "utils.h"

class Model{
    public:
        Model();

        Model(const std::string&, const std::string&);

       ~Model();

        void display(glm::mat4&);

    private:

        std::vector<Mesh*> meshes;  //all of the meshes
        std::vector<Texture*> textures; //all of the textures
};
