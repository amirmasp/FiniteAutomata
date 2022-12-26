#ifndef MODEL_H
#define MODEL_H

#include <unordered_set>
#include "state.hpp"

class Model {
    public: 
    Model();
    ~Model();
    void PrintPtrToStates(); 
    void PrintStartAndAcceptedStates();
    bool Run(string sigma);
    void Delete();
   
    private:
    State* Q[3];// vector<State*> Q(3);
    unordered_set<State*> F;
    State* δ(string s); 
    State* currentState; 
};

// Helper Functions
void PrintWelcome();
void SayGoodBye();

#endif
