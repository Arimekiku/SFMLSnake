#pragma once

#include "../Services/TileFactory.h"
#include "../WindowHandler.h"

namespace engine {
	class Field {
	public:
		Field(int rows, int cols, WindowHandler* newWindowHandler);
		~Field() = default;

		void update();

		std::vector<Tile*> generateField();
		Tile* getTile(int x, int y);
		void swapTiles(Tile* first, Tile* second);
		void spawnNextAppleTile();
		Tile* changeTile(Tile* tile, TileType newType);

	private:
		int getTileIndex(Tile* tile);
		void updateTile(Tile* tile);

		int rowSize, colSize;

		TileFactory* tileFactory;
		WindowHandler* windowHandler;

		std::vector<Tile*> tiles;
	};
}