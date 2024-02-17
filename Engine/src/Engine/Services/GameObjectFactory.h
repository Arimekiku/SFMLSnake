#pragma once

#include "TextureAtlas.h"
#include "../Entities/GameObject.h"

namespace engine {
	enum GameObjectType {
		SNAKE_SEGMENT,
		WALL,
		APPLE
	};

	class GameObjectFactory {
	public:
		GameObjectFactory();
		~GameObjectFactory();

		GameObject* spawnObject(GameObjectType objType);

	private:
		TextureAtlas* textureAtlas;
	};
}
