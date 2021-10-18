#pragma once
#include <SFML/Graphics.hpp>

class UIText {
public:
	UIText();

	sf::Text& getText();

	void draw();

private:
	sf::Text m_text;
};