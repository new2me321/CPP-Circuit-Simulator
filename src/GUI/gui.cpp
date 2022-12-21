#include "gui.hpp"

#include <iostream>
#include "component_texture_config.hpp"
#include "text_field_element.hpp"
#include "../Circuit/workspace_netlist.hpp"
#include "../Solver/solver.hpp"


GUI::GUI(int screenWidth, int screenHeight, const char* title) :
	window_(sf::VideoMode(screenWidth, screenHeight), title)
{
	window_.setKeyRepeatEnabled(false);

	bool success = true;

	success &= font_.loadFromFile(defaultFontFile);
	success &= componentTexture_.loadFromFile(componentTextureFile);

	if(!success){
		std::cout << "GUI: Loading resources unsuccessful.\n";
	}
	else{
		componentTexture_.setSmooth(true);
		InitializeDefaultGUI();
	}
}

GUI::~GUI() {
}

void GUI::Run() {
	while(window_.isOpen()){
		HandleEvents();
		Update();
		Draw();

		sf::sleep(sf::milliseconds(10));
	}
}

void GUI::Draw() {
	window_.clear(sf::Color::White);

	componentMenu->Draw(window_);
	buttonMenu->Draw(window_);
	workspace->Draw(window_);
	// std::for_each(elements_.begin(), elements_.end(), [&window=window_](const auto& child){ child->Draw(window); });

  window_.display();
}

void GUI::Update() {
	// std::for_each(elements_.begin(), elements_.end(), [](auto& child){ child->Update(); });

	componentMenu->Update();
	buttonMenu->Update();
	workspace->Update();
}

void GUI::HandleEvents() {
	sf::Event event;
	while(window_.pollEvent(event)){
		if(event.type == sf::Event::Closed){
			window_.close();
		}
		if(event.type == sf::Event::Resized){
			ResizeEvent(event.size.width, event.size.height);
			break;
		}

		// std::for_each(elements_.begin(), elements_.end(), [&event=event](auto& child){ child->HandleEvent(event); });
		workspace->HandleEvent(event);
		componentMenu->HandleEvent(event);
		buttonMenu->HandleEvent(event);
	}
}

void GUI::InitializeDefaultGUI() {
	buttonMenu = std::make_shared<ButtonMenu>(font_, 25);
	buttonMenu->SetPosition(sf::Vector2f(6, 5));
	buttonMenu->AddButton("Solve",[&](){ SolveCircuit(); });
	buttonMenu->AddButton("Save", [&](){ SaveWorkspace(SAVEFILES_PATH "your_circuit.workspace"); });
	buttonMenu->AddButton("Load", [&](){ LoadWorkspace(SAVEFILES_PATH "your_circuit.workspace"); });
	buttonMenu->AddButton("Example 1", [&](){ LoadWorkspace(SAVEFILES_PATH "example1.workspace"); });
	buttonMenu->AddButton("Example 2", [&](){ LoadWorkspace(SAVEFILES_PATH "example2.workspace"); });
	buttonMenu->AddButton("Clear Workspace", [this](){ this->ClearWorkspace(); });

	componentMenu = std::make_shared<ComponentMenu>(buttonMenu->GetSize().y);
  componentMenu->AddComponent(ComponentTypeGUI::Wire, componentTexture_);
  componentMenu->AddComponent(ComponentTypeGUI::DCSupply, componentTexture_);
  componentMenu->AddComponent(ComponentTypeGUI::Resistor, componentTexture_);
  componentMenu->AddComponent(ComponentTypeGUI::Capacitor, componentTexture_);
  componentMenu->AddComponent(ComponentTypeGUI::Inductor, componentTexture_);
  componentMenu->AddComponent(ComponentTypeGUI::CurrentSupply, componentTexture_);
  componentMenu->AddComponent(ComponentTypeGUI::Supply, componentTexture_);
  componentMenu->AddComponent(ComponentTypeGUI::Diode, componentTexture_);
  componentMenu->AddComponent(ComponentTypeGUI::Ground, componentTexture_);

	workspace =  std::make_shared<Workspace>(componentTexture_, componentMenu, font_, 15);

	SetLayout();
}

void GUI::SolveCircuit() {
	std::cout << "Solving circuit...\n";
	
	auto circuit = workspace->GetCircuit();
	if(!circuit){
		std::cout << "Error getting circuit\n";
	}

	for (auto c: (*circuit).GetNodes()) {
		std::cout << c.GetID() << ": " << std::endl;
	}

	// // solve the circuit
	// auto solver = Solver(*circuit);
	// solver.Solve(*circuit);
}

void GUI::ResizeEvent(int width, int height) {
	// reset window view
	sf::FloatRect visibleArea(0, 0, width, height);
	window_.setView(sf::View(visibleArea));
	
	SetLayout();
}

void GUI::SetLayout() {
	buttonMenu->SetPosition(sf::Vector2f(6, 5));
	componentMenu->SetRelativePosition(buttonMenu->GetPosition() + sf::Vector2f(buttonMenu->GetSize().x, 0.f));

	workspace->SetPosition(sf::Vector2f(0, buttonMenu->GetPosition().y + buttonMenu->GetSize().y + 5));
	workspace->SetSize(sf::Vector2f(window_.getSize().x, window_.getSize().y - workspace->GetPosition().y));
}

void GUI::SaveWorkspace(std::string filepath) {
	std::cout << "Saving file to " << filepath << "...\n";

	WorkspaceInstructions workspaceInstructions = workspace->GetWorkspaceInstructions();

	::SaveWorkspace(workspaceInstructions, filepath);

	std::cout << "Save complete.\n";
}

void GUI::LoadWorkspace(std::string filepath) {
	ClearWorkspace();

	std::cout << "Loading from file " << filepath << "...\n";

	auto instructions = LoadWorkspaceInstructions(filepath);

	workspace->SetWorkspaceFromInstructions(instructions);

	std::cout << "Load complete.\n";
}

void GUI::ClearWorkspace() {
	workspace =  std::make_shared<Workspace>(componentTexture_, componentMenu, font_, 15);
	SetLayout();
}
