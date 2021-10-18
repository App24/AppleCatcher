#include "uiText.h"
#include "../Misc/assetManager.h"
#include "../Display/display.h"

UIText::UIText() {
	m_text.setFont(AssetManager::getFont("Arial"));
}

sf::Text& UIText::getText() {
	return m_text;
}

void UIText::draw() {
	Display::getWindow().draw(m_text);
}