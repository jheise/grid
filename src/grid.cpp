//C++ libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>

//engine stuff
#include "engine.h"

float screenwidth = 800.0f;
float screenheight = 600.0f;

int main(int argc, char *argv[]){
    try{
        Engine engine = Engine(screenwidth, screenheight);
        engine.run();
        printf("Grid Online\n");
    } catch(...){
        printf("EXCEPTION\n");
    }
    return 0;

}
