#include "TileFactory.h"

namespace engine {
	TileFactory::TileFactory(WindowHandler* newHandler) {
		windowHandler = newHandler;

		textureAtlas = new TextureAtlas();
		textureAtlas->addTexture("BRICK", R"(D:\Dev\C++\SFMLSnake\resources\sprites\brick.png)");
		textureAtlas->addTexture("APPLE", R"(D:\Dev\C++\SFMLSnake\resources\sprites\apple.png)");
	}

	TileFactory::~TileFactory() {
		delete textureAtlas;
		delete windowHandler;
	}

	Tile* TileFactory::spawnTile(TileType objType) {
		Tile* tileToSpawn = nullptr;

		if (objType == WALL) {

		} else if (objType == SNAKE) {
			auto snake = new GameObject(textureAtlas->getTexture("BRICK"));
			windowHandler->addRenderable(snake->sprite);
			tileToSpawn = new Tile(TileType::SNAKE, snake);
		} else if (objType == APPLE) {
			auto apple = new GameObject(textureAtlas->getTexture("APPLE"));
			windowHandler->addRenderable(apple->sprite);
			tileToSpawn = new Tile(TileType::APPLE, apple);
		} else {
			tileToSpawn = new Tile(TileType::NOTHING, nullptr);
		}

		return tileToSpawn;
	}
}