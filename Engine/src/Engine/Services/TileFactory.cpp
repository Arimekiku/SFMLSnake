#include "TileFactory.h"

namespace engine {
	TileFactory::TileFactory() {
		textureAtlas = new TextureAtlas();
		textureAtlas->addTexture("BRICK", R"(D:\Dev\C++\SFMLSnake\resources\sprites\brick.png)");
		textureAtlas->addTexture("APPLE", R"(D:\Dev\C++\SFMLSnake\resources\sprites\apple.png)");
		textureAtlas->addTexture("SNAKE_HEAD", R"(D:\Dev\C++\SFMLSnake\resources\sprites\snake_head.png)");
		textureAtlas->addTexture("SNAKE_BODY", R"(D:\Dev\C++\SFMLSnake\resources\sprites\snake_body.png)");
	}

	TileFactory::~TileFactory() {
		delete textureAtlas;
	}

	Tile* TileFactory::spawnTile(TileType objType) {
		Tile* tileToSpawn = nullptr;

		if (objType == WALL) {
			auto wall = new GameObject(textureAtlas->getTexture("BRICK"));
			tileToSpawn = new Tile(objType, wall);
		} else if (objType == SNAKE) {
			auto snake = new GameObject(textureAtlas->getTexture("SNAKE_HEAD"));
			tileToSpawn = new Tile(objType, snake);
		} else if (objType == SNAKE_BODY) {
			auto snake_body = new GameObject(textureAtlas->getTexture("SNAKE_BODY"));
			tileToSpawn = new Tile(objType, snake_body);
		} else if (objType == APPLE) {
			auto apple = new GameObject(textureAtlas->getTexture("APPLE"));
			tileToSpawn = new Tile(objType, apple);
		} else {
			auto nothing = nullptr;
			tileToSpawn = new Tile(objType, nothing);
		}

		return tileToSpawn;
	}
}