#include "TextureAtlas.h"

#include <iostream>

namespace engine {
	TextureAtlas::TextureAtlas() {

	}

	TextureAtlas::~TextureAtlas() {
		for (const auto& texture : textures) {
			delete texture.second;
		}
	}

	sf::Texture* TextureAtlas::getTexture(const std::string& textureName) {
		sf::Texture* possibleTexture = textures.at(textureName);
		if (possibleTexture == NULL) {
			std::cout << "Can't find texture: " << textureName << std::endl;
			return nullptr;
		}

		return possibleTexture;
	}

	void TextureAtlas::addTexture(const std::string& textureName, const std::string& texturePath) {
		sf::Texture* newTexture = new sf::Texture();
		newTexture->loadFromFile(texturePath);

		textures.insert({ textureName, newTexture });
	}
}