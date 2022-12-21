#ifndef __COMPONENT_TEXTURE_CONFIG_H__
#define __COMPONENT_TEXTURE_CONFIG_H__

#include "component_type.hpp"
#include <map>
#include <math.h>
#include <SFML/Graphics/Rect.hpp>

/*

Todo:
- Add resource filepaths to cmake as define macros
- move sfml vector operators somewhere where they belong
- componet clips should be somewhere else
- this file shouldnt exist (!!)

*/

inline const char* componentTextureFile = RESOURCES_PATH "components.png";
inline const char* defaultFontFile = RESOURCES_PATH "Ubuntu-R.ttf";

inline const std::map<ComponentTypeGUI, sf::IntRect> componentClips = {
	{ComponentTypeGUI::Diode,    			sf::IntRect(200 * 0, 0, 200, 150)},
	{ComponentTypeGUI::Capacitor,			sf::IntRect(200 * 1, 0, 200, 150)},
	{ComponentTypeGUI::Inductor, 			sf::IntRect(200 * 2, 0, 200, 150)},
	{ComponentTypeGUI::Resistor, 			sf::IntRect(200 * 3, 0, 200, 150)},
	{ComponentTypeGUI::DCSupply, 			sf::IntRect(200 * 4, 0, 200, 150)},
	{ComponentTypeGUI::Supply,   			sf::IntRect(200 * 5, 0, 200, 150)},
	{ComponentTypeGUI::Ground,   			sf::IntRect(200 * 6, 0, 200, 150)},
	{ComponentTypeGUI::CurrentSupply, sf::IntRect(200 * 7, 0, 200, 150)},
	{ComponentTypeGUI::Wire,					sf::IntRect(200 * 8, 0, 200, 150)},
	{ComponentTypeGUI::None,					sf::IntRect(0, 0, 1, 1)}
};

inline sf::Vector2f operator*(sf::Vector2f vec, float scalar){
	return sf::Vector2f(vec.x * scalar, vec.y * scalar);
}

inline std::ostream& operator<<(std::ostream& os, sf::FloatRect rect){
	os << "Rect(" << rect.left << ", " << rect.top << ", " << rect.width << "," << rect.height << ")";
	return os;
}

inline std::ostream& operator<<(std::ostream& os, sf::Vector2f vec){
	os << "Vector2f(" << vec.x << ", " << vec.y << ")";
	return os;
}

inline sf::Vector2f RotateVector(sf::Vector2f vector, float angle){
	float length = std::hypot(vector.y, vector.x);
	float vecAngle = std::atan2(vector.y, vector.x);
	return sf::Vector2f(
		length * std::cos(angle + vecAngle),
		length * std::sin(angle + vecAngle)
	);
}

#endif // __COMPONENT_TEXTURE_CONFIG_H__