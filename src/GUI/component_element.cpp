#include "component_element.hpp"

#include "component_texture_config.hpp"

#include "../Circuit/resistor.hpp"
#include "../Circuit/capacitor.hpp"
#include "../Circuit/inductor.hpp"
#include "../Circuit/node.hpp"
#include "../Circuit/voltage_source.hpp"

ComponentElement::ComponentElement(const sf::Texture& texture, ComponentTypeGUI type, std::shared_ptr<TextFieldElement> textField) :
  ImageElement(texture, componentClips.at(type)),
  textField_(textField),
  type_(type)
{
  pins_ = CreatePins(type);
  if(textField_)
    textField_->SetRelativePosition(GetPosition());
}

void ComponentElement::Draw(sf::RenderWindow& window) const {
  if(pinsVisible_)
    for(auto&[node, pos] : pins_)
      node->Draw(window);
  ImageElement::Draw(window);

  if(textField_){
    textField_->Draw(window);
  }
}

void ComponentElement::HandleEvent(const sf::Event& event) {
  if(textField_)
    textField_->HandleEvent(event);
}

void ComponentElement::HandleDimensionsUpdated(){
  for(auto&[node, pos] : pins_){
    auto pos2 = sf::Vector2f(
      GetSize().x * pos.x,
      GetSize().y * pos.y
    );
    node->SetRelativePosition(GetPosition());
    node->SetPosition(RotateVector(pos2, angle_ * (3.14159 / 180.0)));
  }
  ImageElement::HandleDimensionsUpdated();

  if(textField_){
    textField_->SetRelativePosition(GetPosition());
    textField_->HandleDimensionsUpdated();
  }
}

ComponentTypeGUI ComponentElement::GetType() const {
  return type_;
}

std::string ComponentElement::GetTypeString() const {
  return ComponentTypeToString(type_);
}

void ComponentElement::SetType(ComponentTypeGUI type) {
  SetClip(componentClips.at(type));
}

std::shared_ptr<Component> ComponentElement::GetComponent() const {
  switch(type_){
    case ComponentTypeGUI::Capacitor:{
      auto result = std::make_shared<Capacitor>("C", GetValue());
      result->SetID(this->GetID());
      return result;
    }
    case ComponentTypeGUI::Inductor:{
      auto result = std::make_shared<Inductor>("I", GetValue());
      result->SetID(this->GetID());
      return result;
    }
    case ComponentTypeGUI::Resistor:{
      auto result = std::make_shared<Resistor>("R", GetValue());
      result->SetID(this->GetID());
      return result;
    }
    case ComponentTypeGUI::DCSupply:{
      // auto result = std::make_shared<DCVoltageSource>("DC", value);
      // result->SetID(this->GetID());
      return nullptr;
    }
    case ComponentTypeGUI::Supply:{
      // ???
      return nullptr;
    }
    case ComponentTypeGUI::Ground:{
      // ???
      return nullptr;
    }
    default:
      return nullptr;
  }
}

void ComponentElement::SetPinsVisibility(bool pinsVisible) {
  pinsVisible_ = pinsVisible;    
}

std::vector<std::pair<std::shared_ptr<WireNode>, sf::Vector2f>> ComponentElement::CreatePins(ComponentTypeGUI type) {
  std::vector<std::pair<std::shared_ptr<WireNode>, sf::Vector2f>> result;

  switch(type){
    case ComponentTypeGUI::Ground:
      result.push_back(std::make_pair(std::make_shared<WireNode>(sf::Vector2f(0, 0)), sf::Vector2f(-0.5, 0)));
      break;
    case ComponentTypeGUI::Capacitor:
    case ComponentTypeGUI::Resistor:
    case ComponentTypeGUI::Diode:
    case ComponentTypeGUI::Inductor:
    case ComponentTypeGUI::DCSupply:
    case ComponentTypeGUI::Supply:
      result.push_back(std::make_pair(std::make_shared<WireNode>(sf::Vector2f(0, 0)), sf::Vector2f(0.5, 0)));
      result.push_back(std::make_pair(std::make_shared<WireNode>(sf::Vector2f(0, 0)), sf::Vector2f(-0.5, 0)));
      break;
    default:
      break;
  }
  
  return result;
}

double ComponentElement::GetValue() const {
  return textField_ ? std::stod(textField_->GetContent()) : 0.0;
}

void ComponentElement::SetValue(double value) {
  if(textField_)
    textField_->SetContent(std::to_string(value));
}

void ComponentElement::ToggleTextFieldVisibility() {
  textField_->ToggleTextFieldVisibility();
}

std::string ComponentElement::GetName() const {
  return ComponentTypeToString(GetType())[0] + std::to_string(GetID());
}

std::vector<sf::Vector2f> ComponentElement::GetNodeLocations() const {
  std::vector<sf::Vector2f> result;

  for(auto& node : pins_){
    result.push_back(node.first->GetPosition());
  }

  return result;
}
