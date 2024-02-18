#include "TileFactory.h"

namespace engine {
	TileFactory::TileFactory() {
		textureAtlas = new TextureAtlas();
		textureAtlas->addTexture("BRICK", R"(D:\Dev\C++\SFMLSnake\resources\sprites\brick.png)");
		textureAtlas->addTexture("APPLE", R"(D:\Dev\C++\SFMLSnake\resources\sprites\apple.png)");
	}

	TileFactory::~TileFactory() {
		delete textureAtlas;
	}

	Tile* TileFactory::spawnTile(TileType objType) {
		Tile* tileToSpawn = nullptr;

		if (objType == WALL) {

		} else if (objType == SNAKE) {
			auto snake = new GameObject(textureAtlas->getTexture("BRICK"));
			tileToSpawn = new Tile(TileType::SNAKE, snake);
		} else if (objType == APPLE) {
			auto apple = new GameObject(textureAtlas->getTexture("APPLE"));
			tileToSpawn = new Tile(TileType::APPLE, apple);
		} else {
			auto nothing = nullptr;
			tileToSpawn = new Tile(TileType::NOTHING, nothing);
		}

		return tileToSpawn;
	}
}