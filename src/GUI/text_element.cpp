#include "text_element.hpp"
#include <iostream>

#include "component_texture_config.hpp"

TextElement::TextElement(std::string text, const sf::Font& font, int fontsize) :
  textObject_(text, font, fontsize)
{
  if(fitBoundaryToText_){
    UpdateBoundsToFitText();
  }

  rectangleShape_.setOutlineColor(outlineColor_);
  rectangleShape_.setOutlineThickness(outlineThickness_);
  rectangleShape_.setFillColor(fillColor_);

  textObject_.setFillColor(textColor_);
}

TextElement::~TextElement() {
}

void TextElement::SetText(std::string text) {
  // content_ = content;
  textObject_.setString(text);
  if(fitBoundaryToText_){
    UpdateBoundsToFitText();
  }
}

void TextElement::SetColor(sf::Color color) {
  textColor_ = color;
  textObject_.setFillColor(color);
}

void TextElement::Draw(sf::RenderWindow& window) const {
  window.draw(rectangleShape_);
  window.draw(textObject_);
}

void TextElement::UpdateBoundsToFitText() {
  Element::SetSize(GetTextSize() + (paddingTopLeft_ + paddingBottomRight_) * paddingScale_);
  if(isCentered_){
    SetOriginToCenter();
  }
}

sf::Vector2f TextElement::GetTextSize() const {
  return sf::Vector2f(
    textObject_.getLocalBounds().width,
    textObject_.getLocalBounds().height + textObject_.getLocalBounds().top
  );
}

void TextElement::HandleDimensionsUpdated() {
  textObject_.setPosition(this->GetPosition() - origin_ + paddingTopLeft_ * paddingScale_);
  rectangleShape_.setSize(this->GetSize());
  rectangleShape_.setPosition(this->GetPosition() - origin_);
}

void TextElement::SetOriginToCenter() {
  SetOrigin(GetSize() * 0.5f);
}

void TextElement::SetCentered(bool isCentered) {
  isCentered_ = isCentered;
  UpdateBoundsToFitText();
}

void TextElement::SetFillColor(sf::Color color) {
  fillColor_ = color;    
  rectangleShape_.setFillColor(color);
}

void TextElement::SetOutlineColor(sf::Color color) {
  outlineColor_ = color;
  rectangleShape_.setOutlineColor(color);
}

void TextElement::SetOutlineThickness(int outlineThickness) {
  outlineThickness_ = outlineThickness;
  rectangleShape_.setOutlineThickness(outlineThickness);
}

void TextElement::SetPaddingScale(float scale) {
  paddingScale_ = scale;    
}
