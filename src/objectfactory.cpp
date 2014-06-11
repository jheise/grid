#include "objectfactory.h"

//ObjectFactory::ObjectFactory(Shader* shader_ptr){
    //shader = shader_ptr;
//}
ObjectFactory::ObjectFactory(){
    shader = new Shader(std::string("../shaders/basic.vertex"), std::string("../shaders/basic.fragment"));
    shader->assemble();

}

ObjectFactory::~ObjectFactory(){
    for(int i =0; i < objects.size(); i++){
        delete objects[i];
    }
    delete shader;

}

void ObjectFactory::create_object(const std::string& modelPath, const std::string& modelName){
    GridObject* new_object = new GridObject(shader, modelPath, modelName);
    objects.push_back(new_object);

    //return new_object;
}

std::vector<GridObject*> ObjectFactory::get_objects(){
    return objects;
}

void ObjectFactory::return_object(GridObject*){

}

Shader* ObjectFactory::get_shader(){
    return shader;
}
