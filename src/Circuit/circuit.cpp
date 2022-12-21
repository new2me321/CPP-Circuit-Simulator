#include "circuit.hpp"

#include "Circuit/component.hpp"
#include "Circuit/resistor.hpp"
#include "Circuit/inductor.hpp"
#include "Circuit/capacitor.hpp"
#include "Circuit/voltage_source.hpp"

Circuit::Circuit() {}
Circuit::~Circuit(){
  this->ClearCircuit();
}

void Circuit::AddComponent(Component *c) { components_.push_back(c); }

void Circuit::Print()
{
  std::cout << "The circuit has the following components:" << std::endl;
  for (auto i = components_.begin(); i != components_.end(); ++i)
  {
    std::cout << "name: " << (*i)->GetName() << " value: " << (*i)->GetValue() << std::endl;
  }

  std::cout << "Nodes before connecting components..." << std::endl;
  for (auto &comp : components_)
  {
    std::cout << "Nodes on " << comp->GetName() << " are: " << comp->GetNode1() << " " << comp->GetNode2() << std::endl;
  }

  std::cout << "------------Validating nodes------------ " << std::endl;
  std::cout << "Nodes count: " << GetNodes().size() << std::endl;

  for (auto n : nodes_)
  {
    std::cout << "Is " << n.first << " GND? " << n.second->IsGND() << std::endl;
  }
}

void Circuit::ClearCircuit()
{
  for (auto p : nodes_)
  {
    delete p.second;
  }
  for (auto p : components_)
  {
    delete p;
  }

  nodes_.clear();
  components_.clear();
  connected_components_.clear();
  connected_nodes_.clear();
  connected_pins_.clear();
  idCounter_ = 0;

  // std::cout << "Circuit cleared!" << std::endl;
}

const Node *Circuit::AddNode(const std::string &node_name)
{
  bool isDuplicate = false;
  std::string n_name = node_name;
  try
  {
    for (auto n : nodes_)
    {
      if (n.second->GetID() == node_name) // check if node already exists
      {
        isDuplicate = true;
        throw std::invalid_argument("Error: Duplicate node found!");
      }
    }
  }
  catch (const std::invalid_argument &e) // caught by reference to base
  {
    std::cout << e.what() << "'\n";
    std::cout << "Generating a unique node ID instead..." << std::endl;
  }

  // if (isDuplicate)
  // {
  //   std::string uniq_name = "N";
  //   uniq_name += GetUniqueId();
  //   for (auto n : connected_nodes_)
  //   {
  //     while (n.first->GetID() == uniq_name)
  //     {
  //       uniq_name += GetUniqueId();
  //     }
  //   }
  //   n_name = uniq_name;
  //   nodes_[n_name] = new Node(n_name);
  // }
  // else
  {
    auto it = nodes_.find(n_name);
    if (it == nodes_.end())
    {
      nodes_[n_name] = new Node(n_name);
    }
  }
  return nodes_[n_name];
}

std::list<Node> Circuit::GetNodes() const
{
  std::list<Node> ret_list;
  for (auto it : nodes_)
  {
    ret_list.push_back(*it.second);
  }

  // Make sure GND is last term
  std::list<Node> temp_list;
  bool found = false;
  for (auto n = ret_list.begin(); n != ret_list.end(); ++n)
  {
    if (n->GetID() != "GND")
    {
      temp_list.push_back(*n);
    }
  }
  for (auto n = ret_list.begin(); n != ret_list.end(); ++n)
  {
    if (n->GetID() == "GND")
    {
      temp_list.push_back(*n);
      found = true;
    }
  }
  if (found)
  {
    ret_list = temp_list;
  }
  return ret_list;
}

void Circuit::RemoveNode(const std::string &node_name)
{
  nodes_.erase(node_name);
}

void Circuit::ConnectComponent(Component *src, TerminalPin srcPin, Component *target, TerminalPin targetPin)
{

  std::pair<Component *, TerminalPin> key;
  key.first = src;
  key.second = srcPin;
  connected_components_.push_back(target);

  for (auto i = connected_pins_.begin(); i != connected_pins_.end(); ++i)
  {
    if (i->first.first->GetName() == key.first->GetName() && i->first.second == key.second)
    {
      i->second.push_back(target);
    }
  }
  connected_pins_.emplace(make_pair(key, connected_components_));

  auto targetNode = targetPin == pinA ? target->GetNode1() : target->GetNode2();
  auto sourceNode = srcPin == pinA ? src->GetNode1() : src->GetNode2();

  if (srcPin == pinA)
  {
    src->SetNode1(targetNode);
  }
  else
  {
    src->SetNode2(targetNode);
  }

  // update nodes container
  for (auto c : components_)
  {
    if (sourceNode == c->GetNode1())
    {
      c->SetNode1(targetNode);
    }
    if (sourceNode == c->GetNode2())
    {
      c->SetNode2(targetNode);
    }
  }

  Node *node = new Node(targetNode);
  connected_nodes_[node] = connected_components_;
  nodes_[node->GetID()] = node;

  // Clear the vector
  connected_components_.clear();
}

