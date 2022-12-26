Deterministic Finite Automata(DFA)
Instead of modeling machines directly,
we can create Abstract Models which capture the important aspects
of the Thing we are trying to understand. 
This guid might help to make it clear implementation part.
A very simple Computer Model is a Finite Automaton.
It's represents a computer who has a very small amount of memory.
And look at capability of those kinds of machines.
We can develop a very comprehensive theory.


Model M1: Language (Collection of Strings)
    L(M1) = A = {w|w contains substring "11"}
    M1 Accepts exactly those string in A where:
    A = {w| w contains substring 11}      
    So we say A is the Language of M1 when M1 recognizes A, 
    A = L(M1) 

Model M1: Informal Definition
    Function:
        Input:
            we need 3 Variables<ptrObject>, 
                Bool Inputs Variables are Binary Type;
                    There are finite sequence of these Type Objects as an input to this model;
            We need A = {A set of Accepted states}        
        Output:    
            Input States are Transformed into the Output states by Function named it M1.
            Accept state or Reject state;
        Computation Process(algorithm):
            Begin at start state,
            Reade input symbols,
            Follow corresponding  transitions, 
            Accept if end with accept state
               
Model M1: Formal Definition
    M1 = (Q, Σ, δ, q0, F)
        Q: finite set of states
        Σ: finite set of alphabet symbols
        δ: Q X Σ -> Q
            δ transition function 
            X means Q cross Σ
            you are going to give delta a StateVariable AND an Alphabet Symbol(Char),
            its going to give you back The TransformedStateVariable.            
            Delta, if you give it a State q and Symbol 'a',and it Returns a State r 
            that means q when you read an 'a' goes to r
            δ(q, a) = r 
            Which describes those transitions between states
        q0: is the starting State
        F: A set (unordered_set) of accepting States


Instruction to run the M1:
    g++ main.cpp model.cpp -o main
    ./main
