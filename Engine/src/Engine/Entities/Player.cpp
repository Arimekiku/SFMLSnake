#include "Player.h"

namespace engine {
	Player::Player(const sf::Vector2i initPos, const sf::Texture* texture) 
		: GameObject::GameObject(initPos, texture) {
		movementVector = { 0, -1 };
	}

	void Player::update() {

	}

	void Player::move() {
		auto textureSize = sprite->getTexture()->getSize();

		sf::Vector2i movementAmount = sf::Vector2i(textureSize.x * movementVector.x, textureSize.y* movementVector.y);
		worldPos = sf::Vector2i { worldPos + movementAmount };
		sprite->setPosition(sf::Vector2f{ worldPos });
	}

	void Player::setMovementVector(sf::Vector2i newMovementVector) {
		movementVector = newMovementVector;
	}
}