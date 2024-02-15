#pragma once

#include "Core.h"

namespace engine {
	class ENGINE_API Engine {
	public:
		Engine();
		virtual ~Engine();

		void Run();
	};
}
