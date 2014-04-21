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

class GridObject {
    public:
        GridObject();

        GridObject(Shader*, const std::string&, const std::string&);

        ~GridObject();

        void display(glm::mat4&);

        void update(float);

    private:
        Shader* shader;
        Texture* texture;
        GLuint vao, index, vertex, uv, normal, count, umodel, ucamera, utexture;
        glm::mat4 identity;
        float degree;


};
