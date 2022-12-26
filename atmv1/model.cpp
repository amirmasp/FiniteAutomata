#include<iostream>
#include "model.hpp"
using namespace std;

// *****************************************************************************************
Model::Model() {
    this->Q[0] = new State();
    this->Q[1] = new State();
    this->Q[2] = new State();
    this->currentState = Q[0];
    this->F.insert(this->Q[2]);
}
// *****************************************************************************************
Model::~Model() {
    for (int i = 0; i < 3; i++) {
        delete Q[i];
    }
    //cout << "The Model States(memories) are Freed Now : Objected Deleted\n";
}

// transition functionDelta (private member) is implemented inside this Interface
// *****************************************************************************************
bool Model::Run(string Σ) { 
   this->δ(Σ);
   
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
    // Start to Read Input Alphabet
    for (int i = 0; i < s.size(); i++) { 
        if (this->currentState == this->Q[0]) {
            if (s[i] == '0') {
                this->currentState = this->Q[0];
            }
            else {
                this->currentState = this->Q[1];
            }
        }
        else if (this->currentState == this->Q[1]) {
            if (s[i] == '0') {
                this->currentState = this->Q[0];
            }
            else {
                this->currentState = this->Q[2];
            }
        }
        else if (this->currentState == this->Q[2]) {   
            if (s[i] == '0') {
                this->currentState = this->Q[2];
            }
            else {
                this->currentState = this->Q[2];
            }
        }     
    }

    return this->currentState;
}
// *****************************************************************************************
void Model::PrintPtrToStates() {
    for (int i = 0; i < 3; i++) {
        cout << "state q" << i+1 << " address is  " <<  this->Q[i] <<endl;      
    }
}
// *****************************************************************************************
void Model::PrintStartAndAcceptedStates() {
    for (int i = 0; i < 3; i++) {
        if (i == 0) {
            cout << "address q0 is: " << this->Q[0] << endl;
        }       
        if (this->F.find(this->Q[i]) != this->F.end()) {
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