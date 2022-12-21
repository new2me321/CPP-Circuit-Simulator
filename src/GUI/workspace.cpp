#include "workspace.hpp"

#include "wire_element.hpp"
#include "text_field_element.hpp"
#include <iostream>
#include <math.h>
#include <algorithm>

#include "../Circuit/component.hpp"
#include "../Circuit/resistor.hpp"
#include "../Circuit/capacitor.hpp"
#include "../Circuit/inductor.hpp"
#include "../Circuit/voltage_source.hpp"
#include "../Circuit/node.hpp"

Workspace::Workspace(const sf::Texture& componentTexture, std::shared_ptr<ComponentMenu> menu, const sf::Font& font, int fontsize):
  font_(font),
  fontsize_(fontsize),
  componentMenu_(menu),
  componentTexture_(componentTexture)
{
  wires_.SetRelativePosition(this->GetPosition());
  wireNodes_.SetRelativePosition(this->GetPosition());
  components_.SetRelativePosition(this->GetPosition());

  RegenerateGrid();
}

Workspace::~Workspace() {
}

sf::Vector2f Workspace::GetSize() const {
  return Element::GetSize();
}

void Workspace::Draw(sf::RenderWindow& window) const {
  window.draw(background_);
  window.draw(gridVertices_.data(), gridVertices_.size(), sf::Lines);

  wires_.Draw(window);
  wireNodes_.Draw(window);
  components_.Draw(window);
}

void Workspace::HandleEvent(const sf::Event& event) {
  switch(event.type){
    case sf::Event::MouseButtonPressed:{
      sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
      // mouse click inside workspace
      if(event.mouseButton.button == sf::Mouse::Button::Left) LeftClick(mousePosition);
      if(event.mouseButton.button == sf::Mouse::Button::Right) RightClick(mousePosition);
      break;
    }
    case sf::Event::MouseButtonReleased:{
      sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
      if(event.mouseButton.button == sf::Mouse::Button::Left) LeftRelease(mousePosition);
      break;
    }
    case sf::Event::MouseMoved:{
      sf::Vector2f mousePosition = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
      MouseMove(mousePosition);
      break;
    }
    case sf::Event::TextEntered:{
      if(AnyTextFieldSelected()){
        components_.HandleEvent(event);
      }
      break;
    }
    case sf::Event::KeyPressed:{
      if(!AnyTextFieldSelected()){
        if(event.key.code == sf::Keyboard::Key::R){
          RotateEvent();
        }
        if(event.key.code == sf::Keyboard::Key::Delete){
          DeleteEvent();
        }
        if(event.key.code == sf::Keyboard::Key::Escape){
          ClearMenuEvent();
        }
        if(event.key.code == sf::Keyboard::Key::LShift){
          componentMenu_->SetSelectedComponentType(ComponentTypeGUI::Wire);
          isSelectedDragged_ = false;
        }
      }

      break;
    }
    case sf::Event::KeyReleased:{
      if(event.key.code == sf::Keyboard::Key::LShift){
        componentMenu_->SetSelectedComponentType(ComponentTypeGUI::None);
      }
      break;
    }
    default:
      break;
  }
}

void Workspace::Update() {
  wires_.Update();
  wireNodes_.Update();
  components_.Update();
}

void Workspace::RegenerateGrid() {
  gridVertices_.clear();

  // how many lines is there in x and y directions
  int gridW = this->GetSize().x / gridLineInterval_ + 1;
  int gridH = this->GetSize().y / gridLineInterval_ + 1;

  // vertical lines
  for(int i=0; i<gridW; i++){
    sf::Vertex vertex1(sf::Vector2f(this->GetPosition().x + i * gridLineInterval_, this->GetPosition().y), gridColor_);
    sf::Vertex vertex2(sf::Vector2f(this->GetPosition().x + i * gridLineInterval_, this->GetPosition().y + this->GetSize().y), gridColor_);

    gridVertices_.push_back(vertex1);
    gridVertices_.push_back(vertex2);
  }

  // horisontal lines
  for(int i=0; i<gridH; i++){
    sf::Vertex vertex1(sf::Vector2f(this->GetPosition().x, this->GetPosition().y + i * gridLineInterval_), gridColor_);
    sf::Vertex vertex2(sf::Vector2f(this->GetPosition().x + this->GetSize().x, this->GetPosition().y + i * gridLineInterval_), gridColor_);

    gridVertices_.push_back(vertex1);
    gridVertices_.push_back(vertex2);
  }
}

