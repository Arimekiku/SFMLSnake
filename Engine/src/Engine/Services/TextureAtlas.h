#pragma once

#include "SFML/Graphics.hpp"
#include <unordered_map>
#include <string>

namespace engine {
	class TextureAtlas {
	public:
		TextureAtlas();
		~TextureAtlas();

		sf::Texture* getTexture(const std::string& textureName);

		void addTexture(const std::string& textureName, const std::string& texturePath);

	private: 
		std::unordered_map<std::string, sf::Texture*> textures;
	};
}