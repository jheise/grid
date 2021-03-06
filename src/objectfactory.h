#pragma once
//C++ libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

//grid headers
#include "shader.h"
#include "gridobject.h"

class ObjectFactory {
    public:
        /*ObjectFactory(Shader*);*/
        ObjectFactory();
        ~ObjectFactory();
        void create_object(const std::string&, const std::string&);
        std::vector<GridObject*> get_objects();
        void return_object(GridObject*);
        Shader* get_shader();

    private:
        Shader* shader;
        std::vector<GridObject*> objects;   //interactive 3d objects

};
