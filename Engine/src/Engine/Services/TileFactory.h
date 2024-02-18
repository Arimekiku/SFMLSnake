#pragma once

#include "TextureAtlas.h"
#include "../Field/Tile.h"

namespace engine {
	class TileFactory {
	public:
		TileFactory();
		~TileFactory();

		Tile* spawnTile(TileType objType);

	private:
		TextureAtlas* textureAtlas;
	};
}
