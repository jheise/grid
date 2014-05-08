#include "keyboardhandler.h"

KeyboardHandler::KeyboardHandler(EventQueue* queue_ptr){
    queue = queue_ptr;
    f1hit = false;
}

KeyboardHandler::~KeyboardHandler(){

}

void KeyboardHandler::handle_input(){
    float tick = glfwGetTime();

    //all letters
    if(glfwGetKey('A')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('A');
        }else{
            new_key->set_key('a');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('B')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('B');
        }else{
            new_key->set_key('b');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('C')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('C');
        }else{
            new_key->set_key('c');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('D')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('D');
        }else{
            new_key->set_key('d');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('E')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('E');
        }else{
            new_key->set_key('e');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('F')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('F');
        }else{
            new_key->set_key('f');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('G')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('G');
        }else{
            new_key->set_key('g');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('H')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('H');
        }else{
            new_key->set_key('h');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('I')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('I');
        }else{
            new_key->set_key('i');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('J')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('J');
        }else{
            new_key->set_key('j');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('K')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('K');
        }else{
            new_key->set_key('k');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('L')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('L');
        }else{
            new_key->set_key('l');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('M')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('M');
        }else{
            new_key->set_key('m');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('N')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('N');
        }else{
            new_key->set_key('n');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('O')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('O');
        }else{
            new_key->set_key('o');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('P')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('P');
        }else{
            new_key->set_key('p');
        }
        queue->push_event(new_key);
    }


   if(glfwGetKey('Q')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('Q');
        }else{
            new_key->set_key('q');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('R')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('R');
        }else{
            new_key->set_key('r');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('S')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('S');
        }else{
            new_key->set_key('s');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('T')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('T');
        }else{
            new_key->set_key('t');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('U')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('U');
        }else{
            new_key->set_key('u');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('V')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('V');
        }else{
            new_key->set_key('v');
        }
        queue->push_event(new_key);
    }


    if(glfwGetKey('W')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('W');
        }else{
            new_key->set_key('w');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('X')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('X');
        }else{
            new_key->set_key('x');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('Y')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('Y');
        }else{
            new_key->set_key('y');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('Z')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('Z');
        }else{
            new_key->set_key('z');
        }
        queue->push_event(new_key);
    }

    //special keys
    if(glfwGetKey(GLFW_KEY_ESC)){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        new_key->set_key(27);
        queue->push_event(new_key);
    }

    if(glfwGetKey(GLFW_KEY_BACKSPACE)){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        new_key->set_key(259);
        queue->push_event(new_key);
    }

    if(glfwGetKey(GLFW_KEY_SPACE)){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        new_key->set_key(32);
        queue->push_event(new_key);
    }

    if(glfwGetKey(GLFW_KEY_ENTER)){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        new_key->set_key(257);
        queue->push_event(new_key);
    }

    if(glfwGetKey('=')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('+');
        }else{
            new_key->set_key('=');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('-')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('_');
        }else{
            new_key->set_key('-');
        }
        queue->push_event(new_key);
    }
    if(glfwGetKey('1')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('!');
        }else{
            new_key->set_key('1');
        }
        queue->push_event(new_key);
    }
    if(glfwGetKey('2')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('@');
        }else{
            new_key->set_key('2');
        }
        queue->push_event(new_key);
    }
    if(glfwGetKey('3')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('#');
        }else{
            new_key->set_key('3');
        }
        queue->push_event(new_key);
    }
    if(glfwGetKey('4')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('$');
        }else{
            new_key->set_key('4');
        }
        queue->push_event(new_key);
    }
    if(glfwGetKey('5')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('%');
        }else{
            new_key->set_key('5');
        }
        queue->push_event(new_key);
    }
    if(glfwGetKey('6')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('^');
        }else{
            new_key->set_key('6');
        }
        queue->push_event(new_key);
    }
    if(glfwGetKey('7')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('&');
        }else{
            new_key->set_key('7');
        }
        queue->push_event(new_key);
    }
    if(glfwGetKey('8')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('*');
        }else{
            new_key->set_key('8');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('9')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('(');
        }else{
            new_key->set_key('9');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('0')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key(')');
        }else{
            new_key->set_key('0');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('`')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('~');
        }else{
            new_key->set_key('`');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey(',')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('<');
        }else{
            new_key->set_key(',');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('\'')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('"');
        }else{
            new_key->set_key('\'');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('.')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('>');
        }else{
            new_key->set_key('.');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('/')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('?');
        }else{
            new_key->set_key('/');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('[')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('{');
        }else{
            new_key->set_key('[');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey(']')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('}');
        }else{
            new_key->set_key(']');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey('\\')){
        KeyboardEvent* new_key = new KeyboardEvent(tick);
        if(glfwGetKey(GLFW_KEY_LSHIFT) or glfwGetKey(GLFW_KEY_RSHIFT)){
            new_key->set_key('|');
        }else{
            new_key->set_key('\\');
        }
        queue->push_event(new_key);
    }

    if(glfwGetKey(GLFW_KEY_F1)){
        if( !f1hit ){
            KeyboardEvent* new_key = new KeyboardEvent(tick);
            new_key->set_key(290);
            //new_key->set_key(GLFW_KEY_F1);
            queue->push_event(new_key);
            f1hit = true;
        }
    }else{
        f1hit = false;
    }

}