void Circuit::PrintAll()
{
  std::cout << "The connections between the components:" << std::endl;
  for (auto i = connected_pins_.begin(); i != connected_pins_.end(); ++i)
  {
    std::cout << (*i).first.first->GetName() << " connects at pin";
    switch ((*i).first.second)
    {
    case pinA:
      std::cout << "A with " << std::endl;
      break;
    case pinB:
      std::cout << "B with " << std::endl;
      break;

    default:
      break;
    }

    for (auto j = (*i).second.begin(); j != (*i).second.end(); ++j)
    {
      std::cout << (*j)->GetName() << std::endl;
    }
  }
}

void Circuit::ConnectGround(Component *target, TerminalPin targetPin)
{
  auto targetNode = targetPin == pinA ? target->GetNode1() : target->GetNode2();
  std::map<std::pair<std::string, std::string>, Component *> node_pairs_;
  for (auto c : this->GetComponents())
  {
    node_pairs_.emplace(std::make_pair(std::make_pair(c->GetNode1(), c->GetNode2()), c));
  }

  //  update component nodes
  for (auto np : node_pairs_)
  {
    if (np.first.first == targetNode || np.first.second == targetNode)
    {
      if (targetPin == pinA)
      {
        np.second->SetNode1("GND");
      }
      else
      {
        np.second->SetNode2("GND");
      }
    }
  }

  // update nodes container
  for (auto n : nodes_)
  {
    if (targetNode == n.first)
    {
      n.second->SetGND();
      n.second->SetID("GND");
    }
  }
}
std::string Circuit::GetUniqueId()
{
  std::ostringstream os;
  os << idCounter_++;
  return os.str();
}

CircuitInstructions Circuit::CreateInstruction() const
{
  CircuitInstructions instructions;

  for (auto &comp : components_)
  {
    ComponentData compData;

    compData.pins.push_back(comp->GetNode1());
    compData.pins.push_back(comp->GetNode2());
    compData.values.push_back(std::to_string(comp->GetValue()));

    instructions.components[comp->GetName()] = compData;
  }

  return instructions;
}

void Circuit::ConstructFromInstructions(CircuitInstructions instructions)
{
  ClearCircuit();

  auto ConvertStringToValue = [](std::string value)
  {
    return std::stof(value);
  };

  if (!instructions.loadSuccess)
  {
    std::cout << "Warning: Loading potentially incorrect circuit.\n";
  }

  // Add all components
  for (auto &componentInstructions : instructions.components)
  {
    auto compName = componentInstructions.first;

    if (componentInstructions.second.pins.size() != 2)
    {
      std::cout << "Warning: Loading component without exactly 2 pins, not implemented. Skipping.\n";
      continue;
    }

    auto nodeId1 = componentInstructions.second.pins[0];
    auto nodeId2 = componentInstructions.second.pins[1];

    auto &allValues = componentInstructions.second.values;
    auto value = allValues.size() ? allValues[0] : "0";

    auto compTypeChar = compName[0];
    Component *component = nullptr;
    switch (compTypeChar)
    {
    case 'R':
      component = new Resistor(compName, ConvertStringToValue(value));
      break;
    case 'L':
      component = new Inductor(compName, ConvertStringToValue(value));
      break;
    case 'C':
      component = new Capacitor(compName, ConvertStringToValue(value));
      break;
    case 'V':
      component = new DCVoltageSource(compName, ConvertStringToValue(value));
      break;
    }

    if (!component)
    {
      std::cout << "Error: Loading component of unknown type.: " << compName << "\n";
      break;
    }

    // find if nodes exist already
    auto node1_count = std::count_if(nodes_.begin(), nodes_.end(), [&nodeId1](auto &node)
                                     { return node.second->GetID() == nodeId1; });
    auto node2_count = std::count_if(nodes_.begin(), nodes_.end(), [&nodeId2](auto &node)
                                     { return node.second->GetID() == nodeId2; });

    // create nodes in case they dont exist
    if (node1_count == 0)
    {
      Node *node = new Node("");
      node->SetID(nodeId1 == "0" ? "GND" : nodeId1);
      if (nodeId1 == "0")
      {
        node->SetGND();
        nodeId1 = "GND";
      }
      nodes_.emplace(node->GetID(), node);
    }
    if (node2_count == 0)
    {
      Node *node = new Node("");
      node->SetID(nodeId2 == "0" ? "GND" : nodeId2);
      if (nodeId2 == "0")
      {
        node->SetGND();
        nodeId2 = "GND";
      }
      nodes_.emplace(node->GetID(), node);
    }

    component->SetNode1(nodeId1);
    component->SetNode2(nodeId2);
    AddComponent(component);
  }
}
