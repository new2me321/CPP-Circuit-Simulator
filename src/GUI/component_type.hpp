#ifndef __COMPONENT_TYPE_H__
#define __COMPONENT_TYPE_H__

#include <string>

/**
 * @brief ComponetTypeGUI is used for determining component type
 * 
 * @details 
 * 	Used by ComponentMenu, Workspace and ComponentElement
 * 
 * @see component_element.hpp
 */
enum class ComponentTypeGUI{
	Diode,
	Capacitor,
	Inductor,
	Resistor,
	DCSupply,
	Supply,
	Ground,
	CurrentSupply,
	Wire,
	None
};

/**
 * @brief Create string representation of ComponentTypeGUI
 * 
 * @param type 
 * @return std::string 
 */
inline std::string ComponentTypeToString(ComponentTypeGUI type){
	switch(type){
		case ComponentTypeGUI::Diode: 				return "Diode";
		case ComponentTypeGUI::Capacitor: 		return "Capacitor";
		case ComponentTypeGUI::Inductor: 			return "LInductor";
		case ComponentTypeGUI::Resistor: 			return "Resistor";
		case ComponentTypeGUI::DCSupply: 			return "VoltageSupply";
		case ComponentTypeGUI::Supply: 				return "ASupply";
		case ComponentTypeGUI::CurrentSupply: return "ISupply";
		case ComponentTypeGUI::Ground: 				return "Ground";
		case ComponentTypeGUI::Wire: 					return "Wire";
		case ComponentTypeGUI::None: 					return "None";
	}
	return "ComponentTypeGUI";
}

inline ComponentTypeGUI GetComponentElementTypeFromName(std::string name){
	if(!name.size())
		return ComponentTypeGUI::None;

	char c = name.front();

	switch(c){
		case 'R':
			return ComponentTypeGUI::Resistor;
		case 'L':
			return ComponentTypeGUI::Inductor;
		case 'C':
			return ComponentTypeGUI::Capacitor;
		case 'V':
			return ComponentTypeGUI::DCSupply;
		case 'D':
			return ComponentTypeGUI::Diode;
		case 'G':
			return ComponentTypeGUI::Ground;
		case 'A':
			return ComponentTypeGUI::Supply;
		case 'I':
			return ComponentTypeGUI::CurrentSupply;
		default:
			return ComponentTypeGUI::None;
	}
}

// inline std::string GetComponentNameFromType(ComponentTypeGUI type){
// 	switch(type){
// 		case ComponentTypeGUI::Resistor:
// 			return "Resistor";
// 		case ComponentTypeGUI::Inductor:
// 			return "Inductor";
// 		case ComponentTypeGUI::Capacitor:
// 			return "Capacitor";
// 		case ComponentTypeGUI::DCSupply:
// 			return "VoltageSource";
// 		default ComponentTypeGUI::None:
// 			return "None";
// 	}
// }

#endif // __COMPONENT_TYPE_H__