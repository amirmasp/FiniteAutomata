# M1: a Deterministic Finite Automaton (DFA)
Instead of modeling machines directly,
we can create Abstract Models which capture the important aspects
of the Thing we are trying to understand. 
This guid might help to make it clear implementation part.
A very simple Computer Model is a Finite Automaton.
It's represents a computer who has a very small amount of memory.
And let's look at capability of those kinds of machines.
We can develop a very comprehensive theory.


## Model M1: Language (Collection of Strings)
`L(M1) = A = {w|w contains substring "11"}`

M1 Accepts exactly those string in A where that string contains substring '11'.     
Thus we say A is the Language of M1 when M1 recognizes A.


`A = L(M1) `

## Model M1: Informal Definition
#### Function:
##### Input:
- We need 3 Variables<ptrObject>. Bool Inputs Variables are. 

- We need A = {A set of Accepted states}        
##### Output:    
- Input States are Transformed into the Output states by transformer M1.
- Accept state or Reject state;
##### Computation Process(algorithm):
1. Begin at start state.
2. Reade input symbols.
3. Follow corresponding transitions, 
4. Accept if end with accept state
               
## Model M1: Formal Definition
`M1 = (Q, Σ, δ, q0, F)`
- Q: finite set of states
- Σ: finite set of alphabet symbols
- δ: Q X Σ -> Q
- F: A set of accepting States
- q0: is the starting State,
δ is transition function,
X means Q cross Σ.
You are going to give delta a StateVariable and an alphabet symbol, 
its going to give you back The Transformed StateVariable. 


##### Note : `δ(q, a) = r ` means q when you read an 'a' goes to r
            
        
        


## Instruction to run M1 model:
`g++ main.cpp model.cpp -o main`
`./main`
