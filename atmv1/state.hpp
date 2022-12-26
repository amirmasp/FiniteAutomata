#ifndef STATE_H
#define STATE_H

#include <iostream>
using namespace std;
/*
    States in the model M1 can be 
    Accepted OR Rejected, So Binary or Char dataType.
    So each state can be 1 byte.
*/
class State {
    public:
    State() {
        _state = new bool();
    }
    ~State() {
        delete this->_state;
    }
    
    private:
    bool* _state;
};

#endif