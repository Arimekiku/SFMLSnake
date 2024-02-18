#include "PlayerHandler.h"

#include <iostream>

namespace engine {
	PlayerHandler::PlayerHandler(Field* newField, Tile* startTile) {
		gameField = newField;
		head = startTile;

		movementVector = sf::Vector2i(0, 1);
	}

	void PlayerHandler::movePlayer() {
		sf::Vector2i headPosition = head->getObject()->getPosition();
		Tile* nextTile = gameField->getTile(headPosition.x + movementVector.x, headPosition.y + movementVector.y);

		auto lastStoredPosition = headPosition;
		auto nextPosition = lastStoredPosition + movementVector;

		auto nextTileToSwap = gameField->getTile(nextPosition.x, nextPosition.y);
		gameField->swapTiles(head, nextTileToSwap);

		for (auto segment : tail) {
			nextTileToSwap = gameField->getTile(lastStoredPosition.x, lastStoredPosition.y);
			lastStoredPosition = segment->getObject()->getPosition();
			gameField->swapTiles(segment, nextTileToSwap);
		}

		checkCollision(nextTile);
	}

	void PlayerHandler::setMovementVector(sf::Vector2i newMovementVector) {
		movementVector = newMovementVector;
	}

	void PlayerHandler::addSegment() {
		Tile* newSegment;

		if (tail.empty()) {
			sf::Vector2i headPosition = head->getObject()->getPosition();
			Tile* oldTile = gameField->getTile(headPosition.x + movementVector.x, headPosition.y - movementVector.y);
			newSegment = gameField->changeTile(oldTile, SNAKE_BODY);
		} else {
			auto firstTailElemPosition = tail[tail.size() - 1]->getObject()->getPosition();
			auto secondTailElemPosition = sf::Vector2i();

			if (tail.size() == 1) {
				secondTailElemPosition = head->getObject()->getPosition();
			} else {
				secondTailElemPosition = tail[tail.size() - 2]->getObject()->getPosition();
			}
			sf::Vector2i spawnPosition = 2 * firstTailElemPosition - secondTailElemPosition;

			Tile* oldTile = gameField->getTile(spawnPosition.x, spawnPosition.y);
			newSegment = gameField->changeTile(oldTile, SNAKE_BODY);
		}

		tail.push_back(newSegment);
	}

	void PlayerHandler::checkCollision(Tile* collisionTile) {
		switch (collisionTile->getType()) {
			case NOTHING: 
				break;
			case APPLE:
				addSegment();
				gameField->spawnNextAppleTile();
				break;
			case SNAKE_BODY:
			case WALL:
				std::cout << "You lose";
				break;
		}
	}
}