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

//python
#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

//grid files
#include "shader.h"
#include "gridobject.h"
#include "Camera.h"
#include "texture.h"
#include "pangotexture.h"
#include "pangotest.h"
#include "textbox.h"
#include "light.h"
#include "objectfactory.h"
#include "scriptengine.h"
#include "event.h"
#include "eventqueue.h"
#include "keyboardhandler.h"
#include "cameralistener.h"
#include "escapelistener.h"
#include "textobject.h"
#include "console.h"



class Engine {
    public:
        Engine(int ,char**,float, float);

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

        ObjectFactory*      factory;
        EventQueue*         queue;
        ScriptingEngine*    script;
        KeyboardHandler*    keyboard;
        CameraListener*     clistener;
        EscapeListener*     elistener;
        TextObject*         textobj;
        Console*            console;
        PangoTest*          ptext;
        grid::textbox::TextBox*            tbox;

        //replace later
        Shader* basicshader;
        int argc;
        char** argv;

};
