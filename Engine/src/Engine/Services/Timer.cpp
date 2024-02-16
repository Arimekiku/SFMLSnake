#include "Timer.h"

namespace engine {
	Timer::Timer(float timeout) {
		target = timeout;
	}

	void Timer::tick(float deltaTime) {
		secondsElapsed += deltaTime;

		if (secondsElapsed >= target) {
			func();
			reset();
		}
	}

	void Timer::reset() {
		secondsElapsed = 0;
	}

	void Timer::bind(void(*func)()) {
		this->func = func;
	}
}