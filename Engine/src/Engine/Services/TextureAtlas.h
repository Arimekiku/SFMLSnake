#pragma once

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>

namespace engine {
	class TextureAtlas {
	public:
		TextureAtlas() = default;
		~TextureAtlas();

		sf::Texture* getTexture(std::string textureName);

		void addTexture(std::string textureName, std::string texturePath);

	private: 
		std::unordered_map<std::string, sf::Texture*> textures;
	};
}