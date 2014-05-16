#include "console.h"

Console::Console(ScriptingEngine* eng_ptr){
    write_state = new ConsoleWriteState(eng_ptr);
    wait_state = new ConsoleWaitState();
    current = wait_state;
}

Console::~Console(){

}

void Console::update(float tick){
    current->update(tick);
}

void Console::receive(Event* event, float tick){
    KeyboardEvent* key_event = dynamic_cast<KeyboardEvent*>(event);
    if(key_event){
        current->handle_event(this, key_event, tick);
    }
}

void Console::switch_state(){

    if( current == write_state ){
        current = wait_state;
    }else{
        current = write_state;
    }
}

void Console::render(){
    current->render();
}
