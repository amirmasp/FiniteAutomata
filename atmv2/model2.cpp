#include<iostream>
#include "model2.hpp"
using namespace std;

// Initializing The Model M2 using The Constructor of Model
// *****************************************************************************************
Model::Model() {    
    for (int i = 0; i < this->_STATESSIZE; i++) {
        this->Q[i] = new State();
    }
    //  Starts from the state q0
    this->currentState = Q[0];

    // In this particular machine one of the possible answers is what we SET to be an Accept State
    // We based on the design found out q0 is accepted state for this machin M2
    this->F.insert(this->Q[0]);

    // dictionary keeps a finit set of alphabet symbol that this Model recognizes
    this->Σ.emplace('0');// This Model only reconizes '0' and '1' characters symbol
    this->Σ.emplace('1');
}

// Destructor of the Model M1
// *****************************************************************************************
Model::~Model() {
    for (int i = 0; i <this->_STATESSIZE; i++) {
        delete Q[i];
    }
    //cout << "The Model States(memories) are Freed Now : Objected Deleted\n";
}

// transition functionDelta (private member) is implemented inside this Interface
// *****************************************************************************************
bool Model::Run(string w) {   
   // Transform currentState based this input word 
   this->δ(w);
   
   // Now Make a Decision if currentState is in Accepted states Set F
   auto got = this->F.find(this->currentState);
   if (got != this->F.end()) {
        return true;
   }

   return false;
}

// Algorithm Implementation of delta tranision function
// *****************************************************************************************
State* Model::δ(string s) {
    // s is a word given by user
    // Do transformation
    // Make a m x n Matrix       
    // m = Q, n = Σ, so let's see we how to transion?
 
    // Start to Read the given String word
    // Remember: this->currentState Keeps Track the Current State in each itteration
    // this->currentState
    // So Update this->currentState at end of each iteration.
    // Update : Transforming a state to a state(possible itself) Based transition function Table!
    // q0 is Alredy has been initilized to be Q[0]
    for (int i = 0; i < s.size(); i++) {
        cout << "s[" << i << "] = " << s[i] << ", inputState: " << this->currentState; 
        if (this->currentState == this->Q[0]) {
            if (s[i] == '0') {
                this->currentState = this->Q[0];
                cout << ",is transformed to " << this->currentState << endl;
            }
            else {
                this->currentState = this->Q[1];
                cout << ",is transformed to " << this->currentState << endl;
            }
        }
        else if (this->currentState == this->Q[1]) {
            if (s[i] == '0') {
                this->currentState = this->Q[1];
                cout << ",*is transformed to " << this->currentState << endl;
            }
            else {
                this->currentState = this->Q[0];
                cout << ",#is transformed to " << this->currentState << endl;
            }
        }    
    }

    return this->currentState;
}
// *****************************************************************************************
void Model::PrintPtrToStates() {
    for (int i = 0; i < 3; i++) {
        cout << "state q" << i+1 << " address is  " <<  this->Q[i] <<endl;
       // cout << "\tsizeof StateObjects: " <<  sizeof(this->Q[i]) << " Byte"<<endl;       
    }
}
// *****************************************************************************************
void Model::PrintStartAndAcceptedStates() {
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            cout << "address q0 is: " << this->Q[0] << endl;
        }       
        if (this->F.find(this->Q[i]) != this->F.end()) {
            // Then it is a accepted state 
            cout << "Accepted state address is: " << this->Q[i] << endl;

        }      
    }
}
// *****************************************************************************************
void PrintWelcome() {
    cout << "Welcome to your Automaton M1!\n" << endl;
}
// *****************************************************************************************
void SayGoodBye() {
    cout << "Have a Nice Time!\n" << endl;
}
// *****************************************************************************************

void Model::Delete() {
    this->~Model();
}