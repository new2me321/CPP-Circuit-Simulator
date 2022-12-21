#ifndef __BUTTON_ELEMENT_H__
#define __BUTTON_ELEMENT_H__

#include "text_element.hpp"
#include <functional>

/**
 * @brief Button is an interactive TextElement that has a callback function.
 * 
 * @see text_element.hpp
 */
class ButtonElement : public TextElement{
public:
  /**
   * @brief Construct a new Button object
   * 
   * @details
   *  Callback is nullptr by default and can be set later.
   * 
   * @see Button::SetCallback
   * 
   * @param text to be drawn inside rectangle
   * @param font 
   * @param fontsize 
   * @param callback takes no parameters and returns no parameters. Will be called when a button is activated.
   */
  explicit ButtonElement(std::string text, const sf::Font& font, int fontsize, const std::function<void()> callback = nullptr);

  /**
   * @brief override Element::HandleEvent
   * 
   * @details
   *  Will activate button if mouse is pressed at the buttons location.
   * 
   * @param event 
   */
	virtual void HandleEvent(const sf::Event& event);

  /**
   * @brief Set callback when button is activated.
   * 
   * @param callback takes no parameters and returns no parameters.
   */
  void SetCallback(const std::function<void()>& callback);

protected:
  /**
   * @brief Callback when button is activated.
   * 
   * @note May or may not be defined.
   * 
   * @details Takes no parameters and returns no parameters.
   */
  std::function<void()> callback_;
};

#endif // __BUTTON_ELEMENT_H__