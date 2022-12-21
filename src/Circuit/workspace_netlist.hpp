#ifndef __WORKSPACE_NETLIST_H__
#define __WORKSPACE_NETLIST_H__

#include "netlist.hpp"
#include "../GUI/workspace.hpp"
#include "../GUI/component_type.hpp"

struct ComponentElementInstructions{
  std::string name;
  ComponentTypeGUI type;
  sf::Vector2f position;
  float angle;
  std::vector<std::string> values;
};

struct WireNodeInstructions{
  unsigned node_id;
  sf::Vector2f position;
};

struct WireElementInstructions{
  unsigned node1_id, node2_id;
};

struct WorkspaceInstructions{
  std::vector<ComponentElementInstructions> components;
  std::vector<WireNodeInstructions>         nodes;
  std::vector<WireElementInstructions>      wires;

  bool loadSuccess = true;
};

void SaveWorkspace(WorkspaceInstructions workspace, std::ostream& os);
void SaveWorkspace(WorkspaceInstructions workspace, std::string filename);

WorkspaceInstructions LoadWorkspaceInstructions(std::istream& is);
WorkspaceInstructions LoadWorkspaceInstructions(std::string filepath);

#endif // __WORKSPACE_NETLIST_H__