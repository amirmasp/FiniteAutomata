#ifndef STATE_H
#define STATE_H

#include <iostream>
using namespace std;
 /*
    States in the model M1 can be 
    Accepted OR Rejected, So Binary or Char dataType
    So each state can hold 8 bits == 1 byte
    Sure that can hold 8 bits as 1 char as well
    But here our machine language is 0 and 1
    So we need to allocate memory here and return a 
    pointer to that object which is byte here into
*/
// This class is served as a State of Model M1
class State {
    public:
    State() {
        this->_state = new bool();
        //this->state = false;
    }
    ~State() {
       // delete this->_state;
    }
    private:
    // in this model our states can be 0 or 1
    bool* _state;
    //bool state;
};

#endif