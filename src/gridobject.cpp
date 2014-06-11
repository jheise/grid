#include "gridobject.h"

using namespace std;
using namespace grid;

GridObject::GridObject(){
};

GridObject::GridObject(Shader* shader_reference, const std::string& modelPath, const std::string& modelName){
    shader = shader_reference;
    model = new Model(modelPath, modelName);

    //setup identity and position
    identity = glm::mat4();
    umodel = shader->handleUniform("model");
    ucamera = shader->handleUniform("camera");
    utexture = shader->handleUniform("textureUniform");
    ulightpos = shader->handleUniform("light.position");
    ulightint = shader->handleUniform("light.intensities");
    degree = 0;

}

GridObject::~GridObject(){
    //printf("OBJECT GOES AWAY NOW\n");
}

void GridObject::display(glm::mat4& view, vector<light::Light*> lights){
    //turn on shader to use
    shader->activate();

    //update model
    glUniformMatrix4fv(umodel, 1, GL_FALSE, &identity[0][0]);
    //push current camera position
    glUniformMatrix4fv(ucamera, 1, GL_FALSE, &view[0][0]);

    //push light data
    glUniform3fv(ulightpos, 1, &lights[0]->get_position()[0]);
    glUniform3fv(ulightint, 1, &lights[0]->get_intensities()[0]);

    model->display(view);

    //clean up
    glBindVertexArray(0);
    glUseProgram(0);
}

void GridObject::update(float tick){
    //update code goes here
    degree += tick * 180.0f;
    if(degree > 360.0f){
        degree -= 360.0f;
    }
    identity = glm::rotate(glm::mat4(), degree, glm::vec3(0,1,0));
    identity = glm::rotate(glm::mat4(), 270.0f, glm::vec3(1,0,0));
    identity = glm::rotate(identity, degree, glm::vec3(0,0,1));
}
