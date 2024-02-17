#pragma once

#include "GameObject.h"

namespace engine {
	class Player : public GameObject {
	public:
		Player(const sf::Vector2i initPos, const sf::Texture* texture);
		~Player() = default;

		void update() override;

		void setMovementVector(sf::Vector2i newMovementVector);
		void move();

	private:
		sf::Vector2i movementVector;
	};
}