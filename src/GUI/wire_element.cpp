#include "wire_element.hpp"

#include <iostream>
#include <math.h>

WireElement::WireElement(std::shared_ptr<WireNode> node1, std::shared_ptr<WireNode> node2):
  Element(),
  node1_(node1),
  node2_(node2)
{
}

void WireElement::Draw(sf::RenderWindow& window) const{
  sf::Vertex vertices[4];

  sf::Vector2f point1 = node1_->GetPosition();
  sf::Vector2f point2 = node2_->GetPosition();

  sf::Vector2f direction = point2 - point1;
  sf::Vector2f directionUnit = direction / std::hypot(direction.x, direction.y);
  sf::Vector2f directionNormal(-directionUnit.y, directionUnit.x);

  sf::Vector2f offset = directionNormal * (wireThickness / 2.f);

  vertices[0].position = point1 + offset;
  vertices[1].position = point2 + offset;
  vertices[2].position = point2 - offset;
  vertices[3].position = point1 - offset;

  for(int i=0; i<4; i++)
    vertices[i].color = wireColor_;
       
  window.draw(vertices, 4, sf::Quads);
     
  std::vector<sf::Vertex> lineVertices_ = {
    sf::Vertex(node1_->GetPosition(), wireColor_),
    sf::Vertex(node2_->GetPosition(), wireColor_)
  };
  window.draw(lineVertices_.data(), lineVertices_.size(), sf::LineStrip);
}

std::vector<unsigned> WireElement::GetElementsThatContain(sf::Vector2f position) const {
  std::vector<unsigned> result;
  if(node1_->GetBoundRect().contains(position)) result.push_back(node1_->GetID());
  if(node2_->GetBoundRect().contains(position)) result.push_back(node2_->GetID());
  return result;
}

WireNode* WireElement::GetNode(int index) const{
  return index == 0 ? node1_.get() : (index == 1 ? node2_.get() : nullptr);
}

void WireElement::SetNode(int index, std::shared_ptr<WireNode> node) {
  switch(index){
    case 0: node1_ = node; break;
    case 1: node2_ = node; break;
    default: break;
  }
}

bool WireElement::Contains(unsigned nodeId) const {
  return node1_->GetID() == nodeId || node2_->GetID() == nodeId;
}
