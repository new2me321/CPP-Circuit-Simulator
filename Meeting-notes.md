# Meeting Notes

# Meeting 6.11.2022 16:30

**Participants**: 
1. Unna
2. Henrik
3. Kwasi
4. Patrick 


## Actions
1. Started devicing the general plan
2. Thought about createing respective GUI classes for each Component
3. Came up with two main components of the project GUI and Solver
4. Decided to use MNA for solver


# Meeting 9.11.2022 14:30

**Participants**: 
1. Unna
2. Henrik
3. Kwasi
4. Patrick 

## Actions
1. Created milestones
2. Discussed how GUI should work with Solver


# Short meeting about the GUI 11.11.2022 14:30

**Participants**: 
1. Henrik
2. Kwasi

## Problems
1. Discussed if we should have a single Component class but decided not to

## Plan
1. GUI specific Component attributes should be exclusively stored in GUI components


# Meeting 16.11.2022 14::15

**Participants**: 
1. Unna
2. Henrik
3. Kwasi
4. Patrick 

## Summary of works
1. Henrik
   
   Initial GUI testing in the look-and-feel branch.

2. Kwasi

   File bases for main component classes.

3. Unna

   Haven't known what to do yet.

4. Patrick

   Documentation to the files made by Kwasi. Reading on MNA.

## Challenges
1. Nothing yet.

2. Problems compiling with WSL

## Actions
1. Start formulating solver skeleton. 
   - 
   - Patrick will look into SPICE implementation.

2. Compiling exclusively for Linux (for now)


## Project status 
### Plan
- Not going to use ImGui. 

Solver class with constructor and methods.
- Parser
   - nodes with connecting elements
   - generates nodes from a list of components
- Formulate equations
   - 3-4 steps
- Solve using values of the copmonents in given time interval // odeint
- Output :) (+ tester)

Every time Solver is called, one instance is created.
Reference to MNA: https://lpsa.swarthmore.edu/Systems/Electrical/mna/MNA3.html


# Meeting 28.11.2022 10::20

**Participants**: 

1. Unna

2. Henrik

3. Kwasi

4. Patrick 

## Summary of works
1. Patrick
   - Pushed initial solver code to master
2. Henrik 
   - Created initial GUI in gui_devel

## Actions
1. No specific GUI components, since it wasn't necessary, only using a ComponentElement with a type member variable

# Short meeting about the Solver 30.11.2022, around 15-18

**Participants**:

1. Patrick

2. Unna

## Summary of works

1. Patrick

   Has written a lot of the Solver base code giving it a structure and started on the definitions.

2. Unna

   Has started reading up on how odeint is actually used, and how we should use it.

## Challenges

1. Adding *just* odeint has turned out to be difficult. **Solution:** add all of the "boost" library to ensure dependencies, also enabling the use of libraries like "uBLAS" (Basic Linear Algebra Subprograms library for C++) for data structures.

2. The order of the solver will depend on what components are included in the circuit, which isn't trivial to determine. Decided to leave the determination to a later date closer to integration.

## Actions

1. odeint components done for next Weekly meeting, hopefully also an interface for GUI and a "run everything".

2. boost library working as a part of the project without issues for everyone.

## Project status

### Plan

- see Actions and Challenges, redundant to repeat here

### TODOs

- Unna: Will code the odeint part of the solver once the library is working

- Patrick: Will continue working on the rest of the Solver, especially parts focusing on its use as part of the program.


# Short meeting about GUI again 30.11.2022 18::36

**Participants**: 

1. Henrik

2. Kwasi

## Summary of works

1. Henrik

   Create memory safe and cleaner codebase for GUI

2. Kwasi

   Created base classes and some definitions, and testing everything works

## Challenges

1. Difficulty adding nodes

2. Using pointers for wires. Decided to use ID references instead of pointers for nodes


## Actions

1. GUI completed by next week (Create Wire functionality and other GUI frontend etc.)

2. Check into frontend connection to backend

## Project status 

### Plan

- No longer going to have seperate GUI files for corresponding components.

- No image for wire, instead use SFML graphics

### TODOs

1. Patrick: Basic methods of the solver (parsing and formulating)

2. Unna: Get familiar with Odeint library and start implementing the solver part of the solver

3. Henrik: Create robust GUI in Master branch

4. Kwasi: Adding extra features such as attach/detach wires, and completing the connection.cpp files



# Meeting 5.12.2022 18::45

**Participants**: 
1. Patrick

2. Henrik

3. Kwasi

## Summary of Works

1. GUI almost done

2. Most of Solver defined

## Plan

1. "Finishing" solver

2. Integrating solver to GUI and creating all the missing GUI features



# Meeting 10.12.2022 17::00

**Participants**:
1. Henrik

2. Kwasi

## Plan

1. Kwasi will create a solver that satisfied requirements (at least dc analyser)

2. Henrik will finish features that are required and other unfinished features (saving, loading, netlist, translating workspace circuit to solver and solving it, displaying output data, integrating solver to GUI)
