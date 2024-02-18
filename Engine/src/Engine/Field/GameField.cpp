#include "GameField.h"

#include <iostream>
#include <algorithm>
#include <fstream>

namespace engine {
	Field::Field(WindowHandler* newWindowHandler) {
		rowSize = 0;
		colSize = 0;

		tileFactory = new TileFactory();
		windowHandler = newWindowHandler;

		std::fstream fInput;
		fInput.open(R"(resources\map\map.json)");
		fInput >> currentMap;
		fInput.close();
	}

	std::vector<Tile*> Field::generateField() {
		nlohmann::json mapJSON = currentMap["map"];

		int currentW = 0, currentH = 0;
		for (const auto& obj : mapJSON) {
			std::vector<int> row = obj;
			for (const int value : row) {
				Tile* tile;
				switch (value) {
					case NOTHING:
						tile = tileFactory->spawnTile(NOTHING);
						break;
					case WALL:
						tile = tileFactory->spawnTile(WALL);
						break;
					case SNAKE:
						tile = tileFactory->spawnTile(SNAKE);
						break;
					default:
						std::cout << "Map conversion fail" << std::endl;
						throw std::exception();
				}

				tiles.push_back(tile);
				if (tile->getType() != NOTHING) {
					windowHandler->addRenderable(tile->getObject()->sprite);
				}

				currentW++;
			}

			rowSize = currentW;
			currentW = 0;
			currentH++;
		}

		colSize = currentH;
		update();

		return tiles;
	}

	Tile* Field::getTile(int x, int y) {
		if (x + y * rowSize > rowSize * colSize) {
			std::cout << "Can't get tile";
			throw std::exception();
		}

		return tiles[x + y * rowSize];
	}

	void Field::update() {
		for (auto tile : tiles) {
			updateTile(tile);
		}
	}

	void Field::swapTiles(Tile* first, Tile* second) {
		int firstIndex = getTileIndex(first);
		int secondIndex = getTileIndex(second);

		std::swap(tiles[firstIndex], tiles[secondIndex]);

		updateTile(tiles[firstIndex]);
		updateTile(tiles[secondIndex]);
	}

	void Field::spawnNextAppleTile() {
		Tile* targetTile = nullptr;

		while (targetTile == nullptr || targetTile->getType() != NOTHING) {
			int x = rand() % rowSize;
			int y = rand() % colSize;

			targetTile = getTile(x, y);
		}
		
		changeTile(targetTile, APPLE);
	}

	Tile* Field::changeTile(Tile* tile, TileType newType) {
		int index = getTileIndex(tile);
		if (tile->getType() != NOTHING) {
			windowHandler->removeRenderable(tile->getObject()->sprite);
		}

		Tile* newTile = tileFactory->spawnTile(newType);
		if (newTile->getType() != NOTHING) {
			windowHandler->addRenderable(newTile->getObject()->sprite);
		}
		tiles[index] = newTile;
		updateTile(tiles[index]);

		return tiles[index];
	}

	int Field::getTileIndex(Tile* tile) {
		auto iterator = std::find(tiles.begin(), tiles.end(), tile);
		if (iterator == tiles.end()) {
			std::cout << "Invalid first tile selected";
			throw std::exception();
		}

		int index = iterator - tiles.begin();
		return index;
	}

	void Field::updateTile(Tile* tile) {
		int index = getTileIndex(tile);

		if (tile->getType() != TileType::NOTHING) {
			tile->getObject()->setPosition(sf::Vector2i(index % rowSize, index / rowSize));
		}
	}
}