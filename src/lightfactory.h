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

//opengl libs
#include <GL/glew.h>
#include <GL/glfw.h>
#include <glm/glm.hpp>

//grid headers
#include "light.h"
namespace grid {
    namespace light{
        class LightFactory{

            public:
                LightFactory();
                ~LightFactory();
                void create_light(float, float, float, float, float, float);
                std::vector<Light*> get_lights();
                void return_light(Light*);

            private:
                std::vector<Light*> lights;
        };
    }
}
