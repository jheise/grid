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

class Mesh{
    public:
        Mesh();

        Mesh(Shader*, const std::string&, aiMesh*);

        ~Mesh();

        void display(glm::mat4&, const std::vector<Texture*>&);

        void update(float);

    private:
        Shader* shader;
        GLuint vao, index, vertex, uv, normal, count, umodel, ucamera, utexture;
        unsigned int material;

};
