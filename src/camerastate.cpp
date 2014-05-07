#include "camerastate.h"
//virtual class
CameraState::~CameraState(){}

void CameraState::handle_event(CameraListener* c_listen, KeyboardEvent* k_event, float tick){

}

//CameraStateWait
CameraStateWait::CameraStateWait(){

}

CameraStateWait::~CameraStateWait(){ }

void CameraStateWait::handle_event(CameraListener* c_listen, KeyboardEvent* k_event, float tick){
    int key = k_event->get_key();
    if(key == 290){
        c_listen->switch_state();
    }

}
//CameraStateMove
CameraStateMove::CameraStateMove(Camera* camera_ptr, float move){
    camera = camera_ptr;
    moveSpeed = move;

}

CameraStateMove::~CameraStateMove(){ }

void CameraStateMove::handle_event(CameraListener* c_listen, KeyboardEvent* k_event, float tick){
    int key = k_event->get_key();
    if( key == 'a' ){
        camera->offsetPosition( tick * moveSpeed * -camera->right());
    }else if( key == 'd' ){
        camera->offsetPosition( tick * moveSpeed * camera->right());
    }

    if( key == 's'){
        camera->offsetPosition( tick * moveSpeed * -camera->forward());
    }else if( key == 'w' ){
        camera->offsetPosition( tick * moveSpeed * camera->forward());
    }

    if(key == 290){
        c_listen->switch_state();
    }

}
