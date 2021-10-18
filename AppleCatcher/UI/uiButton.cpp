#include "uiButton.h"
#include "../Misc/assetManager.h"
#include "../Display/display.h"
#include "../Input/mouse.h"

UIButton::UIButton() {
	m_text.setFont(AssetManager::getFont("Arial"));
	m_button.setTexture(AssetManager::getTexture("Button"));
}

void UIButton::draw() {
	m_centerText();
	Display::getWindow().draw(m_button);
	Display::getWindow().draw(m_text);
}

bool UIButton::isClicked() {
	if (Mouse::isButtonPressed(sf::Mouse::Left)) {
		sf::Vector2i mousePos = Mouse::getMousePosition();
		sf::Vector2f position = m_button.getPosition();
		sf::Vector2u size = m_button.getTexture()->getSize();
		if (mousePos.x > position.x && mousePos.y > position.y && mousePos.x < position.x + size.x && mousePos.y < position.y + size.y) {
			return true;
		}
	}
	return false;
}

sf::Text& UIButton::getButtonText() {
	return m_text;
}

sf::Sprite& UIButton::getButtonSprite() {
	return m_button;
}

void UIButton::m_centerText() {
	m_text.setOrigin(sf::Vector2f((m_text.getLocalBounds().width - m_text.getLocalBounds().left) / 2.f, (m_text.getLocalBounds().height - m_text.getLocalBounds().top)));
	float yPos = m_button.getTexture()->getSize().y / 2.f;
	m_text.setPosition(m_button.getPosition() + sf::Vector2f(m_button.getTexture()->getSize().x / 2.f, yPos));
}