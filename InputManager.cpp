#include "InputManager.h"

bool InputManager::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {
	if (sf::Mouse::isButtonPressed(button)) {
		sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);

		if (tempRect.contains(sf::Mouse::getPosition(window)) && !_isMouseKeyPressed[button]) {
			_isMouseKeyPressed[button] = true;
			return true;
		}
	}
	else if (!sf::Mouse::isButtonPressed(button)) {
		_isMouseKeyPressed[button] = false;
	}
	return false;
}

bool InputManager::IsKeyPressed(sf::Keyboard::Key key) {
	if (sf::Keyboard::isKeyPressed(key) && !_isKeyPressed[key]) {
		_isKeyPressed[key] = true;
		return true;
	}else if (!sf::Keyboard::isKeyPressed(key)){
		_isKeyPressed[key] = false;
	}
	return false;
}

bool InputManager::IsKeyHeld(sf::Keyboard::Key key) {
	return sf::Keyboard::isKeyPressed(key);
}

sf::Vector2i InputManager::GetMousePosition(sf::RenderWindow &window) {
	return sf::Mouse::getPosition(window);
}
