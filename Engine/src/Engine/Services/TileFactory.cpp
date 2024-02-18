#include "TileFactory.h"

namespace engine {
	TileFactory::TileFactory(WindowHandler* newHandler) {
		windowHandler = newHandler;

		textureAtlas = new TextureAtlas();
		textureAtlas->addTexture("BRICK", R"(D:\Dev\C++\SFMLSnake\resources\sprites\brick.png)");
	}

	TileFactory::~TileFactory() {
		delete textureAtlas;
		delete windowHandler;
	}

	Tile* TileFactory::spawnTile(TileType objType) {
		Tile* tileToSpawn = nullptr;

		switch (objType) {
			case NOTHING:
				tileToSpawn = new Tile(TileType::NOTHING, nullptr);
				break;
			case SNAKE:
				auto obj = new GameObject(textureAtlas->getTexture("BRICK"));
				windowHandler->addRenderable(obj->sprite);
				tileToSpawn = new Tile(TileType::SNAKE, obj);
				break;
			//case WALL:
			//	//objToSpawn = new Wall(textureAtlas->getTexture("WALL"));
			//	break;
			//case APPLE:
			//	//objToSpawn = new Apple(textureAtlas->getTexture("APPLE"));
			//	break;
		}

		return tileToSpawn;
	}
}