#pragma once

#include "../Services/TileFactory.h"

namespace engine {
	class Field {
	public:
		Field(int rows, int cols, TileFactory* newFactory);
		~Field() = default;

		void update();

		std::vector<Tile*> generateField();
		Tile* getTile(int x, int y);
		void swapTiles(Tile* first, Tile* second);
		Tile* changeTile(Tile* tile, TileType newType);

	private:
		int getTileIndex(Tile* tile);
		void updateTile(Tile* tile);

		int rowSize, colSize;

		TileFactory* tileFactory;
		std::vector<Tile*> tiles;
	};
}