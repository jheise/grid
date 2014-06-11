#include "lightfactory.h"

//set namespaces
using namespace std;
using namespace glm;
using namespace grid;
using namespace light;

LightFactory::LightFactory(){

}

LightFactory::~LightFactory(){

}

void LightFactory::create_light(float x, float y, float z, float r, float g, float b){
    Light* new_light = new Light(vec3(x,y,z), vec3(r,g,b));
    lights.push_back(new_light);
}

void LightFactory::return_light(Light* old_light){

}

vector<Light*> LightFactory::get_lights(){
    return lights;
}
