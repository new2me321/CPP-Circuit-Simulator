#include "circuit_netlist.hpp"
#include <string>
#include <algorithm>

template <typename Map>
bool AreMapsEqual(const Map& lhs, const Map& rhs) {
  return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <typename Vector>
bool AreVectorsEqual(const Vector& lhs, const Vector& rhs) {
  auto copy1 = lhs;
  auto copy2 = rhs;
  std::sort(copy1.begin(), copy1.end());
  std::sort(copy2.begin(), copy2.end());
  return lhs.size() == rhs.size() && std::equal(copy1.begin(), copy1.end(), copy2.begin());
}

bool ComponentData::operator==(const ComponentData& rhs) const{
  return
    name == rhs.name &&
    AreVectorsEqual(pins, rhs.pins) &&
    AreVectorsEqual(values, rhs.values);
}

bool CircuitInstructions::operator==(const CircuitInstructions& rhs) const{
  return
    (loadSuccess == rhs.loadSuccess) &&
    AreMapsEqual(components, rhs.components);
}

bool SaveCircuitInstructions(std::ostream& os, CircuitInstructions instructions){
  for(auto& comp : instructions.components){
    os << comp.first;
    
    for(auto& node : comp.second.pins){
      os << " " << node;
    }

    for(auto& value : comp.second.values){
      os << " " << value;
    }

    os << "\n";
  }

  return true;
}

bool SaveCircuitInstructions(std::string filepath, CircuitInstructions instructions){
  std::ofstream os(filepath);
  if(os.fail()){
    std::cout << "Failed to save circuit file to: " << filepath << "\n";
    return false;
  }
  auto result = SaveCircuitInstructions(os, instructions);
  os.close();

  return result;
}

CircuitInstructions LoadCircuitInstructions(std::istream& is){
  CircuitInstructions instructions;
  auto lines = NetlistFile(is).GetAllLines();

  // in the format:
  // V1 1 0 5
  // R2 2 0 220
  // R3 1 2 220

  for(auto& line : lines){
    // skip empty lines and comments
    if(line.size() == 0 || (line.front().size() && line.front().front() == '*')){
      continue;
    }

    // invalid amount of tokens
    if(line.size() < 3){
      // error
      std::cout << "Error loading netlist file. Invalid format." << std::endl;
      instructions.loadSuccess = false;
      return instructions;
    }

    std::string component = line[0];
    std::string node1 = line[1];
    std::string node2 = line[2];

    instructions.components[component].pins = {node1, node2};
    instructions.components[component].values = std::vector<std::string>(line.begin() + 3, line.end());
  }

  instructions.loadSuccess = true;
  return instructions;
}

CircuitInstructions LoadCircuitInstructions(std::string filepath){
  std::ifstream is(filepath);
  if(is.fail()){
    std::cout << "Failed to load circuit file: " << filepath << "\n";
    return {{}, false};
  }
  auto result = LoadCircuitInstructions(is);
  is.close();

  return result;
}
