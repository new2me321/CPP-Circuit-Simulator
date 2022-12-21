#include "component_menu.hpp"

#include <iostream>
#include <algorithm>
#include <math.h>

ComponentMenu::ComponentMenu(float height):
  componentSize_(componentSizeResolution_ * height, height)
{
}

ComponentMenu::~ComponentMenu() {
}

void ComponentMenu::AddComponent(ComponentTypeGUI type, const sf::Texture& texture) {
  auto component = std::make_shared<ComponentElement>(texture, type);
  component->SetSize(componentSize_);

  AddChild(component);
}

void ComponentMenu::HandleEvent(const sf::Event& event) {
  if(event.type == sf::Event::MouseButtonPressed){
    auto mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
    
    // select component that was clicked
    auto it = std::find_if(children_.begin(), children_.end(), [&mousePosition](const auto& child){ return child->GetBoundRect().contains(mousePosition); });
    if(it != children_.end()){
      Select((*it).get());
    }
  }
}

void ComponentMenu::Update() {
  UpdateChildren();
}

void ComponentMenu::ArrangeChildren() {
  std::for_each(children_.begin(), children_.end(), [p=this->GetPosition(), x=0, y=0](auto& child) mutable {
    child->SetPosition(sf::Vector2f(x, y));
    child->SetRelativePosition(p);
    x += child->GetSize().x;
  });
}

ComponentTypeGUI ComponentMenu::GetSelectedComponentType() const {
  return selectedComponent ? selectedComponent->GetType() : ComponentTypeGUI::None;
}

void ComponentMenu::Select(ComponentElement* element) {
  if(selectedComponent)
    selectedComponent->SetFillColor(nonSelectedOutlineColor_);

  if(!element){
    selectedComponent = nullptr;
  }
  else if(element == selectedComponent){
    selectedComponent = nullptr;
  }
  else{
    element->SetFillColor(selectedOutlineColor_);
    selectedComponent = element;
  }
}

void ComponentMenu::SetSelectedComponentType(ComponentTypeGUI type) {
  auto it = std::find_if(children_.begin(), children_.end(), [type](auto& child){
    return child->GetType() == type;
  });

  Select(it == children_.end() ? nullptr : (*it).get());
}

void ComponentMenu::SetHeight(float height) {
  componentSize_ = sf::Vector2f(componentSizeResolution_ * height, height);
}
