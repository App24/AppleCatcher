#pragma once
#include <SFML\Graphics.hpp>

class InputManager
{
public:
	bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
	bool IsKeyPressed(sf::Keyboard::Key key);
	bool IsKeyHeld(sf::Keyboard::Key key);
	
	sf::Vector2i GetMousePosition(sf::RenderWindow &window);
private:
	bool _isKeyPressed[sf::Keyboard::KeyCount];
	bool _isMouseKeyPressed[sf::Mouse::ButtonCount];
};

