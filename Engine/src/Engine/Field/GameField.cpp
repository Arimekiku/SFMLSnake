#include "GameField.h"

#include <iostream>
#include <algorithm>

namespace engine {
	Field::Field(int rows, int cols, TileFactory* newFactory) {
		tileFactory = newFactory;

		rowSize = rows;
		colSize = cols;
	}

	std::vector<Tile*> Field::generateField() {
		int totalTiles = rowSize * colSize;
		printf("Generating field with %d tiles\n", totalTiles);

		while (totalTiles != 0) {
			if (totalTiles == 150) {
				Tile* tile = tileFactory->spawnTile(SNAKE);
				tiles.push_back(tile);

				totalTiles--;
				continue;
			}

			Tile* tile = tileFactory->spawnTile(NOTHING);
			tiles.push_back(tile);

			totalTiles--;
		}

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
		Tile* newTile = tileFactory->spawnTile(newType);

		int index = getTileIndex(tile);
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