#include "workspace_netlist.hpp"

void SaveWorkspace(WorkspaceInstructions workspace, std::ostream& os){
  /*
  save components

  format:
  name position:x,y angle:a values:A,B,C

  example:
  R30 position:300.0,200.0 angle:450.0 values:450k
  */ 

  // os << "title here\n\n";
  os << "Components:\n";
  for(auto& comp : workspace.components){
    os << comp.name;
    os << " " << std::to_string(comp.position.x) << "," << std::to_string(comp.position.y);
    os << " " << std::to_string(comp.angle);
    os << " ";
    for(size_t i=0; i<comp.values.size(); i++){
      if(i != 0)
        os << ",";
      os << comp.values[i];
    }
    os << "\n";
  }

  /*
  save nodes

  format:
  nodeId x y

  example:
  391 320.0 400.0
  */
  os << "\nNodes:\n";
  for(auto& node : workspace.nodes){
    os << std::to_string(node.node_id) << " " << std::to_string(node.position.x) << " " << std::to_string(node.position.y) << "\n";
  }

  /*
  save wires

  format
  nodeId1 nodeId2
  */
  os << "\nWires:\n";
  for(auto& node : workspace.wires){
    os << node.node1_id << " " << node.node2_id << "\n";
  }
}

void SaveWorkspace(WorkspaceInstructions workspace, std::string filename){
  std::ofstream os(filename);
  if(os.fail()){
    return;
  }
  SaveWorkspace(workspace, os);
  os.close();
}

WorkspaceInstructions LoadWorkspaceInstructions(std::istream& is){
  auto GetCommaSeperatedTokens = [](const std::string& str){
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string token;

    while(std::getline(ss, token, ',')){
      result.push_back(token);
    }

    return result;
  };

  WorkspaceInstructions instructions;
  auto lines = NetlistFile(is).GetAllLines();

  enum {
    Start = 0,
    Components,
    Nodes,
    Wires
  } currentLoadState = Start;

  // in the format:
  // V1 1 0 5
  // R2 2 0 220
  // R3 1 2 220

  for(auto& line : lines){
    // skip empty lines and comments
    if(line.size() == 0 || (line.front().size() && line.front().front() == '*')){
      continue;
    }

    // set new state and continue to next loop iteration
    if(line[0] == "Components:"){ currentLoadState = std::max(currentLoadState, Components); continue; }
    if(line[0] == "Nodes:")     { currentLoadState = std::max(currentLoadState, Nodes);      continue; }
    if(line[0] == "Wires:")     { currentLoadState = std::max(currentLoadState, Wires);      continue; }

    // check valid amount of tokens
    if(
      (currentLoadState == Components && line.size() != 4) ||
      (currentLoadState == Nodes && line.size() != 3) ||
      (currentLoadState == Wires && line.size() != 2)
    ){
      instructions.loadSuccess = false;
      return instructions;
    }

    // load line depending on what state loader currently in
    switch(currentLoadState){
      case Components:{
        ComponentElementInstructions compInstructions;
        compInstructions.name = line[0];
        compInstructions.angle = std::stof(line[2]);
        compInstructions.values = GetCommaSeperatedTokens(line[3]);
        compInstructions.type = GetComponentElementTypeFromName(line[0]);

        auto pos = GetCommaSeperatedTokens(line[1]);
        if(pos.size() != 2){
          instructions.loadSuccess = false;
          return instructions;
        }
        compInstructions.position.x = std::stof(pos[0]);
        compInstructions.position.y = std::stof(pos[1]);

        instructions.components.push_back(compInstructions);
        break;
      }
      case Nodes:{
        WireNodeInstructions nodeInstructions;
        nodeInstructions.node_id = std::stoul(line[0]);
        nodeInstructions.position.x = std::stof(line[1]);
        nodeInstructions.position.y = std::stof(line[2]);

        instructions.nodes.push_back(nodeInstructions);
        break;
      }
      case Wires:
        WireElementInstructions wireInstructions;
        wireInstructions.node1_id = std::stoul(line[0]);
        wireInstructions.node2_id = std::stoul(line[1]);

        instructions.wires.push_back(wireInstructions);
        break;
      default:
        break;
    }

  }

  instructions.loadSuccess = true;
  return instructions;
}

WorkspaceInstructions LoadWorkspaceInstructions(std::string filepath){
  std::ifstream is(filepath);
  if(is.fail()){
    return {{}, {}, {}, false};
  }
  auto instructions = LoadWorkspaceInstructions(is);
  is.close();

  return instructions;
}
