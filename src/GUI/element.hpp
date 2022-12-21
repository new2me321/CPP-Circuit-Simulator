#ifndef __ELEMENT_H__
#define __ELEMENT_H__

#include <SFML/Graphics.hpp>

/**
 * @brief Element class for any GUI element which specialized elements inherit from
 * 
 * @details
 *  Element has a lot of functionality can be overriden or used as it is. Most elements should
 *  override the Draw method. In case they are interactive they can override HandleEvent method.
 * 
 * @note
 * 	This class should not be used as it is, but be derived from. Different elements
 * 	may override different functions and leave others as they are. This way the GUI
 *  is very versatile and it is easy to add new GUI elements in the future.
 * 
 * @see gui.hpp
 * 
 */
class Element{
public:
	/**
	 * @brief Construct a new Element object
	 * 
	 * @details
	 * 	Generates an unique id for each element.
	 * 
	 * @see GenerateID
	 */
	explicit Element();

	/**
	 * @brief Destroy the Element object
	 */
	virtual ~Element();

	/**
	 * @brief Copy assigment operator deleted
	 */
	Element& operator=(Element&) = delete;

	/**
	 * @brief Draws element in specified way. By default it does nothing.
	 * 
	 * @param window 
	 */
	virtual void Draw(sf::RenderWindow& window) const;

	/**
	 * @brief Handles an event.
	 * 
	 * @details
	 *  An event can be any SFML event (e.g. keyboard or mouse).
	 *  Event is passed to this function from a parent element or directly from the GUI.
	 * 
	 * @param event 
	 */
	virtual void HandleEvent(const sf::Event& event);

	/**
	 * @brief Updates elements internal states. 
	 * 
	 * @details By default it does nothing.
	 */
	virtual void Update();

	/**
	 * @brief Handles changes in any modifications to dimensions
	 * 
	 * @details Will be called from functions that modify position and/or size
	 * 
	 * @see Element::SetPosition Element::SetSize
	 */
	virtual void HandleDimensionsUpdated();

	/**
	 * @brief GetID returns id_
	 * 
	 * @see Element::id_
	 * 
	 * @return unsigned id_
	 */
	unsigned GetID() const;

	/**
	 * @brief Get element with given ID and store it in result
	 * 
	 * @details
	 * 	By default this will return pointer to "this"
	 * 	Elements that have mutliple elements inside may override this function
	 * 
	 * @see element_collection.hpp
	 * 
	 * @param unsigned id
	 * @param Element*& result
	 * 
	 * @return returns whether element was found and was successfully stored in "result" parameter
	 */
	virtual bool GetElementWithId(unsigned id, Element*& result) const;

	/**
	 * @brief Get the global position object
	 * 
	 * @return sf::Vector2f 
	 */
	sf::Vector2f GetPosition() const;

	/**
	 * @brief Get the Size object
	 * 
	 * @return sf::Vector2f 
	 */
	virtual sf::Vector2f GetSize() const;

	/**
	 * @brief Get the boundary as rectangle of object
	 * 
	 * @details May be overridden in case object has own boundaries
	 * 
	 * @return sf::FloatRect 
	 */
	virtual sf::FloatRect GetBoundRect() const;

	/**
	 * @brief Get elements that have a position co-ordinate inside them
	 * 
	 * @details
	 * 	By default this will return the objects own ID in case the position is inside its boundaries.
	 *  Elements that have multiple elements may override this function.
	 * 
	 * @param position 
	 * @return std::vector<unsigned> listOfIDs
	 */
  virtual std::vector<unsigned> GetElementsThatContain(sf::Vector2f position) const;

	/**
	 * @brief Set the origin of the object
	 * 
	 * @details
	 * 	An origin is the offset which the center of boundary is located
	 * 
	 * @see GetBoundRect
	 * 
	 * @param origin 
	 */
	void SetOrigin(sf::Vector2f origin);

	/**
	 * @brief Set the position of the object
	 * 
	 * @details
	 * 	This function will not place the object in screen space, rather
	 * 	position relative to given parent position
	 * 
	 * @see SetGlobalPosition
	 * 
	 * @param position 
	 */
	void SetPosition(sf::Vector2f position);

	/**
	 * @brief Set the size object
	 * 
	 * @details This will call HandleDimensionsUpdated
	 * 
	 * @see HandleDimensionsUpdated
	 * 
	 * @param size 
	 */
	void SetSize(sf::Vector2f size);

	/**
	 * @brief Set the Global Position object
	 * 
	 * @details	
	 * 	This function will place the object in screen space
	 * 
	 * @see SetPosition
	 * 
	 * @param position 
	 */
	void SetGlobalPosition(sf::Vector2f position);

	/**
	 * @brief Set the parent position of the object. AKA relative to the parent position
	 * 
	 * @param relativePosition 
	 */
	void SetRelativePosition(sf::Vector2f relativePosition);

	/**
	 * @brief Rotate the object by an angle
	 * 
	 * @details This function will be totally interpetable by specific elements and does nothing by default.
	 * 
	 * @param angle 
	 */
	virtual void Rotate(float angle);

	float GetAngle() const;

protected:
	/**
	 * @todo rename these
	 * 
	 *	startPosition <- relativePosition ?
	 *	
	 *	use parentPosition instead ?
	 *	
	 *	- GetGlobalPosition: return position + startPosition;
	 *	- SetGlobalPosition: position = newPosition - startPosition;
	 *	- GetLocalPosition: return position;
	 *	- SetLocalPosition: position = newPosition;
	 *	- GetGlobalBounds: Rect(GetGlobalPosition - origin, size)
	 */
	sf::Vector2f size_;
	sf::Vector2f origin_;
	sf::Vector2f position_;
	sf::Vector2f relativePosition_;
	float angle_;

	/**
	 * @brief id_ is an identifier unique to this object
	 * 
	 * @details
	 * 	id_ will always be greater than zero. In case some function returns
	 *  an id equal to zero, it means it has failed
	 * 
	 * @see GenerateID
	 */
	unsigned id_;

private:
	/**
	 * @brief Generates an unique identifier that is stored as unsigned int
	 * 
	 * @attention Only the Element constructor should call this function. 
	 * 
	 * @details
	 *  Returned id's will start from 1. Each time the function is called it will increment the counter.
	 *  In any realistic lifetime of the program there will never be close to enough Elements that would
	 * 	cause this function to overflow.
	 * 
	 * @return unsigned 
	 */
	static unsigned GenerateID();
};

#endif // __ELEMENT_H__