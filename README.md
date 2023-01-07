# Deterministic Finite Automata (DFS)
DFSs are very simple abstract models of machines. Although they are simple but they could demonstrate some strong aspect of machines like doing Parallel Tasks.
You could suppose these machines as a machine with minimum amount of memory. In first model (atmv1), it runs in space comprised of 3 states. Each state is a byte,
can be true or false.
##### Note0: These models can be using for pattern recognition tasks.
## atmv1 Model
3 states.
#### Language of atmv1
`L(atmv1) = A = {w| w contains substring '11'}` 

## atmv2 Model
2 states.
#### Language of atmv2
`L(atmv2) = B = {w| w contains an even number of 1s}`



##### Note1: Machines can handle more than one task simultaneously!
Above models Change state q to state r while Read an character from input.


# DFAs VS NFAs
In above DFA models, there is maximum one state to go when it reads character 'a' from input at the current state.
In NFA(Nondeterministic Finite Automata), there are more than one state to go, like a tree.
