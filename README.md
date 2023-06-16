# Deterministic Finite Automata (DFS)
A DFS is a simple *abstract model* of a machine. Although they(DFAs) are simple but they could demonstrate some strong aspects of machines like doing parallel tasks(threads).
You could suppose these machines as a machine with minimum amount of memory. In the first model **(atmv1)**, it runs in a space comprised of 3 states. Each state is a byte,
can be true or false. Thus there are 3 possible states for  **atmv1** to run in space `S`.
##### Note0: These models can be using for pattern recognition tasks.
## atmv1 Model
3 states.
#### Language of atmv1
`A = L(atmv1) = {w| w contains substring '11'}` 

## atmv2 Model
2 states.
#### Language of atmv2
`L(atmv2) = B = {w| w contains an even number of 1s}`


# Impressions
Machines can handle more than one task simultaneously!
(**Above models Change state q to state r while reading an character from input**).


# DFAs VS NFAs
In above DFA models, there is maximum one state to go when it reads character 'a' from input at the current state.
In NFA(Nondeterministic Finite Automata), there are more than one state to go,given input character 'a' at the current state.
NFAs act like Tree data structure.
