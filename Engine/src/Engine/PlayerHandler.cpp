#include "PlayerHandler.h"

#include <iostream>

namespace engine {
	PlayerHandler::PlayerHandler(Field* newField, Tile* startTile)
	{
		gameField = newField;
		head = startTile;

		movementVector = sf::Vector2i(0, 1);
	}

	void PlayerHandler::movePlayer()
	{
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
			newSegment = gameField->changeTile(oldTile, TileType::SNAKE);
		} else {
			sf::Vector2i lastPosition = tail[tail.size() - 1]->getObject()->getPosition();
			Tile* oldTile = gameField->getTile(lastPosition.x + movementVector.x, lastPosition.y - movementVector.y);
			newSegment = gameField->changeTile(oldTile, TileType::SNAKE);
		}

		tail.push_back(newSegment);
	}

	void PlayerHandler::checkCollision(Tile* collisionTile)
	{
		switch (collisionTile->getType()) {
			case TileType::NOTHING: 
				break;
			case TileType::APPLE:
				addSegment();
				gameField->spawnNextAppleTile();
				break;
			case TileType::SNAKE:
			case TileType::WALL:
				std::cout << "You lose";
				break;
		}
	}
}