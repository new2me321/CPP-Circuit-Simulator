#ifndef __COMPONENT_MENU_H__
#define __COMPONENT_MENU_H__

#include "element_collection.hpp"
#include "component_element.hpp"

class ComponentMenu : public ElementCollection<ComponentElement>{
public:
	explicit ComponentMenu(float height);
	~ComponentMenu();

	void SetHeight(float height);

	void AddComponent(ComponentTypeGUI type, const sf::Texture& texture);

	void SetSelectedComponentType(ComponentTypeGUI type);
	ComponentTypeGUI GetSelectedComponentType() const;

	void Select(ComponentElement* element);
	virtual void HandleEvent(const sf::Event& event) override;
	virtual void Update() override;

protected:
	virtual void ArrangeChildren() override;

	const float componentSizeResolution_ = 4.0/3.0;
	sf::Vector2f componentSize_;

  const sf::Color nonSelectedOutlineColor_ = sf::Color::Transparent;
  const sf::Color selectedOutlineColor_ = sf::Color(0, 0, 255, 144);
	ComponentElement* selectedComponent = nullptr;

};

#endif // __COMPONENT_MENU_H__