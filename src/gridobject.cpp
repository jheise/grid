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
    ulightcount = shader->handleUniform("numlights");
    //ulightpos = shader->handleUniform("light[0].position");
    //ulightint = shader->handleUniform("light[0].intensities");
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
    glUniform1i(ulightcount, (int)lights.size());
    for( int i=0; i < (int)lights.size(); i++){
        std::ostringstream ss;
        std::ostringstream sa;
        ss << "light[" << i << "].position";
        std::string uniform_name = ss.str();
        sa << "light[" << i << "].intensities";
        std::string other_name = sa.str();

        shader->processLightUniform(uniform_name.c_str(), &lights[0]->get_position()[0]);
        shader->processLightUniform(other_name.c_str(), &lights[0]->get_intensities()[0]);
    }

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
