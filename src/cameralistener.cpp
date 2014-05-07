#include "cameralistener.h"

CameraListener::CameraListener(Camera* camera_ptr, float move_speed){

    move = new CameraStateMove(camera_ptr, move_speed);
    wait = new CameraStateWait();
    current = move;
}

CameraListener::~CameraListener(){
    delete move;
    delete wait;

}

void CameraListener::receive(Event* event, float tick){
    KeyboardEvent* key_event = dynamic_cast<KeyboardEvent*>(event);
    if(key_event){
        current->handle_event(this, key_event, tick);
    }
}

void CameraListener::switch_state(){
    if( current == wait){
        current = move;
    }else{
        current = wait;
    }
}
