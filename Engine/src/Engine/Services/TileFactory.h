#pragma once

#include "TextureAtlas.h"
#include "../Field/Tile.h"
#include "../WindowHandler.h"

namespace engine {
	class TileFactory {
	public:
		TileFactory(WindowHandler* newRenderWindow);
		~TileFactory();

		Tile* spawnTile(TileType objType);

	private:
		TextureAtlas* textureAtlas;
		WindowHandler* windowHandler;
	};
}
