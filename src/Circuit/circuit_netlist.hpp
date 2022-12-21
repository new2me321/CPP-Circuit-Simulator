#ifndef __CIRCUIT_NETLIST_H__
#define __CIRCUIT_NETLIST_H__

#include "netlist.hpp"
#include "circuit.hpp"

struct ComponentData{
  std::string name;
  std::vector<std::string> pins;
  std::vector<std::string> values;

  bool operator==(const ComponentData& rhs) const;
};

struct CircuitInstructions{
  std::map<std::string, ComponentData> components; // componentName, componentData
  bool loadSuccess = true;

  bool operator==(const CircuitInstructions& rhs) const;
};

bool SaveCircuitInstructions(std::ostream& os, CircuitInstructions instructions);
bool SaveCircuitInstructions(std::string filepath, CircuitInstructions instructions);

CircuitInstructions LoadCircuitInstructions(std::istream& is);
CircuitInstructions LoadCircuitInstructions(std::string filepath);

// void SaveCircuit(Circuit* circuit, std::string filename);

#endif // __CIRCUIT_NETLIST_H__