void Workspace::SetPosition(sf::Vector2f position) {
  Element::SetPosition(position);
  UpdateBackground();
  RegenerateGrid();
  
  wireNodes_.SetRelativePosition(this->GetPosition());
  components_.SetRelativePosition(this->GetPosition());
}

void Workspace::SetSize(sf::Vector2f size) {
  Element::SetSize(size);
  UpdateBackground();
  RegenerateGrid();
}

void Workspace::UpdateBackground() {
  background_.setSize(this->GetSize());
  background_.setPosition(this->GetPosition());
  background_.setFillColor(backgroundColor_);
}

bool Workspace::GetElementWithId(unsigned id, Element*& element) const{
  if(wireNodes_.GetElementWithId(id, element)) return true;
  if(components_.GetElementWithId(id, element)) return true;

  element = nullptr;
  return false;
}

void Workspace::LeftClick(sf::Vector2f mousePosition) {
  // return if not inside workspace
  if(!this->GetBoundRect().contains(mousePosition))
    return;

  auto type = componentMenu_->GetSelectedComponentType();
  switch(type){
    case ComponentTypeGUI::None:{
      auto nodes = wires_.GetElementsThatContain(mousePosition);
      auto components = components_.GetElementsThatContain(mousePosition);

      if(nodes.size()){
        isSelectedDragged_ = true;
        selectedComponentId_ = nodes.front();
      }
      else if(components.size()){
        isSelectedDragged_ = true;
        selectedComponentId_ = components.front();

        // if its a component, set boundary visible
        if(Element* element = nullptr; components_.GetElementWithId(selectedComponentId_, element)){
          dynamic_cast<ComponentElement*>(element)->SetBoundaryVisible(true);
        }
      }
      break;
    }
    case ComponentTypeGUI::Wire:
      selectedComponentId_ = CreateWire(mousePosition);
      isSelectedDragged_ = true;
      break;
    default:
      selectedComponentId_ = CreateComponent(type, mousePosition);
      isSelectedDragged_ = true;
      componentMenu_->SetSelectedComponentType(ComponentTypeGUI::None);
      break;
  }
}

void Workspace::RightClick(sf::Vector2f mousePosition) {
  // return if not inside workspace
  if(!this->GetBoundRect().contains(mousePosition))
    return;

  // clear selection
  for(auto& child : componentTextFields_){
    child->SetSelected(false);
  }

  // set selected if clicked on 
  for(auto& child : componentTextFields_){
    if(!child->GetElementsThatContain(mousePosition).size() || !child->IsVisible())
      continue;

    child->SetSelected(true);
  }

  // if no text field is active, look for components and toggle their text field
  if(!AnyTextFieldSelected()){
    auto components = components_.GetElementsThatContain(mousePosition);

    if(components.size()){
      // pick first
      unsigned componentID = components.front();

      Element* element;
      if(components_.GetElementWithId(componentID, element)){
        ComponentElement* component = dynamic_cast<ComponentElement*>(element);
        component->ToggleTextFieldVisibility();
      }
    }
  }
}

void Workspace::LeftRelease(sf::Vector2f) {
  Element* element = nullptr;
  if(components_.GetElementWithId(selectedComponentId_, element)){
    // selected is a component, unset boundary
    dynamic_cast<ComponentElement*>(element)->SetBoundaryVisible(false);
  }

  else if(isSelectedDragged_ && wires_.GetElementWithId(selectedComponentId_, element)){
    // selected is a wire

    // check for other nodes
    // CombineWireNodesWithSamePosition();
  }

  isSelectedDragged_ = false;
}

void Workspace::MouseMove(sf::Vector2f mousePosition) {
  Element* element = nullptr;
  if(isSelectedDragged_ && GetElementWithId(selectedComponentId_, element)){
    element->SetGlobalPosition(ClampToGrid(mousePosition));
  }
}

sf::Vector2f Workspace::ClampToGrid(sf::Vector2f position) const {
  auto rect = GetBoundRect();

	return sf::Vector2f(
		int((std::clamp(position.x, rect.left + gridLineInterval_, rect.left + rect.width  - + gridLineInterval_) - GetPosition().x) / gridLineInterval_ + 0.5) * gridLineInterval_,
		int((std::clamp(position.y, rect.top  + gridLineInterval_, rect.top  + rect.height - + gridLineInterval_) - GetPosition().y) / gridLineInterval_ + 0.5) * gridLineInterval_
	) + GetPosition();
}

