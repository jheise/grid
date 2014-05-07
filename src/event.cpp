#include "event.h"

Event::Event(){
    time = 0;
    next = NULL;
}

Event::Event(float ctime){
    time = ctime;
}

Event::~Event(){

}

float Event::get_time(){
    return time;
}

void Event::set_time(float ctime){
    time = ctime;
}

Event* Event::get_next(){
    return next;
}

void Event::set_next(Event* newevent){
    next = newevent;
}
