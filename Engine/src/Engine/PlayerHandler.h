#pragma once

#include "Field/GameField.h"

namespace engine {
	class PlayerHandler {
	public:
		PlayerHandler(Field* newField, Tile* startTile);
		~PlayerHandler() = default;

		void movePlayer();
		void setMovementVector(sf::Vector2i newMovementVector);
		void addSegment();

	private:
		void checkCollision(Tile* collisionTile);

		Field* gameField;

		Tile* head;
		std::vector<Tile*> tail;

		sf::Vector2i movementVector;
	};
}