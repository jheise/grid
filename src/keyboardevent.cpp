#include "keyboardevent.h"

KeyboardEvent::KeyboardEvent(float ctime){
    time = ctime;
    key = 0;
}

KeyboardEvent::~KeyboardEvent(){

}

void KeyboardEvent::set_key(int key_value){
    key = key_value;
}

int KeyboardEvent::get_key(){
    return key;
}
