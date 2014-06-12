#include "scriptengine.h"
using namespace std;
using namespace grid;

ScriptingEngine::ScriptingEngine(ObjectFactory* factory_ptr, light::LightFactory* lightfactory_ptr){

    factory = factory_ptr;
    lightfactory = lightfactory_ptr;

    Py_Initialize();

    boost::python::object main_module(( boost::python::handle<>(boost::python::borrowed(PyImport_AddModule("__main__")))));
    main_namespace = main_module.attr("__dict__");

    main_namespace["ObjectFactory"] = boost::python::class_<ObjectFactory>("ObjectFactory").def("create_object", &ObjectFactory::create_object);

    main_namespace["factory"] = boost::python::ptr(factory);

    main_namespace["LightFactory"] = boost::python::class_<light::LightFactory>("LightFactory").def("create_light", &light::LightFactory::create_light);

    main_namespace["lightfactory"] = boost::python::ptr(lightfactory);

    FILE* testscript = fopen("../scripts/scripting.py","r");
    boost::python::handle<> ignored((PyRun_File(testscript, "scripting.py", Py_file_input, main_namespace.ptr(), main_namespace.ptr() ) ));
    catcher = PyObject_GetAttrString(main_module.ptr(), "catcher");


}

ScriptingEngine::~ScriptingEngine(){
    Py_Finalize();
}

std::string ScriptingEngine::get_output(){
    output = PyObject_GetAttrString(catcher, "data");
    return std::string(PyString_AsString(output));
}

//std::string ScriptingEngine::execute_command(const std::string& command){
void ScriptingEngine::execute_command(const std::string& command){
    //printf("executing command %s\n", command.c_str());
    PyRun_SimpleString(command.c_str());
    //output = PyObject_GetAttrString(catcher, "data");
    //return std::string(PyString_AsString(output));
}
