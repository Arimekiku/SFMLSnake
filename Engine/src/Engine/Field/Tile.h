#pragma once

#include "../Entities/GameObject.h"

namespace engine {
	enum TileType {
		NOTHING,
		WALL,
		SNAKE,
		APPLE
	};

	class Tile {
	public:
		Tile(TileType newType, GameObject* newObject);
		~Tile() = default;

		TileType getType();
		GameObject* getObject();

	private:
		TileType type;
		GameObject* object;
	};
}