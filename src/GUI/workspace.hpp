#ifndef __WORKSPACE_H__
#define __WORKSPACE_H__

#include <SFML/Graphics/RectangleShape.hpp>
#include "element_collection.hpp"
#include "component_element.hpp"
#include "wire_element.hpp"
#include "component_menu.hpp"
#include "../Circuit/circuit.hpp"
#include "../Circuit/workspace_netlist.hpp"

class WorkspaceInstructions;
class ComponentElementInstructions;

/**
 * @brief Workspace is used to edit circuits.
 * 
 * @note Does not solve anything, rather only edits circuits
 * 
 * @see solver.hpp
 */
class Workspace : public Element{
public:
	explicit Workspace(const sf::Texture& componentTexture, std::shared_ptr<ComponentMenu> menu, const sf::Font& font, int fontsize);
	~Workspace();

	/**
	 * @brief Constructor for creating a workspace from WorkspaceInstructions
	 * 
	 * @details Used for loading a workspace
	 * 
	 * @param instructions 
	 */
	void SetWorkspaceFromInstructions(WorkspaceInstructions instructions);

	/**
	 * @brief Get the WorkspaceInstructions for saving
	 * 
	 * @return WorkspaceInstructions 
	 */
	WorkspaceInstructions GetWorkspaceInstructions() const;

	/**
	 * @brief Create circuit from current workspace editor.
	 * 
	 * @return std::shared_ptr<Circuit> 
	 */
	std::shared_ptr<Circuit> GetCircuit() const;

	virtual sf::Vector2f GetSize() const override;

	/**
	 * @brief override Element functions
	 * 
	 * @param window 
	 */
	virtual void Draw(sf::RenderWindow& window) const override;
	virtual void HandleEvent(const sf::Event& event) override;
	virtual void Update() override;
	virtual void SetPosition(sf::Vector2f position);
	virtual void SetSize(sf::Vector2f size);
	virtual bool GetElementWithId(unsigned id, Element*& result) const override;

private:
	/**
	 * @brief Specific mouse event handlers
	 * 
	 * @param mousePosition 
	 */
	void LeftClick(sf::Vector2f mousePosition);
	void RightClick(sf::Vector2f mousePosition);
	void LeftRelease(sf::Vector2f mousePosition);
	void MouseMove(sf::Vector2f mousePosition);

	/**
	 * @brief Helper functions for some "events"
	 */
	void RotateEvent();
	void DeleteEvent();
	void ClearMenuEvent();

	/**
	 * @brief Helpers for updating workspace drawable components.
	 */
	void UpdateBackground();
	void RegenerateGrid();

	/**
	 * @brief Helper functions for creating components inside workspace containers.
	 * 
	 * @return ID of the element that is created.
	 */
	unsigned CreateNode(sf::Vector2f startGlobalPosition);
	unsigned CreateWire(sf::Vector2f startGlobalPosition);
	unsigned CreateWireFromNodes(unsigned nodeId1, unsigned nodeId2);
	unsigned CreateComponent(ComponentTypeGUI type, sf::Vector2f globalPosition);

	/**
	 * @brief Helper function used by SetWorkspaceFromInstructions
	 * 
	 * @param instructions 
	 */
	void CreateComponentFromInstructions(ComponentElementInstructions instructions);

	/**
	 * @brief Helper function to clamp a co-ordinate onto the grid.
	 * 
	 * @param position 
	 * @return sf::Vector2f 
	 */
	sf::Vector2f ClampToGrid(sf::Vector2f position) const;

	/**
	 * @brief Helper function to determine if any text field is currently selected.
	 */
	bool AnyTextFieldSelected() const;

private:
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
	 * @brief Component menu used for picking components.
	 */
	std::shared_ptr<ComponentMenu> componentMenu_;

	/**
	 * @brief Component texture is used for creating new components.
	 */
	const sf::Texture& componentTexture_;

	/**
	 * @brief All element containers inside Workspace.
	 */
	ElementCollection<ComponentElement> components_;
	ElementCollection<WireNode> wireNodes_;
	ElementCollection<WireElement> wires_;
	std::vector<std::shared_ptr<TextFieldElement>> componentTextFields_;

	/**
	 * @brief Used for drawing grid and background.
	 */
	std::vector<sf::Vertex> gridVertices_;
	sf::RectangleShape background_;

  /**
   * @brief Used by drag mechanic.
   */
  bool isSelectedDragged_ = false;
  unsigned selectedComponentId_ = 0;

	/**
	 * @brief Configuration constants.
	 */
	const sf::Color backgroundColor_ = sf::Color(200, 200, 255);
	const sf::Color gridColor_ = sf::Color(150, 150, 200);
	const float gridLineInterval_ = 25;
	const sf::Vector2f componentSize_ = sf::Vector2f(gridLineInterval_ * 4, gridLineInterval_ * 3);
  const sf::Mouse::Button mouseSelectButton_ = sf::Mouse::Button::Left;

};

#endif // __WORKSPACE_H__