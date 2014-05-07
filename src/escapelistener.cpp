#include "escapelistener.h"

EscapeListener::EscapeListener(){

}

EscapeListener::~EscapeListener(){

}

void EscapeListener::receive(Event* event, float tick){
    //if( typeid(*event) == typeid(KeyboardEvent()){
    KeyboardEvent* key_event = dynamic_cast<KeyboardEvent*>(event);
    if(key_event){
        char key = key_event->get_key();
        if( key == 27 ){
           glfwCloseWindow();
        }
    }
}
