#ifndef __COMPONENT_ELEMENT_H__
#define __COMPONENT_ELEMENT_H__

#include <vector>
#include <memory>

#include "image_element.hpp"
#include "component_type.hpp"
#include "wire_node.hpp"
#include "text_field_element.hpp"

#include "../Circuit/component.hpp"

/**
 * @brief Component element used for drawing.
 * 
 * @note
 * 	Not to be confused with Component
 * 	ComponentElement is purely a GUI object.
 * 
 * @details
 * 	Inherits from ImageElement.
 * 	Generates a Circuit object to be used in solving.
 * 
 * @see Circuit/component.hpp
 */
class ComponentElement : virtual public ImageElement{
public:
	/**
	 * @brief Construct a new Component Element object
	 * 
	 * @param texture 
	 * @param type 
	 */
	explicit ComponentElement(const sf::Texture& texture, ComponentTypeGUI type, std::shared_ptr<TextFieldElement> textField = nullptr);

	/**
	 * @brief override ImageElement::Draw
	 * 
	 * @details Draws pins and then calls ImageElement::Draw.
	 * 
	 * @param window 
	 */
	virtual void Draw(sf::RenderWindow& window) const override;

	/**
	 * @brief override Element::HandleEvent
	 * 
	 * @details Double click on 
	 * 
	 * @param event
	 */
	virtual void HandleEvent(const sf::Event& event) override;
	
	/**
	 * @brief override ImageElement::HandleDimensionsUpdated
	 * 
	 * @details Positions nodes correctly then calls ImageElement::HandleDimensionsUpdated
	 */
	virtual void HandleDimensionsUpdated() override;

	/**
	 * @brief Get the type of the component
	 * 
	 * @return ComponentTypeGUI 
	 */
	ComponentTypeGUI GetType() const;

	/**
	 * @brief Get the type of the component as as string.
	 * 
	 * @return std::string 
	 */
	std::string GetTypeString() const;

	/**
	 * @brief Set the type of the component
	 * 
	 * @details This is a wrapper for changing the clip of ImageElement
	 * 
	 * @param type 
	 */
	void SetType(ComponentTypeGUI type);

	/**
	 * @brief Creates the component to be passed into the Circuit
	 * 
	 * @see circuit.hpp
	 * 
	 * @param valueString the value of the component (e.g. resistance, conductance)
	 * 
	 * @return std::shared_ptr<Component> 
	 */
	std::shared_ptr<Component> CreateComponent(std::string valueString) const;

	/**
	 * @brief Set the visibility of pins
	 * 
	 * @param pinsVisible 
	 */
	void SetPinsVisibility(bool pinsVisible);

	/**
	 * @brief Toggle text field visibility
	 * 
	 * @see ComponentElement::textField_
	 */
	void ToggleTextFieldVisibility();

	std::shared_ptr<Component> GetComponent() const;

	double GetValue() const;
	void SetValue(double value);

	std::string GetName() const;

	std::vector<sf::Vector2f> GetNodeLocations() const;

protected:
	/**
	 * @brief Container for pins
	 * 
	 * @details
	 * 	First value of the pair is the node (WireNode)
	 * 	Second value is the position offset (sf::Vector2f)
	 */
	std::vector<std::pair<std::shared_ptr<WireNode>, sf::Vector2f>> pins_;

	/**
	 * @brief Flag that is true if pins should be drawn.
	 */
	bool pinsVisible_ = false;

	std::shared_ptr<TextFieldElement> textField_;

	/**
	 * @brief Type of the component.
	 */
	ComponentTypeGUI type_;

	/**
	 * @brief Value of component (e.g. resistance)
	 */

	/**
	 * @brief Static helper function to create a list of pins for a component type.
	 * 
	 * @details
	 * 	Different types of components have different pin layout.
	 * 	(e.g. ground node only has one pin)
	 * 
	 * @param type 
	 * @return std::vector<std::pair<std::shared_ptr<WireNode>, sf::Vector2f>> 
	 */
	static std::vector<std::pair<std::shared_ptr<WireNode>, sf::Vector2f>> CreatePins(ComponentTypeGUI type);

	/**
	 * @brief Name of the component
	 * 
	 * @todo: generate
	 * 
	 */
	std::string name_ = "NoName";
};

#endif // __COMPONENT_ELEMENT_H__