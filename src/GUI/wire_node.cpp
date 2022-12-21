#include "wire_node.hpp"

#include <iostream>
#include "component_texture_config.hpp"

WireNode::WireNode(sf::Vector2f position) :
  Element(),
  beingDragged_(false)
{
  SetPosition(position);
  SetSize(wireNodeHandleSize_);
  SetOrigin(wireNodeHandleSize_ * 0.5);

  wireNodeShape_.setFillColor(wireNodeColor_);
  wireNodeShape_.setSize(wireNodeShapeSize_);
  wireNodeShape_.setOrigin(wireNodeShapeSize_ * 0.5);
}

void WireNode::Draw(sf::RenderWindow& window) const {
  window.draw(wireNodeShape_);
}

void WireNode::HandleEvent(const sf::Event& event){
  if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left){
    sf::Vector2f mousePosition = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
    if(wireNodeShape_.getGlobalBounds().contains(mousePosition)){
      beingDragged_ = true;
      SetGlobalPosition(mousePosition);
    }
  }
  if(event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left){
    beingDragged_ = false;
  }

  if(beingDragged_ && event.type == sf::Event::MouseMoved){
    sf::Vector2f mousePosition = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
    SetGlobalPosition(mousePosition);
  }
}

void WireNode::HandleDimensionsUpdated() {
  wireNodeShape_.setPosition(GetPosition());
}
