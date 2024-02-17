#pragma once

#include "GameObject.h"

namespace engine {
	class Player {
	public:
		Player(GameObject* head);
		~Player() = default;

		void setMovementVector(sf::Vector2i newMovementVector);
		void addSegment(GameObject* newSegment);
		void move();

	private:
		GameObject* head;
		std::vector<GameObject*> tail;

		sf::Vector2i movementVector;
	};
}