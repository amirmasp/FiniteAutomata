#include<iostream>
#include <vector>
#include <string>
#include "model2.hpp"

int main() {

    // At first let's make an unordered_set quit which holds all quit words
    /*unordered_set<string> quits;
    quits.emplace("quit");
    quits.emplace("QUIT");
    quits.emplace("Quit");*/
    
    // Exactly this set has been embedded in the Model M2
    unordered_set<char> sigma;
    sigma.emplace('0');
    sigma.emplace('1');
    
    /* The language B is a set of all Strings who were Accepted by this machine.
     B = {Strings W| string  w has even Number of 1's} 
     If the machin M2 Accepts a Language B, That Lang is Regular Language
     B is L(M2) which is a collection of strings.
     At the end of the day B would be a Language of this machine M2.
    */
    vector<string> B;

    // The Empty String
    string word = "";
  
    // Checking out the M1 by a set of user input Strings sequenc of Σ = {σ0,σ1}
    cout << "Enter your Seguence word (for quit type 'quit' and Enter):\nword = ";
    cin >> word;
    while(word != "quit") {
        bool flagWrongCharacter = false;

        // ErrorChecking: characters are all '0' and '1':
        for (int i = 0; i < word.size(); i++) {
            if (sigma.find(word[i]) == sigma.end()) {
                cout << "You have entered non 0/1 character in the sequence!\n";
                flagWrongCharacter = true;
                break;
            }
        }
        // If sigma is valid       
        if (!flagWrongCharacter) {
            // Create a Model M2 and store it's address in M2
            Model* M2 = new Model();

            // Get return val whether Model M2 has Accepted given word
            // OR Rejected the given word
            bool ans  = M2->Run(word);

            // Check ans out, if true, add it to machine's Language B  
            cout << "Is word  = \"" << word << "\" is Accepted by M2? ";
            if (ans) {
                cout << " true. Thus this given word w could be in  Model M2's language Set B.\n";
                B.push_back(word);
            }
            else {
                cout << " false.Thus this given word w could Not be in Model M2's language Set B.\n";
            }
            
            // Deallocat Memory
            M2->Delete(); 
            cout << "word = ";
            cin >> word;      
        }
        else {
            cout << "Σ = ";
            cin >> word;
        }    
    }
    // We can save B = {w|w has even number of 1's} into a file and label it
    // as language of this machin  
    // L(M2) = B

    return 0;
}