#ifndef __IMAGE_ELEMENT_H__
#define __IMAGE_ELEMENT_H__

#include "element.hpp"
#include <SFML/Graphics/Sprite.hpp>

/**
 * @brief ImageElement is an element that stores and draws portion of sf::Texture.
 * 
 * @details	ImageElement can also draw its boundaries.
 * 
 * @note
 *  ImageElement doesn't store the texture data.
 * 	It creates an sf::Sprite from given texture
 */
class ImageElement : virtual public Element{
public:
	/**
	 * @brief Construct a new Image Element object
	 * 
	 * @param texture
	 * @param clip 
	 */
	explicit ImageElement(const sf::Texture& texture, sf::IntRect clip);

	/**
	 * @brief Destroy the Image Element object
	 * 
	 */
	~ImageElement();

	/**
	 * @brief Override Element::Draw to draw image and boundary
	 * 
	 * @param window 
	 */
	virtual void Draw(sf::RenderWindow& window) const override;

	/**
	 * @brief Override Element::HandleDimensionsUpdate
	 * 
	 * @details Will scale texture properly inside element bounds.
	 */
	virtual void HandleDimensionsUpdated() override;

	/**
	 * @brief Override Element::Rotate
	 * 
	 * @details Rotates both the sprite and the boundaries
	 * 
	 * @param angle 
	 */
	virtual void Rotate(float angle) override;

	/**
	 * @brief Set the clip of the texture.
	 * 
	 * @param clip 
	 */
	void SetClip(sf::IntRect clip);

	/**
	 * @brief Sets the origin to the center of the image.
	 * 
	 * @note Also calls Element::SetOrigin
	 */
	void SetOriginToCenter();

	/**
	 * @brief Set the Outline Color object
	 * 
	 * @param color 
	 */
	void SetOutlineColor(sf::Color color);

	/**
	 * @brief Set the Fill Color object
	 * 
	 * @param color 
	 */
	void SetFillColor(sf::Color color);

	/**
	 * @brief Set boundarys visibility flag
	 * 
	 * @param visible 
	 */
	void SetBoundaryVisible(bool visible);

protected:
	/**
	 * @brief sprite_ will draw the image.
	 * 
	 * @details Doesn't store the texture data.
	 */
	sf::Sprite sprite_;

	/**
	 * @brief Clip is the portion of the texture to be drawn.
	 */
	sf::IntRect clip_;

	/**
	 * @brief when true, the boundary will be drawn.
	 */
	bool boundaryVisible_ = true;

	/**
	 * @brief Boundary shape that will be drawn if boundaryVisible_ flag is true
	 */
  sf::RectangleShape boundaryShape_;

	/**
	 * @brief Padding is the gap between the image and its corners.
	 */
	const sf::Vector2f padding_ = sf::Vector2f(0.0, 0.0);
};


#endif // __IMAGE_ELEMENT_H__