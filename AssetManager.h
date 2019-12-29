#pragma once
#include <SFML\Graphics.hpp>
#include <map>

class AssetManager
{
public:
	void LoadTexture(std::string name, std::string fileName);
	void LoadFont(std::string name, std::string fileName);

	sf::Texture &GetTexture(std::string name);
	sf::Font &GetFont(std::string name);
private:
	std::map<std::string, sf::Texture> _textures;
	std::map<std::string, sf::Font> _fonts;
};

