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

//grid files
#include "shader.h"
#include "gridobject.h"
#include "Camera.h"
#include "texture.h"



class Engine {
    public:
        Engine(float, float);

        ~Engine();

        void run();


    private:
        void glPrintError();

        void doStuff();

        void display();

        void update();

        float screenheight, screenwidth;
        float thisTime, lastTime, tick;
        float moveSpeed;
        float mouseSensitivity;
        int mouseX, mouseY;
        bool pause;

        Camera* camera;

        std::vector<GridObject*> objects; //interactive 3d objects
        std::vector<GridObject*> scenary; //static 3d objects
        std::vector<GridObject*> uielems; //ui elements

        //replace later
        Shader* basicshader;

};
