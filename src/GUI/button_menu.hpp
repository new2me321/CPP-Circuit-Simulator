#ifndef __BUTTON_MENU_H__
#define __BUTTON_MENU_H__

#include "element_collection.hpp"
#include "button_element.hpp"

/**
 * @brief ButtonMenu is a horisontal panel of buttons.
 * 
 * @see button.hpp
 */
class ButtonMenu : public ElementCollection<ButtonElement>{
public:
	/**
	 * @brief Construct a new Button Menu object
	 * 
	 * @param font 
	 * @param fontsize 
	 */
	explicit ButtonMenu(const sf::Font& font, int fontsize);

	/**
	 * @brief Wrapper for adding a button with a callback in the panel.
	 * 
	 * @param text 
	 * @param callback 
	 */
	void AddButton(std::string text, std::function<void()> callback);

protected:
	/**
	 * @brief Stores fontsize and a reference to a font. 
	 * 
	 * @details 
	 * 	Passed to new buttons when they are added.
	 * 
	 * @see ButtonMenu::AddButton
	 */
  const sf::Font& font_;
  int fontsize_;

	/**
	 * @brief override ElementCollection<T>::ArrangeChildren
	 * 
	 * @details
	 * 	Arranges buttons in a horisontal row.
	 */
	virtual void ArrangeChildren() override;

	sf::Color outlineColor_ = sf::Color(255, 174, 66);
	sf::Color fillColor_ = sf::Color(255, 195, 11);
	sf::Color textColor_ = sf::Color(0, 0, 0);

	float gap_ = 5.f;
};

#endif // __BUTTON_MENU_H__