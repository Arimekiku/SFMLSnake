#include "Timer.h"

#include <iostream>

namespace engine {
	Timer::Timer(float timeout) {
		target = timeout;
		secondsElapsed = 0;
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

	void Timer::bind(std::function<void()> func) {
		this->func = func;
	}
}