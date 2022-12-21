#include "button_menu.hpp"

#include <limits>

ButtonMenu::ButtonMenu(const sf::Font& font, int fontsize):
  font_(font), fontsize_(fontsize)
{
}

void ButtonMenu::AddButton(std::string text, std::function<void()> callback) {
  auto button = std::make_shared<ButtonElement>(text, font_, fontsize_, callback);
  button->SetColor(textColor_);
  button->SetFillColor(fillColor_);
  button->SetOutlineColor(outlineColor_);
  AddChild(button);
  ArrangeChildren();
}

void ButtonMenu::ArrangeChildren() {
  std::for_each(children_.begin(), children_.end(), [p=this->GetPosition(), x=0, y=0, gap=gap_](auto& child) mutable {
    child->SetPosition(sf::Vector2f(x, y));
    child->SetRelativePosition(p);
    x += child->GetSize().x + gap;
  });
}
