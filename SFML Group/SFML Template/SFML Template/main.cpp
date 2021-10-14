#include <SFML/Graphics.hpp>

#define SCREEN_WIDTH 720
#define SCREEN_HEIGHT 480

using namespace sf;

int main() 
{
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "MY_WINDOW");

	while (window.isOpen()) 
	{ 
		// handle event

		window.clear();

		window.display();
	}

	return EXIT_SUCCESS;
}