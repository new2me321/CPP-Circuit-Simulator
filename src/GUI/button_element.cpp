#include "button_element.hpp"

ButtonElement::ButtonElement(std::string text, const sf::Font& font, int fontsize, const std::function<void()> callback) :
  TextElement(text, font, fontsize),
  callback_(callback)
{
  rectangleShape_.setOutlineColor(outlineColor_);
  rectangleShape_.setOutlineThickness(outlineThickness_);
  rectangleShape_.setFillColor(fillColor_);
}

void ButtonElement::HandleEvent(const sf::Event& event) {
  if(
    callback_ &&
    event.type == sf::Event::MouseButtonPressed &&
    this->GetBoundRect().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y))
  ){
    callback_();
  }
}

void ButtonElement::SetCallback(const std::function<void()>& callback) {
  callback_ = callback;
}
