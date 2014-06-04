#include "consolestate.h"
ConsoleState::~ConsoleState(){ }

void ConsoleState::handle_event(Console* console, KeyboardEvent* k_event, float tick){ }

void ConsoleState::render(){ }

void ConsoleState::update(float tick){ }

ConsoleWriteState::ConsoleWriteState( ScriptingEngine* scriptobj){
    text_box = new grid::textbox::TextBox(-0.95, 0.95, 256, "Sans bold 18");
    script = scriptobj;
    //current = std::string("");
    lastevent = 0;
    //block = 176;
    block = '%';
    text_box->append(script->get_output());
    text_box->append(&block);
    //std::vector<std::string>strings = split_string(script->get_output(), "\n");
    //for(int i=0; i < strings.size(); i++){
        //buffer.push_back(strings[i]);
    //}

}

ConsoleWriteState::~ConsoleWriteState(){
}

void ConsoleWriteState::handle_event(Console* console, KeyboardEvent* k_event, float tick){
    int key = k_event->get_key();
    float diff = k_event->get_time() - lastevent;
    lastevent = k_event->get_time();

    //check if key is F1
    if(key == 290){
        console->switch_state();
    }

    if(diff > tick * 1.25){
        if(  key > 31 and key < 256){
            current += key;
            text_box->pop_back();
            text_box->append((char*)&key);
            text_box->append(&block);
        }
        if( key == 259 ){
            if(current.length() > 0){
                current.pop_back();
                text_box->pop_back();
                text_box->pop_back();
                text_box->append(&block);
            }
        }

        if( key == 257 ){
            if(current != ""){
                text_box->pop_back();
                text_box->append("\n");
                text_box->append("\n");
                printf("current is '%s'.\n",current.c_str());
                script->execute_command(current + "\n");
                std::string output = script->get_output();
                text_box->pop_back();
                text_box->append(output);
                //text_box->append("\n");
                text_box->append(&block);
                current = std::string("");
            }
        }
    }

}

void ConsoleWriteState::render(){
    //text_object->render_text("Hello World", -0.95, 0.83f, 2.0/1366, 2.0/768);
    //float startx = -0.95;
    //float starty = 0.83;
    //for(int i=0; i < buffer.size(); i++){
    //text_object->render_text(buffer[i].c_str(), startx, starty, 2.0/1366, 2.0/768);
    //starty -= .1;
    //}
    //text_object->render_text(current.c_str(), startx, starty, 2.0/1366, 2.0/768);
    text_box->render();
}

void ConsoleWriteState::update(float tick){
    text_box->update(tick);
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

void ConsoleWaitState::update(float tick){ }
