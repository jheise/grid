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
#include "textobject.h"
#include "scriptengine.h"

class Console;

class ConsoleState {
    public:
        virtual ~ConsoleState();
        virtual void handle_event(Console*, KeyboardEvent*, float);
        virtual void render();
};

class ConsoleWriteState: public ConsoleState{
    public:
        ConsoleWriteState(TextObject*, ScriptingEngine*);
        ~ConsoleWriteState();
        void handle_event(Console*, KeyboardEvent*, float);
        void render();
    private:
        std::vector<std::string> buffer;
        std::string current;
        TextObject* text_object;
        ScriptingEngine* script;
        float lastevent;
};

class ConsoleWaitState: public ConsoleState{
    public:
        ConsoleWaitState();
        ~ConsoleWaitState();
        void handle_event(Console*, KeyboardEvent*, float);
        void render();
    private:

};
