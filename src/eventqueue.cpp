#include "eventqueue.h"

EventQueue::EventQueue(){
    begin   = NULL;
    end     = NULL;
}

EventQueue::~EventQueue(){

}

void EventQueue::push_event(Event* new_event){
    if( begin == NULL){
        begin = new_event;
        end = new_event;
    }else{
        end->set_next(new_event);
        end = new_event;
    }
}

Event* EventQueue::pop_event(){
    Event* retval = begin;
    begin = retval->get_next();
    if( end == retval ){
        end = begin;
    }

    return retval;
}

bool EventQueue::empty(){
    if( begin == NULL and end == NULL){
        return true;
    }
    return false;
}
