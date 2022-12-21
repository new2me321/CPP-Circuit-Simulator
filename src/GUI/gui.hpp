#ifndef __GUI_H__
#define __GUI_H__

#include <memory>
#include <vector>
#include <algorithm>

#include "component_menu.hpp"
#include "button_menu.hpp"
#include "workspace.hpp"

/**
 * @brief GUI will handle the window and layout of the app.
 * 
 * @details
 * 	GUI has a container or Elements.
 * 
 * 	An element has different functionality that is handled by the GUI
 * 		- HandleEvent : Event handling (mouse, keyboard, etc)
 * 		- Draw 				:	Custom draw methods
 * 		- Update 			:	Updating Element specific attributes
 * 
 * 	GUI will store all texture and font data.
 * 
 * @note Elements are drawn in sequential order. Latter elements will be drawn on top of former.
 * 
 * @see element.hpp
 */
class GUI{
public:
	explicit GUI(int screenWidth, int screenHeight, const char* title);
	~GUI();
	GUI& operator=(GUI&) = delete;

	void Run();

	void SolveCircuit();
	void SaveWorkspace(std::string filepath);
	void LoadWorkspace(std::string filepath);
	void ClearWorkspace();

private:
	void Draw();
	void Update();
	void HandleEvents();

	void InitializeDefaultGUI();
	void SetLayout();
	void ResizeEvent(int width, int height);

private:
	sf::RenderWindow window_;
	sf::Texture componentTexture_;
	sf::Font font_;

	std::shared_ptr<ComponentMenu> componentMenu = nullptr;
	std::shared_ptr<ButtonMenu> buttonMenu = nullptr;
	std::shared_ptr<Workspace> workspace = nullptr;

	// std::vector<std::shared_ptr<Element>> elements_;
};

#endif // __GUI_H__