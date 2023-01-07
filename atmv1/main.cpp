#include<iostream>
#include <vector>
#include <string>
#include "model.hpp"

int main() {
    
    string sigma = "";
    // dictionary keeps all finite set of alphabet symbol
    unordered_set<char> dictionary;
    // In our case dictionary only accepts char '0' and char '1'
    dictionary.emplace('0');
    dictionary.emplace('1');

    // A is L(M1) which is a collection of strings
    // At the end of the day A will be Language of of M1
    vector<string> A;

    PrintWelcome();
       
    cout << "Enter a Seguence of 0s and 1s"\n;
    cout << " (type 'quit' and Enter for quit):\nΣ = ";
    cin >> sigma;

    while(sigma != "quit") {
        bool flagWrongCharacter = false;
        // Check characters are all 0 and 1:
        for (int i = 0; i < sigma.size(); i++) {
            if (dictionary.find(sigma[i]) == dictionary.end()) {
                cout << "You have entered non 0/1 character! Try again!\n";
                flagWrongCharacter = true;
                break;
            }
        }
        if (!flagWrongCharacter) {
            Model* M1 = new Model();
            bool ans  = M1->Run(sigma);
            cout << "Does Σ is a Language of M1? ";
            if (ans) {
                cout << " true.\n";
                A.push_back(sigma);
            }
            else {
                cout << " false.\n";
            }
            
            M1->Delete(); 
            cout << "Σ = ";
            cin >> sigma;      
        }
        else {
            cout << "Σ = ";
            cin >> sigma;
        }    
    }
    SayGoodBye();

    return 0;
}