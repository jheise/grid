#pragma once
//C++ libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>

class Event{
    public:
        Event();
        Event(float);

        virtual ~Event();

        float get_time();
        void  set_time(float);

        Event* get_next();

        void set_next(Event*);
    protected:
        Event* next;
        float time;

};
