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

//python
#include <Python.h>
#include <boost/python.hpp>
#include <boost/python/module.hpp>
#include <boost/python/def.hpp>

//grid files
#include "objectfactory.h"

class ScriptingEngine {
    public:
        ScriptingEngine(ObjectFactory*);

        ~ScriptingEngine();

    private:
        ObjectFactory* factory;
};
