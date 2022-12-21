# Initial project plan notes

*Created: 5.11.2022*

Here are some initial notes on/for the project plan, before the format is decided.

A+ has the following instructions on the contents of the plan:

>- Scope of the work: what features and functionalities will be implemented, how is the program used, and how does it work
>- The high-level structure of the software: main modules, main classes (according to current understanding)
>- The planned use of external libraries
>- Division of work and responsibilities between the group members
>- Planned schedule and milestones before the final deadline of the project
>
> **The document should be approx. 5 pages long and contain mandatory diagrams!**

## "Meta" stuff
*Write in here all discussion about the writing and planning process itself*  
Firstly, what is the platform we use?  
Options:
- Markdown
- LaTeX / Overleaf
- Word etc.
- just .txt with CLI Vim :D

How deep into the details do we want to go when planning?
- Minimal: "we get there when we get there"
- Balanced: general outline
- Detailed: plan first, code later


## Initial class hierarchy pseudocode

```
struct Component{
  - internal parts
}

struct Node{
  - list<pair<Node, Component>>
}

class Circuit
 - list<Component> 
 - list<Node> 
 - iterator GetComponent
 - SaveToFile
 - LoadFile

class Simulutor(Circuit&);

class GUI(Circuit&);
```


## Actual contents, project features

*(copy/paste from A+ and notes & discussion thereon)*

### **Basic features**

Directly from A+:
>These features are the minimum requirements for this project. They are worth no points and must be implemented to get a passing grade from the project.
>- Basic components: resistor, capacitor, inductor and a constant voltage source
>- Graphical user interface for building the circuit and showing results (must be able to add, connect, move and remove components and wires)
>- Saving and loading circuits from files
>- RMS voltage and current calculations
>- Basic ready-made circuits for showing the program’s functionalities

Naturally, getting all of this planned and completed should be the first order of business.  
Some notes on the points:  

- "Saving and loading circuits from files" should be integrated from the beginning with "Ability to import schematics from a third party circuit design software".
  - The 3rd party circuit design software in question should be a simple, accessible but commonly used, I (Patrick) put forward "SPICE" (Simulaton Program with Integrated Circuit Emphasis) and the commonly used freeware GUI application LTSpice (one of the most used in the industry, by Analog Devices).
  - LTSpice is a good inspiration for this project, as it has a simple yet funcitonal interface.
- Ready-made circuits are easy to find, found in abundance in any circuit analysis textbook, even better if their model solutions are provided. For example, "Microelectronic Circuits" by Sedra & Smith (probably?) is a good source.
- I (Patrick) would also add an additional "component" which is very important to make more complex circuits more readable: a "node marker", which can be used to give nodes names, which also handily will allow connecting two disconnected nets/circuits together.
  - if this turns out to be very difficult, we can postpone this, but I would say that this is a crucial part of a GUI circuit designer/simulator.


### **Additional features**

Directly from A+:
>Implement some additional features if you’re aiming for a good grade. You can suggest your own additional features if they stay relevant to the project. If so, remember to ask the teaching assistant overseeing your project if the feature would be worth some additional points.
>
>These features below are essential to a basic circuit simulator. Don’t try to implement too many, as every feature listed here is generally worth two points.
>
>- Sinusoidal AC voltage source and sinusoidal AC and constant DC current sources
>- Expand both sources for triangle and square waves. (requires current source)
>- Dependent sources: voltage controller voltage, current controlled voltage, voltage controlled current and current controlled current sources.
>- Time domain graphs for voltage and current
>- Frequency domain graphs for voltage and current
>- Ideal BJT and diode
>- Ideal operational amplifier
>- Ability to import schematics from a third party circuit design software

Some notes:

- While "frequency domain graphs for voltage and current" are useful (for AC analysis), we could ask if we can recieve more points for implementing an utility for generating "bode plots", see e.g. Wikipedia.
  - probably #1 analysis tool for evaluating the AC behaviour of circuits, especially filters.
- That, however, requires implementing Sinusoidal AC sources at least.
- No-one uses BJTs anymore :D if we implement transistors, we will make MOSFETs, because we don't live in the 1900s.

### **Advanced**
Directly from A+:
>These features might offer a challenge. The features are generally worth two or more points.
>- Y and Z parameters for two-port networks
>- Allow abstraction of circuits into blocks and precalculate its properties to make the simulation more efficient
>- Basic microcontroller emulation (run custom code that can read and write to the ports of an IC in the simulation)

Some notes:

- Unless someone feels strongly about any of these, I recommend the abstraction into blocks, as this is what many similar software do, allowing "high-level" design.
    - could, for example, be implemented with system / transfer functions.


### **Suggestions, libraries and external materials**

From A+:
>MNA (Modified Nodal Analysis) is recommended for implementing the solver. It uses linear algebra and involves laplace transforms for the reactive components and fourier transforms for non-sinusoidal signals.  
>
>**Using libraries**  
>
>The GUI isn’t very complicated, so a basic graphics library should be enough.
>
>For solving differential equations, you should use a library instead of writing your own solver. This might save you from a lot of headache.
>
>**Links**
>
>- SFML - a simple multimedia library for graphics and media playback.
>- IMGUI - a simple library for making GUIs easily.
>- IMGUI-SFML - library which allows you to use ImGui with SFML.
>- Qt - an application framework with extended capabilities, like UI features.
>- Odeint - ODE solver library

If someone is familiar with any of these, a take on why / why not.  

As said, SPICE and LTSpice are good sources of inspiration, but as both are decades-old projects we souldn't aspire to nearly the same level with this project.

For circuit Save/Load IO operations, the Netlist should be enough for this scale.  
Basically a txt file with a standard format, which conviniently separates values with whitespaces (easy << and >> operator manipulation) and newlines (e.g. getline() can get one processable item at a time).
