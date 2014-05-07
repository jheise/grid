#include "scriptengine.h"

ScriptingEngine::ScriptingEngine(ObjectFactory* factory_ptr){

    factory = factory_ptr;

    Py_Initialize();

    boost::python::object main_module(( boost::python::handle<>(boost::python::borrowed(PyImport_AddModule("__main__")))));
    main_namespace = main_module.attr("__dict__");

    main_namespace["ObjectFactory"] = boost::python::class_<ObjectFactory>("ObjectFactory").def("create_object", &ObjectFactory::create_object);

    main_namespace["factory"] = boost::python::ptr(factory);

    FILE* testscript = fopen("../scripts/grid.py","r");
    boost::python::handle<> ignored((PyRun_File(testscript, "grid.py", Py_file_input, main_namespace.ptr(), main_namespace.ptr() ) ));

}

ScriptingEngine::~ScriptingEngine(){
    Py_Finalize();
}

void ScriptingEngine::execute_command(const std::string& command){
    printf("executing command %s\n", command.c_str());
    PyRun_SimpleString(command.c_str());
}
