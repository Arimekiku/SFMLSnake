#pragma once

#include "Engine/WindowHandler.h"

namespace engine {
	class Engine {
	public:
		Engine();
		~Engine();

		void run();

	private:
		WindowHandler* windowHandler;
	};
}