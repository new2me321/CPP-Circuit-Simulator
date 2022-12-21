#include "element.hpp"

Element::Element() :
  size_(0, 0),
  origin_(0, 0),
  position_(0, 0),
  relativePosition_(0, 0),
  angle_(0.f),
  id_(GenerateID())
{}

Element::~Element() {}

void Element::Draw(sf::RenderWindow&) const {}

void Element::HandleEvent(const sf::Event&) {}

void Element::Update() {}

void Element::HandleDimensionsUpdated() {}

void Element::Rotate(float angle){
  angle_ += angle;
  HandleDimensionsUpdated();
}

void Element::Element::SetOrigin(sf::Vector2f origin) {
  origin_ = origin;
  HandleDimensionsUpdated();
}

sf::Vector2f Element::GetPosition() const {
  return position_ + relativePosition_;
}

sf::Vector2f Element::GetSize() const {
  return size_;
}

void Element::SetPosition(sf::Vector2f position) {
  position_ = position;
  HandleDimensionsUpdated();
}

void Element::SetSize(sf::Vector2f size) {
  size_ = size;
  HandleDimensionsUpdated();
}

void Element::SetRelativePosition(sf::Vector2f relativePosition) {
  relativePosition_ = relativePosition;
  HandleDimensionsUpdated();
}

unsigned Element::Element::GetID() const {
  return id_;    
}

unsigned Element::GenerateID() {
  static unsigned c = 1;
  return c++;
}

sf::FloatRect Element::GetBoundRect() const {
  return sf::FloatRect(GetPosition() - origin_, GetSize());
}

void Element::SetGlobalPosition(sf::Vector2f position){
  SetPosition(position - relativePosition_);
}

bool Element::GetElementWithId(unsigned id, Element*& result) const {
  if(this->GetID() == id){
    result = (Element*)this;
    return true;
  }
  else{
    return false;
  }
}

std::vector<unsigned> Element::GetElementsThatContain(sf::Vector2f position) const{
  return this->GetBoundRect().contains(position) ? std::vector<unsigned>(1, GetID()) : std::vector<unsigned>();
}

float Element::GetAngle() const{
  return angle_;
}
