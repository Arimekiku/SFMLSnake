#include "PlayerHandler.h"

namespace engine {
	PlayerHandler::PlayerHandler(Field* newField, Tile* startTile)
	{
		gameField = newField;
		head = startTile;

		movementVector = sf::Vector2i(0, 1);
	}

	void PlayerHandler::movePlayer()
	{
		auto lastStoredPosition = head->getObject()->getPosition();
		auto nextPosition = lastStoredPosition + movementVector;

		auto nextTileToSwap = gameField->getTile(nextPosition.x, nextPosition.y);
		gameField->swapTiles(head, nextTileToSwap);

		for (auto segment : tail) {
			nextTileToSwap = gameField->getTile(lastStoredPosition.x, lastStoredPosition.y);
			lastStoredPosition = segment->getObject()->getPosition();
			gameField->swapTiles(segment, nextTileToSwap);
		}
	}

	void PlayerHandler::setMovementVector(sf::Vector2i newMovementVector) {
		movementVector = newMovementVector;
	}

	void PlayerHandler::addSegment() {
		Tile* newSegment;

		if (tail.empty()) {
			sf::Vector2i headPosition = head->getObject()->getPosition();
			Tile* oldTile = gameField->getTile(headPosition.x + movementVector.x, headPosition.y - movementVector.y);
			newSegment = gameField->changeTile(oldTile, TileType::SNAKE);
		} else {
			sf::Vector2i lastPosition = tail[tail.size() - 1]->getObject()->getPosition();
			Tile* oldTile = gameField->getTile(lastPosition.x + movementVector.x, lastPosition.y - movementVector.y);
			newSegment = gameField->changeTile(oldTile, TileType::SNAKE);
		}

		tail.push_back(newSegment);
	}
}