#include "GameObject.h"

namespace engine {
	GameObject::GameObject(const sf::Texture* texture) {
		sprite = new sf::Sprite();
		sprite->setTexture(*texture);

		textureSize = texture->getSize();
		auto newOrigin = static_cast<sf::Vector2f>(textureSize / 2u);
		sprite->setOrigin(newOrigin);
	}

	GameObject::~GameObject() {
		delete sprite;
	}

	sf::Vector2i GameObject::getPosition() const {
		return worldPos;
	}

	void GameObject::setPosition(sf::Vector2i newPosition) {
		worldPos = newPosition;
		sprite->setPosition(sf::Vector2f(worldPos.x * textureSize.x, worldPos.y * textureSize.y));
	}
}