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

//grid files
#include "event.h"
#include "keyboardevent.h"
#include "consolestate.h"
#include "scriptengine.h"

class ConsoleState;
class ConsoleWaitState;
class ConsoleWriteState;

class Console {
    public:
        Console(ScriptingEngine*);
        ~Console();
        void receive(Event*, float);
        void update(float);
        void render();
        void switch_state();

    private:
        ConsoleState* current;
        ConsoleWriteState* write_state;
        ConsoleWaitState*  wait_state;
};
