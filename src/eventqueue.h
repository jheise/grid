#pragma once
//C++ libs
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <string>
#include <iostream>

//grid files
#include "event.h"

class EventQueue {
    public:

        EventQueue();

        ~EventQueue();

        void push_event(Event*);

        Event* pop_event();

        bool empty();

    private:
        Event *begin, *end;
};
