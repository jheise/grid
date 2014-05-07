#pragma once
//C++ libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <typeinfo>
#include <iostream>

//grid libs
#include "Camera.h"
#include "event.h"
#include "keyboardevent.h"
#include "camerastate.h"

class CameraState;
class CameraStateWait;
class CameraStateMove;

class CameraListener{

    public:
        CameraListener(Camera*, float);
        ~CameraListener();

        void receive(Event*,float);
        void switch_state();

    private:
        CameraState* current;
        CameraStateWait* wait;
        CameraStateMove* move;
};