unsigned Workspace::CreateComponent(ComponentTypeGUI type, sf::Vector2f globalPosition) {
  auto textField_ = std::make_shared<TextFieldElement>("3.0", font_, fontsize_, ComponentTypeToString(type) + "(", ")");
  textField_->SetOutlineThickness(-1);
  textField_->SetPaddingScale(0.5);
  textField_->SetCentered(true);
  textField_->SetPosition(sf::Vector2f(0, -2.f*gridLineInterval_));
  textField_->SetVisibility(false);

  auto comp = std::make_shared<ComponentElement>(componentTexture_, type, textField_);
  comp->SetBoundaryVisible(false);
  comp->SetPinsVisibility(true);
  comp->SetSize(componentSize_);
  comp->SetOriginToCenter();
  comp->SetRelativePosition(GetPosition());
  comp->SetGlobalPosition(ClampToGrid(globalPosition));

  components_.AddChild(comp);
  componentTextFields_.push_back(textField_);

  return comp->GetID();
}

unsigned Workspace::CreateWire(sf::Vector2f startGlobalPosition){
  auto node1 = std::make_shared<WireNode>(sf::Vector2f(0.f, 0.f));
  auto node2 = std::make_shared<WireNode>(sf::Vector2f(0.f, 0.f));
  node1->SetRelativePosition(GetPosition());
  node2->SetRelativePosition(GetPosition());
  node1->SetGlobalPosition(ClampToGrid(startGlobalPosition));
  node2->SetGlobalPosition(ClampToGrid(startGlobalPosition));
  wireNodes_.AddChild(node1);
  wireNodes_.AddChild(node2);

	auto wire = std::make_shared<WireElement>(node1, node2);
	wires_.AddChild(wire);

  return node2->GetID();
}

unsigned Workspace::CreateWireFromNodes(unsigned nodeId1, unsigned nodeId2) {
  std::shared_ptr<WireNode> node1 = nullptr;
  std::shared_ptr<WireNode> node2 = nullptr;

  for(auto& child : wireNodes_.GetChildren()){
    if(child->GetID() == nodeId1) node1 = child;
    if(child->GetID() == nodeId2) node2 = child;
  }

  wireNodes_.AddChild(node1);
  wireNodes_.AddChild(node2);

	auto wire = std::make_shared<WireElement>(node1, node2);
	wires_.AddChild(wire);
  return wire->GetID();
}

void Workspace::RotateEvent() {
  Element* element = nullptr; 
  if(isSelectedDragged_ && GetElementWithId(selectedComponentId_, element)){
    element->Rotate(90.f);
  }    
}

void Workspace::DeleteEvent() {
  if(isSelectedDragged_){
    components_.RemoveChild(selectedComponentId_);

    if(wireNodes_.RemoveChild(selectedComponentId_)){
      // check integrity of wires
      auto id = wires_.FindIf([nodeId=selectedComponentId_](const std::shared_ptr<WireElement>& node) -> bool{
        return node->Contains(nodeId);
      });

      // remove wire and other node
      Element* element;
      if(id && wires_.GetElementWithId(id, element)){
        WireElement* wire = static_cast<WireElement*>(element);
        auto node1 = wire->GetNode(0);
        auto node2 = wire->GetNode(1);
        if(node1->GetID() == selectedComponentId_) wireNodes_.RemoveChild(node2->GetID());
        if(node2->GetID() == selectedComponentId_) wireNodes_.RemoveChild(node1->GetID());
        wires_.RemoveChild(id);
      }
    }
  }    
}

void Workspace::ClearMenuEvent() {
  componentMenu_->Select(nullptr);
}

