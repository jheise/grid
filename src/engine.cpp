#include "engine.h"

void Engine::glPrintError(){
    GLenum errorCode = glGetError();

    if (errorCode != GL_NO_ERROR)
    {
        std::string error = "unknown error";
        std::string description  = "no description";

        // Decode the error code
        switch (errorCode)
        {
            case GL_INVALID_ENUM :
            {
                error = "GL_INVALID_ENUM";
                description = "an unacceptable value has been specified for an enumerated argument";
                break;
            }

            case GL_INVALID_VALUE :
            {
                error = "GL_INVALID_VALUE";
                description = "a numeric argument is out of range";
                break;
            }

            case GL_INVALID_OPERATION :
            {
                error = "GL_INVALID_OPERATION";
                description = "the specified operation is not allowed in the current state";
                break;
            }
            case GL_STACK_OVERFLOW :
            {
                error = "GL_STACK_OVERFLOW";
                description = "this command would cause a stack overflow";
                break;
            }

            case GL_STACK_UNDERFLOW :
            {
                error = "GL_STACK_UNDERFLOW";
                description = "this command would cause a stack underflow";
                break;
            }
            case GL_OUT_OF_MEMORY :
            {
                error = "GL_OUT_OF_MEMORY";
                description = "there is not enough memory left to execute the command";
                break;
            }

            case GL_INVALID_FRAMEBUFFER_OPERATION_EXT :
            {
                error = "GL_INVALID_FRAMEBUFFER_OPERATION_EXT";
                description = "the object bound to FRAMEBUFFER_BINDING_EXT is not \"framebuffer complete\"";
                break;
            }
        }
        std::cerr << "OpenGL Error: "  << error << ", " << description << std::endl;
        exit(1);
    }
}

Engine::Engine(int arg_c, char** arg_v, float width, float height){
    screenwidth = width;
    screenheight = height;
    lastTime = glfwGetTime();
    camera = new Camera();
    moveSpeed = 4.0;
    mouseSensitivity = 0.1;
    pause = false;
    argc = arg_c;
    argv = arg_v;
    //arg_0 = arg0;
}

void Engine::run(){

    //initialize glfw
    if(!glfwInit()){
        throw std::runtime_error("glfwInit Failed");
    }
    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4);
    glfwOpenWindowHint(0, GLFW_OPENGL_CORE_PROFILE);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3);
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);
    glfwOpenWindowHint(GLFW_WINDOW_NO_RESIZE, GL_TRUE);

    GLFWvidmode desktop;
    glfwGetDesktopMode(&desktop);
    screenwidth = desktop.Width;
    screenheight = desktop.Height;

    if(!glfwOpenWindow(screenwidth, screenheight, 0, 0, 0, 0, 32, 0, GLFW_FULLSCREEN)){
        throw std::runtime_error("glfwOpenWindow failed. does this hardware work with 3.1");
    }

    glewExperimental = GL_TRUE;
    if(glewInit() != GLEW_OK){
        throw std::runtime_error("glewInit failed");
    }

    if(!GLEW_VERSION_3_1){
        throw std::runtime_error("OpenGL 3.1 API is not available");
    }

    //enable certain functions
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glEnable(GL_SMOOTH);
    glEnable(GL_TEXTURE_2D);    //seriously why does this need to be enabled

    //set mouse cursore
    glfwDisable(GLFW_MOUSE_CURSOR);
    glfwSetMousePos(0, 0);
    //glfwSetMouseWheel(0);

    //Initialize devIL
    ilutRenderer(ILUT_OPENGL);
    ilInit();
    iluInit();
    ilutInit();
    ilutRenderer(ILUT_OPENGL);


    printf("engine started with %f %f\n", screenwidth, screenheight);

    //create object factory
    factory = new ObjectFactory();

    //start python
    printf("Initializing python\n");
    ScriptingEngine* script  = new ScriptingEngine(factory);
    //Py_SetProgramName(argv[0]);
    //Py_Initialize();
    //PySys_SetArgv(argc, argv);

    //initialize camera
    camera->setPosition(glm::vec3(0,0,8));
    camera->setViewportAspectRatio(screenwidth/screenheight);


    //Load models from python
    printf("building geometry\n");

    printf("Running...\t\t");
    fflush(stdout);
    while(glfwGetWindowParam(GLFW_OPENED)){

        GLenum error = glGetError();
        if(error != GL_NO_ERROR){
            glPrintError();
        }
        update();
        display();

        if(glfwGetKey(GLFW_KEY_ESC)){
            glfwCloseWindow();
        }
    }
    //Py_Finalize();
    glfwTerminate();
    printf("Done.\n");
}

void Engine::display(){
    //setup
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 view = camera->matrix();

    //Render all models
    std::vector<GridObject*> objects = factory->get_objects();
    for(int i = 0; i < objects.size(); i++){
        objects[i]->display(view);
    }


    //Render model related text

    //Render UI elements

    //clean up
    glBindVertexArray(0);
    glUseProgram(0);

    glfwSwapBuffers();
}

void Engine::update(){
    //determine amount of time changed since last pass
    thisTime = glfwGetTime();
    tick = thisTime - lastTime;
    lastTime = thisTime;

    if(!pause){
        //update all objects
        std::vector<GridObject*> objects = factory->get_objects();
        for(int i = 0; i < objects.size(); i++){
            objects[i]->update(tick);
        }
    }

    //replace with actual keyboard subsystem
    //forward back
    if(glfwGetKey('S')){
        camera->offsetPosition( tick * moveSpeed * -camera->forward());
    }else if(glfwGetKey('W')){
        camera->offsetPosition( tick * moveSpeed * camera->forward());
    }

    //left right
    if(glfwGetKey('A')){
        camera->offsetPosition( tick * moveSpeed * -camera->right());
    }else if(glfwGetKey('D')){
        camera->offsetPosition( tick * moveSpeed * camera->right());
    }

    //mouse
    glfwGetMousePos(&mouseX, &mouseY);
    camera->offsetOrientation(mouseSensitivity * mouseY, mouseSensitivity * mouseX);
    glfwSetMousePos(0,0);

    //pause updates
    if(glfwGetKey(GLFW_KEY_SPACE)){
        pause = true;
    }else{
        pause = false;
    }
}

Engine::~Engine(){
    delete factory;
    delete camera;

    printf("BYEBYE\n");
}
