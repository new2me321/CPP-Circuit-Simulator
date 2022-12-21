#ifndef __TEXT_ELEMENT_H__
#define __TEXT_ELEMENT_H__

#include "element.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <memory>

class TextElement : public Element{
public:
  explicit TextElement(std::string text, const sf::Font& font, int fontsize);
  virtual ~TextElement();

  /**
   * @brief override Element::Draw
   * 
   * @details
   *  Draws text and a rectangle
   * 
   * @param window 
   */
	virtual void Draw(sf::RenderWindow& window) const override;

  /**
   * @brief override Element::HandleDimensionsUpdate
   * 
   * @details
   *  Will scale button properly when the dimensions are changed.
   */
  virtual void HandleDimensionsUpdated() override;

  /**
   * @brief Set text to be drawn
   * 
   * @param text 
   */
  void SetText(std::string text);

  /**
   * @brief Set isCentered_ flag
   * 
   * @details if true, the text (and box) will be centered on both x and y axes.
   * 
   * @param isCentered 
   */
  void SetCentered(bool isCentered);

  /**
   * @brief Set text color
   * 
   * @param color 
   */
  void SetColor(sf::Color color);

  /**
   * @brief Set rectangle fill color
   * 
   * @param color 
   */
  void SetFillColor(sf::Color color);

  /**
   * @brief Set rectangle outline color
   * 
   * @param color 
   */
  void SetOutlineColor(sf::Color color);

  /**
   * @brief Set the rectangle outline thickness
   * 
   * @param outlineThickness 
   */
  void SetOutlineThickness(int outlineThickness);

  /**
   * @brief Set the padding scale
   * 
   * @details Multiplies the padding by this scalar value.
   * 
   * @param scale 
   */
  void SetPaddingScale(float scale);

protected:
  /**
   * @brief Helper function to center origin of both text and rectangle
   */
  void SetOriginToCenter();

  /**
   * @brief Get the size of the text on screen
   * 
   * @return sf::Vector2f 
   */
  sf::Vector2f GetTextSize() const;

  /**
   * @brief Helper function to update rectangle size from text size
   */
  void UpdateBoundsToFitText();

  /**
   * @brief SFML text object used for drawing.
   */
  sf::Text textObject_;

  /**
   * @brief Text parts
   * 
   * @details
   *  content_  : modifiable part
   *  preText_  : before content_
   *  postText_ : after content_
   */
  std::string preText_;
  std::string content_;
  std::string postText_;

  // when true boundary will fit the text automatically
  bool fitBoundaryToText_ = true;
  bool isCentered_ = false;

  /**
   * @brief Color of the text
   */
  sf::Color textColor_ = sf::Color::Black;

  /**
   * @brief Color of the rectangle outline.
   */
  sf::Color outlineColor_ = sf::Color::Black;

  /**
   * @brief Color of the rectangle fill color.
   */
  sf::Color fillColor_ = sf::Color::White;

  /**
   * @brief Rectangle shape used for drawing boundary.
   */
  sf::RectangleShape rectangleShape_;

  /**
   * @brief Thickness of the outline.
   * 
   * @note Thickness is negative so the outline will be draw inward.
   */
  int outlineThickness_ = -2;

  // padding is different since text boundary is generally weird
  const sf::Vector2f paddingTopLeft_ = sf::Vector2f(5, 2);
  const sf::Vector2f paddingBottomRight_ = sf::Vector2f(10, 8);

  float paddingScale_ = 1.f;
};

#endif // __TEXT_ELEMENT_H__