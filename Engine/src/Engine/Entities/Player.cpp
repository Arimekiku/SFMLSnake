#include "Player.h"

#include <ranges>

namespace engine {
	Player::Player(GameObject* head) {
		this->head = head;

		movementVector = sf::Vector2i(0, 1);
	}

	void Player::move() {
		int tailSize = tail.size();
		auto headPosition = head->getPosition();

		if (tailSize > 0) {
			for (int i = tailSize - 1; i >= 1; i--) {
				tail[i]->setPosition(tail[i - 1]->getPosition());
			}

			tail[0]->setPosition(headPosition);
		}

		head->setPosition(sf::Vector2i(headPosition + movementVector));
	}

	void Player::setMovementVector(sf::Vector2i newMovementVector) {
		movementVector = newMovementVector;
	}

	void Player::addSegment(GameObject* newObject) {
		tail.push_back(newObject);
	}
}