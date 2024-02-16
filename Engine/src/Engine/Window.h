#pragma once

#include "Services/TextureAtlas.h"
#include "GameObject.h"

namespace engine {
	class Window {
	public:
		Window();
		virtual ~Window();

		void run();
		void addGameObject(GameObject* newObject);

	private:
		TextureAtlas* textureAtlas;

		std::vector<GameObject*> objects;
	};
}