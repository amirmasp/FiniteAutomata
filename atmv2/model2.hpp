#ifndef MODEL_H
#define MODEL_H

#include<unordered_set>
#include "state.hpp"

/* M2 = (Q, Σ, δ, q0, F) 
    Q: A Finite Set of States, Q = {q0,q1}, n = 2
    Σ: is given byModel::Run(sigma) // Could be Variable
    F: is a set of accepted States, F = {q0} // Could be Variable
    &: Q X Σ -> Q (We have designed this transition function table)
    q0: Q[0]
*/
// This Model will be instantiated as an Model Object
class Model {
    public: 
    Model();
    ~Model();
    void PrintPtrToStates(); 
    void PrintStartAndAcceptedStates();
    bool Run(string sigma);
    void Delete();
    
    private:
    // int statesNumber;// This is not possible because 
    // the size of an array Q  must be determined before compile.
    static const int _STATESSIZE = 2; // in this machine M2 we have 2 states
    State* Q[_STATESSIZE];// This could be vector<State*> Q(2);
    unordered_set<State*> F;// F is a Variable that is {q0} in this Model
    State* δ(string s); 
    State* currentState; 
    unordered_set<char> Σ;
    

};

// Helper Functions
void PrintWelcome();
void SayGoodBye();


#endif
