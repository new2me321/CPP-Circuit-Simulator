#include "image_element.hpp"

#include "component_texture_config.hpp"

ImageElement::ImageElement(const sf::Texture& texture, sf::IntRect clip) :
  sprite_(texture, clip),
  clip_(clip)
{
  boundaryShape_.setOutlineColor(sf::Color::Black);
  boundaryShape_.setOutlineThickness(-2);
  boundaryShape_.setFillColor(sf::Color::Transparent);
}

ImageElement::~ImageElement() {
}

void ImageElement::Draw(sf::RenderWindow& window) const {
  if(boundaryVisible_){
    window.draw(boundaryShape_);
  }
  window.draw(sprite_);
}

void ImageElement::HandleDimensionsUpdated(){
  boundaryShape_.setPosition(GetPosition());
  boundaryShape_.setSize(GetSize());

  sprite_.setPosition(GetPosition() + padding_);
  sprite_.setScale(sf::Vector2f(
    (GetSize().x - padding_.x * 2.0) / (float)clip_.width,
    (GetSize().y - padding_.y * 2.0) / (float)clip_.height
  ));
}

void ImageElement::SetBoundaryVisible(bool visible) {
  boundaryVisible_ = visible;
}

void ImageElement::SetOutlineColor(sf::Color color) {
  boundaryShape_.setOutlineColor(color);
}

void ImageElement::SetFillColor(sf::Color color) {
  boundaryShape_.setFillColor(color);
}

void ImageElement::SetClip(sf::IntRect clip) {
  sprite_.setTextureRect(clip);
  SetSize(size_);
}

void ImageElement::Rotate(float angle) {
  sprite_.rotate(angle);
  boundaryShape_.rotate(angle);

  Element::Rotate(angle);
}

void ImageElement::SetOriginToCenter() {
  sprite_.setOrigin(
    clip_.width / 2.f,
    clip_.height / 2.f
  );
  boundaryShape_.setOrigin(
    GetSize() * 0.5
  );

  Element::SetOrigin(GetSize() * 0.5);
}
