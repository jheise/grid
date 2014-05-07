#pragma once
//C++ libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <iostream>

//OpenGL libs
#include <GL/glfw.h>

//grid libs
#include "event.h"
#include "keyboardevent.h"

class EscapeListener{

    public:
        EscapeListener();
        ~EscapeListener();

        void receive(Event*,float);
    private:

};
