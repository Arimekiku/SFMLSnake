#include "Engine.h"

class Application : public engine::Engine {
public:
	Application() { }
	~Application() { }
};

int main() {
	Application* app = new Application(); 
	app->run();

	return 0;
}