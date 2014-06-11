#include "light.h"

using namespace grid;
using namespace light;

Light::Light(glm::vec3 pos, glm::vec3 intens){
    position = pos;
    intensities = intens;
}

Light::~Light(){
    turnoff();
}

void Light::set_position(glm::vec3 newpos){
    position = newpos;
}

void Light::set_intensities(glm::vec3 intens){
    intensities = intens;
}

glm::vec3 Light::get_position(){
    return position;
}

glm::vec3 Light::get_intensities(){
    return intensities;
}

void Light::turnon(GLuint upos, GLuint uint ){
    glUniform3fv(upos, 1, &position[0]);
    glUniform3fv(uint, 1, &intensities[0]);
}

void Light::turnoff(){

}
