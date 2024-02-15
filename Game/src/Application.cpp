#include "Engine.h"

class Application : public engine::Window {
public:
	Application() { }
	~Application() { }
};

int main() {
	Application* app = new Application(); 
	app->Run();

	return 0;
}