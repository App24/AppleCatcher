#pragma once

#include <SFML/Graphics.hpp>

class UIButton {
public:
	UIButton();

	void draw();

	bool isClicked();

	sf::Text& getButtonText();
	sf::Sprite& getButtonSprite();

private:
	sf::Text m_text;
	sf::Sprite m_button;

	void m_centerText();
};