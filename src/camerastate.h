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
#include "keyboardevent.h"
#include "cameralistener.h"
#include "Camera.h"

class CameraListener;

class CameraState {
    public:
        virtual ~CameraState();
        virtual void handle_event(CameraListener*, KeyboardEvent*, float);
};

class CameraStateWait: public CameraState{
    public:
        CameraStateWait();
        ~CameraStateWait();
        void handle_event(CameraListener*, KeyboardEvent*, float);
    private:
};

class CameraStateMove: public CameraState{
    public:
        CameraStateMove(Camera*, float);
        ~CameraStateMove();
        void handle_event(CameraListener*, KeyboardEvent*, float);
    private:
        Camera* camera;
        float  moveSpeed;

};
