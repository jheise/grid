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

//assimp libs
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

//grid files
#include "shader.h"
#include "model.h"
#include "light.h"
#include "utils.h"

class GridObject {
    public:
        GridObject();

        GridObject(Shader*, const std::string&, const std::string&);

        ~GridObject();

        void display(glm::mat4&, std::vector<grid::light::Light*>);

        void update(float);

    private:
        Shader* shader;
        Model* model;
        GLuint umodel, ucamera, utexture, ulightpos, ulightint;
        glm::mat4 identity;
        float degree;

};
