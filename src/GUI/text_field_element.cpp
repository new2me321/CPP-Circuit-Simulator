#include "text_field_element.hpp"

TextFieldElement::TextFieldElement(std::string text, const sf::Font& font, int fontsize, std::string preText, std::string postText) :
  TextElement(preText + text + postText, font, fontsize),
  content_(text),
  preText_(preText),
  postText_(postText)
{
}

void TextFieldElement::Draw(sf::RenderWindow& window) const {
  if(!isVisible_){
    return;
  }

  TextElement::Draw(window);
}

void TextFieldElement::HandleEvent(const sf::Event& event) {
  if(
    event.type == sf::Event::MouseButtonPressed &&
    event.mouseButton.button == sf::Mouse::Left
  ){
    isSelected_ = GetBoundRect().contains(
      sf::Vector2f(event.mouseButton.x, event.mouseButton.y)
    );

    UpdateColor();
  }

  if(event.type == sf::Event::TextEntered && isSelected_){
    if(event.text.unicode == 8){
      std::string text = GetContent();
      if(text.size()){
        text.pop_back();
        SetContent(text);
      }
    }
    else if(event.text.unicode == 13){
      isSelected_ = false;
    }
    else if(event.text.unicode < 128){
      SetContent(sf::String(GetContent()) + event.text.unicode);
    }
  }
}

std::string TextFieldElement::GetContent() const {
  return content_;    
}

std::string TextFieldElement::GetText() const {
  return preText_ + content_ + postText_;    
}

void TextFieldElement::SetContent(std::string content) {
  content_ = content;
  textObject_.setString(GetText());
  if(fitBoundaryToText_){
    UpdateBoundsToFitText();
  }
}

void TextFieldElement::SetPreText(std::string preText) {
  preText_ = preText;
  if(fitBoundaryToText_){
    UpdateBoundsToFitText();
  }
}

void TextFieldElement::SetPostText(std::string postText) {
  postText_ = postText;
  if(fitBoundaryToText_){
    UpdateBoundsToFitText();
  }
}

void TextFieldElement::SetSelectColor(sf::Color color) {
  selectColor_= color;
}

void TextFieldElement::UpdateColor() {
  textObject_.setFillColor(isSelected_ ? selectColor_ : textColor_);
}

void TextFieldElement::SetSelected(bool isSelected) {
  isSelected_ = isSelected;
  UpdateColor();
}

bool TextFieldElement::IsSelected() const {
  return isSelected_;
}

bool TextFieldElement::IsVisible() const {
  return isVisible_;    
}

void TextFieldElement::ToggleTextFieldVisibility() {
  isVisible_ = !isVisible_;
}

void TextFieldElement::SetVisibility(bool isVisible) {
  isVisible_ = isVisible;
}
