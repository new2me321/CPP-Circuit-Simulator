#ifndef CIRCUIT_SIMULATOR_COMPONENT_CIRCUIT_H_
#define CIRCUIT_SIMULATOR_COMPONENT_CIRCUIT_H_

#include <list>
#include <memory>
#include <sstream>
#include "component.hpp"
#include "node.hpp"
#include <algorithm>
#include "../Circuit/circuit_netlist.hpp"

#include <algorithm>

class CircuitInstructions;

class Circuit
{
public:
  Circuit();
  ~Circuit();

  void ConstructFromInstructions(CircuitInstructions instructions);
  CircuitInstructions CreateInstruction() const;

  // methods
  void AddComponent(Component *c);                   // add a component to the circuit
  void Print();                                      // prints circuit
  void ClearCircuit();                               // clears the circuit
  const Node *AddNode(const std::string &node_name); // adds a node to the circuit
  void RemoveNode(const std::string &node_name);     // removes a node from the circuit
  void ConnectComponent(Component *src, TerminalPin srcPin, Component *target, TerminalPin targetPin);
  void PrintAll(); // prints connections between all connected components
  std::list<Node> GetNodes() const;
  std::list<Component *> GetComponents() const { return components_; }
  void ConnectGround(Component *target, TerminalPin targetPin);

private:
  // nodes
  std::map<std::string, Node *> nodes_;
  std::map<Node *, std::vector<Component *>> connected_nodes_;

  // components
  std::list<Component *> components_;
  std::vector<Component *> connected_components_;

  // holds the connected components and to which pin they are connected together.
  std::map<std::pair<Component *, TerminalPin>, std::vector<Component *>> connected_pins_;

  // generates a unique name ID
  int idCounter_ = 1;
  std::string GetUniqueId();
};

#endif