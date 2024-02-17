#include "GameObjectFactory.h"

namespace engine {
	GameObjectFactory::GameObjectFactory() {
		textureAtlas = new TextureAtlas();
		textureAtlas->addTexture("BRICK", R"(D:\Dev\C++\SFMLSnake\resources\sprites\brick.png)");
	}

	GameObjectFactory::~GameObjectFactory() {
		delete textureAtlas;
	}

	GameObject* GameObjectFactory::spawnObject(GameObjectType objType) {
		GameObject* objToSpawn = nullptr;

		switch (objType) {
			case SNAKE_SEGMENT:
				objToSpawn = new GameObject(textureAtlas->getTexture("BRICK"));
				break;
			case WALL:
				//objToSpawn = new Wall(textureAtlas->getTexture("WALL"));
				break;
			case APPLE:
				//objToSpawn = new Apple(textureAtlas->getTexture("APPLE"));
				break;
		}

		return objToSpawn;
	}
}