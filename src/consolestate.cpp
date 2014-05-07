#include "consolestate.h"
ConsoleState::~ConsoleState(){ }

void ConsoleState::handle_event(Console* console, KeyboardEvent* k_event, float tick){ }

void ConsoleState::render(){ }

ConsoleWriteState::ConsoleWriteState(TextObject* textobj, ScriptingEngine* scriptobj){
    text_object = textobj;
    script = scriptobj;
    current = std::string("");
    lastevent = 0;

}

ConsoleWriteState::~ConsoleWriteState(){
}

void ConsoleWriteState::handle_event(Console* console, KeyboardEvent* k_event, float tick){
    //check if key is F1
    int key = k_event->get_key();
    float diff = k_event->get_time() - lastevent;
    lastevent = k_event->get_time();

    if(key == 290){
        console->switch_state();
    }
        //else{
    if(diff > tick * 2.0){
        if(  key > 31 and key < 256){
            current += key;
        }
        if( key == 259 ){
            current = current.substr(0, current.size() - 1);
        }

        if( key == 257 ){
            script->execute_command(current + "\n");
            buffer.push_back(current);
            current = std::string("");
        }
    }
    //}

}

void ConsoleWriteState::render(){
    //text_object->render_text("Hello World", -0.95, 0.83f, 2.0/1366, 2.0/768);
    float startx = -0.95;
    float starty = 0.83;
    for(int i=0; i < buffer.size(); i++){
        text_object->render_text(buffer[i].c_str(), startx, starty, 2.0/1366, 2.0/768);
        starty -= .1;
    }
    text_object->render_text(current.c_str(), startx, starty, 2.0/1366, 2.0/768);
}

ConsoleWaitState::ConsoleWaitState(){

}

ConsoleWaitState::~ConsoleWaitState(){

}

void ConsoleWaitState::handle_event(Console* console, KeyboardEvent* k_event, float tick){
    //check if key is F1
    int key = k_event->get_key();
    if(key == 290){
        console->switch_state();
    }

}

void ConsoleWaitState::render(){ }
