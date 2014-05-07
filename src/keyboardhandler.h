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

//grid libs
#include "Camera.h"
#include "keyboardevent.h"
#include "eventqueue.h"

class KeyboardHandler{
    public:
        KeyboardHandler(EventQueue*);

        ~KeyboardHandler();

        void handle_input();

    private:
        EventQueue* queue;
        bool f1hit;
};
