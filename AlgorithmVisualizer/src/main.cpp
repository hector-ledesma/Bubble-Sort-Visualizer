#include "../Model/window.h"
#include "../Model/text.h"
#undef main

int main(int argc, char *argv) {

	Window window("Algorithm Visualizer - Hector Ledesma", 800, 600); // Creating the window will initialize everything.
	Text title(Window::renderer, "res/msyh_console.ttf", 24, "This is a test", {255, 255, 255, 255});
	SDL_Event event;

	while (!window.isClosed()) {
		if (SDL_PollEvent(&event)) {
			window.pollEvents(event);
		}
		title.display(Window::renderer, 20, 20);
		window.clear(); // Always leave this at the bottom, as THIS is what updates the screen.
	}

	return 0;
}