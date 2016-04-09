//C++ libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>

//grid files
#include "engine.h"

using namespace std;

float screenwidth = 800.0f;
float screenheight = 600.0f;

int main(int argc, char *argv[]){
    //try{
        Engine engine = Engine(screenwidth, screenheight);
        engine.run();
        //} catch(...){
        //printf("EXCEPTION\n");
        //}
    return 0;
}