bool operator==(const sf::Vector2u& lhs, const sf::Vector2u& rhs){
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

std::shared_ptr<Circuit> Workspace::GetCircuit() const {
  auto circuit = std::make_shared<Circuit>();


  // /*
  
  // 1. find wire that has different ids
  //   a) pick one and replace with other
  //   b) find all nodes at grpahical location
  //   c) replace those aswell
  //   d) iterate until no more wires with different ids

  // 2. create CircuitInstructions from components

  // 3. circuit.ConstructFromInstructions

  // 4. return circuit

  // */










  // // std::vector<NodeStuff> nodes;
  // std::vector<WireStuff> wires;

  // // fill in vectors
  // for(auto& node : wireNodes_.GetChildren()){
  //    nodes.push_back(NodeStuff{node->GetID(), node->GetPosition()});
  // }
  // for(auto& wire : wires_.GetChildren()){
  //   wires.push_back(WireStuff{});
  // }

  // bool wireWasReplaced = true;

  // while(wireWasReplaced){
  //   wireWasReplaced = false;
  //   for(auto& wire : wires_.GetChildren()){
      
  //     auto node1 = wire->GetNode(0);
  //     auto node2 = wire->GetNode(1);

  //     auto node1pos = node1->GetPosition();
  //     auto node2pos = node2->GetPosition();

  //     if(node1->GetID() != node2->GetID()){
  //       wireWasReplaced = true;
  //       auto toBeReplaced = node1->GetID();
  //       auto toBeReplacedWith = node2->GetID();

  //       for(auto& node : wireNodes_.GetChildren()){
  //         auto nodePos = node->GetPosition();

  //         if(AreSamePosition(nodePos, node1pos) || AreSamePosition(nodePos, node2pos)){
  //           node =;
  //         }
  //       }
  //     }
  //   }
  // }

  // CircuitInstructions instructions;
  // // instructions.components // add here
  // circuit->ConstructFromInstructions(instructions);

  return circuit;
  // return Circuit();
}

bool Workspace::AnyTextFieldSelected() const {
  return std::any_of(
    componentTextFields_.begin(),
    componentTextFields_.end(),
    [](const auto& child){
      return child->IsSelected();
    }
  );
}

WorkspaceInstructions Workspace::GetWorkspaceInstructions() const {
  WorkspaceInstructions instructions;

  for(auto& comp : components_.GetChildren()){
    ComponentElementInstructions componentInstructions;
    componentInstructions.angle = comp->GetAngle();
    componentInstructions.position = comp->GetPosition() - GetPosition(); // should be local to workspace instead
    componentInstructions.values = {std::to_string(comp->GetValue())};
    componentInstructions.name = comp->GetName();
    componentInstructions.type = comp->GetType();

    instructions.components.push_back(componentInstructions);
  }

  for(auto& node : wireNodes_.GetChildren()){
    WireNodeInstructions wireNodeInstructions;
    wireNodeInstructions.position = node->GetPosition() - GetPosition(); // should be local to workspace instead
    wireNodeInstructions.node_id = node->GetID();
    instructions.nodes.push_back(wireNodeInstructions);
  }

  for(auto& wire : wires_.GetChildren()){
    WireElementInstructions wireInstructions;
    wireInstructions.node1_id = wire->GetNode(0) ? wire->GetNode(0)->GetID() : 0;
    wireInstructions.node2_id = wire->GetNode(1) ? wire->GetNode(1)->GetID() : 0;
    instructions.wires.push_back(wireInstructions);
  }

  return instructions;
}

void Workspace::SetWorkspaceFromInstructions(WorkspaceInstructions instructions) {
  if(!instructions.loadSuccess){
    std::cout << "Warning: Attempting to load potentially broken workspace.\n";
  }

  std::map<unsigned, unsigned> nodeMap;

  for(auto& node : instructions.nodes){
    auto nodeId = CreateNode(node.position);
    nodeMap[node.node_id] = nodeId;
  }

  for(auto& wire : instructions.wires){
    CreateWireFromNodes(nodeMap[wire.node1_id], nodeMap[wire.node2_id]);
  }

  for(auto& comp : instructions.components){
    CreateComponentFromInstructions(comp);
  }
}

unsigned Workspace::CreateNode(sf::Vector2f startGlobalPosition) {
  auto node = std::make_shared<WireNode>(startGlobalPosition);
  wireNodes_.AddChild(node);
  return node->GetID();
}

void Workspace::CreateComponentFromInstructions(ComponentElementInstructions instructions) {
  unsigned id = CreateComponent(instructions.type, instructions.position);

  ComponentElement* component = nullptr;

  for(auto& child : components_.GetChildren()){
    if(child->GetID() == id){
      component = child.get();
    }
  }

  if(component){
    component->SetPosition(instructions.position);
    component->SetRelativePosition(GetPosition());
    component->HandleDimensionsUpdated();
    component->Rotate(instructions.angle);
    component->SetValue(std::stod(instructions.values[0]));
  }
}
