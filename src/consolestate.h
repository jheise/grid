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

//opengl
#include <GL/glew.h>
#include <GL/glfw.h>

//grid files
#include "keyboardevent.h"
#include "console.h"
#include "textbox.h"
#include "scriptengine.h"

class Console;

class ConsoleState {
    public:
        virtual ~ConsoleState();
        virtual void handle_event(Console*, KeyboardEvent*, float);
        virtual void render();
        virtual void update(float);
};

class ConsoleWriteState: public ConsoleState{
    public:
        ConsoleWriteState(ScriptingEngine*);
        ~ConsoleWriteState();
        void handle_event(Console*, KeyboardEvent*, float);
        void render();
        void update(float);

    private:
        std::string current;
        std::string last;
        grid::textbox::TextBox* text_box;
        ScriptingEngine* script;
        float lastevent;
        char block;
};

class ConsoleWaitState: public ConsoleState{
    public:
        ConsoleWaitState();
        ~ConsoleWaitState();
        void handle_event(Console*, KeyboardEvent*, float);
        void render();
        void update(float);
    private:

};
