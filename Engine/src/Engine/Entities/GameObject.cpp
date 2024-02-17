#include "GameObject.h"

namespace engine {
	GameObject::GameObject(const sf::Vector2i initPos, const sf::Texture* texture) {
		sprite = new sf::Sprite();
		sprite->setTexture(*texture);

		auto textureSize = texture->getSize();
		auto newOrigin = static_cast<sf::Vector2f>(textureSize / 2u);
		sprite->setOrigin(newOrigin);

		worldPos = initPos;
		sprite->setPosition(sf::Vector2f(worldPos));
	}
}