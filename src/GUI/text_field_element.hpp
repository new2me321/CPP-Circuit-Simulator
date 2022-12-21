#ifndef __TEXT_FIELD_ELEMENT_H__
#define __TEXT_FIELD_ELEMENT_H__

#include "text_element.hpp"

/**
 * @brief TextFieldElement is an interactive text field, built on top of TextElement
 * 
 * @see TextElement
 */
class TextFieldElement : public TextElement{
public:
  /**
   * @brief Construct a new Text Field Element object
   * 
   * @param text initial contents of the text field
   * @param font 
   * @param fontsize 
   * @param preText text that is before modifiable contents
   * @param postText text that is after
   */
  explicit TextFieldElement(std::string text, const sf::Font& font, int fontsize, std::string preText = "", std::string postText = "");

  /**
   * @brief override TextElement::Draw
   * 
   * @details
   *  Only to gate keep visibility.
   *  If visible, call TextElement::Draw normally
   * 
   * @param window
   */
	virtual void Draw(sf::RenderWindow& window) const override;

  /**
   * @brief override Element::HandleEvent
   * 
   * @details
   *  Will select current TextFieldElement if mouse is pressed at the buttons location.
   *  If selected, keyboard will add characters to contents.
   * 
   * @param event 
   */
	virtual void HandleEvent(const sf::Event& event) override;

  /**
   * @brief Get the entire displayed text
   * 
   * @details
   *  Returns the entire string, including pre- and posttext.
   *  (preText_ + contents_ + postText_)
   * 
   * @return std::string 
   */
  std::string GetText() const;
  
  /**
   * @brief Get the text contents without pretext of posttext.
   * 
   * @return std::string 
   */
  std::string GetContent() const;

  /**
   * @brief Set the modifiable part of the text field.
   * 
   * @param text 
   */
  void SetContent(std::string text);
  
  /**
   * @brief Set the text displayed before the modifiable contents.
   * 
   * @param preText 
   */
  void SetPreText(std::string preText);

  /**
   * @brief Set the text displayed after the modifiable contents.
   * 
   * @param postText 
   */
  void SetPostText(std::string postText);

  /**
   * @brief Set the color of the text when field is selected.
   * 
   * @param color 
   */
  void SetSelectColor(sf::Color color);

  /**
   * @brief Set isSelected_ flag
   * 
   * @details when true, the text field can be modified
   * 
   * @param isSelected 
   */
  void SetSelected(bool isSelected);

  /**
   * @brief Set the visibility flag
   * 
   * @param isVisible 
   */
  void SetVisibility(bool isVisible);

  /**
   * @brief Toggles the visibility flag
   */
  void ToggleTextFieldVisibility();

  /**
   * @brief Is text field selected.
   * 
   * @return true if text field is selected.
   */
  bool IsSelected() const;

  /**
   * @brief Is text field visible.
   * 
   * @return true if text field is visible.
   */
  bool IsVisible() const;

private:
  /**
   * @brief Helper function.
   * 
   * @details Updates colors depending on wether field is currently selected.
   */
  void UpdateColor();

  /**
   * @brief the part of the string that is being modified.
   */
  std::string content_;

  /**
   * @brief the string that comes before content_
   * 
   * @see TextFieldElement::content_
   */
  std::string preText_;

  /**
   * @brief the string that comes after content_
   * 
   * @see TextFieldElement::content_
   */
  std::string postText_;

  /**
   * @brief Color of the text when field is selected.
   */
  sf::Color selectColor_ = sf::Color::Blue;

  /**
   * @brief If flag is true, then field is currently modifiable
   */
  bool isModifiable_ = true;

  /**
   * @brief The text field is currently selected, if the flag is true.
   */
  bool isSelected_ = false;

  bool isVisible_ = true;
};

#endif // __TEXT_FIELD_ELEMENT_H__