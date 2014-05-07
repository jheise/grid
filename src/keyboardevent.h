#pragma once
#include "event.h"

class KeyboardEvent: public Event{
    public:
        KeyboardEvent(float);
        ~KeyboardEvent();
        void set_key(int);
        int get_key();
    protected:
        int key;
};
