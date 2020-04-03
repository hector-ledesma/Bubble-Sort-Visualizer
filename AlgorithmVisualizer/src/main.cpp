#include "../Model/window.h"
#include "../Model/text.h"
#include "../Model/rect.h"
#undef main

class Item {
public:
	Item(int id, int x, int h);

	int get_id();
	
private:
	int _id;
	int _x, _h;
	SDL_Rect* itemRect = nullptr;
};

Item::Item(int id, int x, int h) : _id(id), _x(x), _h(h)
{
	Rect rect(20, _h, _x, 20, 255, 255, 255, 255);
}

void flip(SDL_Rect& rect1, SDL_Rect& rect2) {
	int hold = rect1.x;
	rect1.x = rect2.x;
	rect2.x = hold;
}

int main(int argc, char *argv) {
	// ------------------------------------------------------------------------------
	SDL_Rect hit1;

	hit1.w = 20;
	hit1.h = 200;

	hit1.x = 20;
	hit1.y = 380;

	SDL_Rect hit2;

	hit2.w = 20;
	hit2.h = 300;

	hit2.x = 60;
	hit2.y = 280;

	SDL_Rect hit3;

	hit3.w = 20;
	hit3.h = 350;

	hit3.x = 100;
	hit3.y = 230;

	SDL_Rect hit4;

	hit4.w = 20;
	hit4.h = 400;

	hit4.x = 140;
	hit4.y = 180;

	// ------------------------------------------------------------------------------

	SDL_Event event;

	Window window("Algorithm Visualizer - Hector Ledesma", 800, 600); // Creating the window will initialize everything.
	Text title(Window::renderer, "res/msyh_console.ttf", 24, "This is a test", {255, 255, 255, 255});
	//Rect rect1(20, 200, 20, 380, 255, 255, 255, 255);
	//Rect rect2(20, 400, 60, 180, 255, 255, 255, 255);

	while (!window.isClosed()) {
		if (SDL_PollEvent(&event)) {
			window.pollEvents(event);
		}
		title.display(Window::renderer, 20, 20);

		// ------------------------------------------------------------------------------
		SDL_SetRenderDrawColor(Window::renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(Window::renderer, &hit1);
		SDL_RenderFillRect(Window::renderer, &hit2);
		SDL_RenderFillRect(Window::renderer, &hit3);
		SDL_RenderFillRect(Window::renderer, &hit4);

		flip(hit1, hit4);
		SDL_Delay(500);
		// ------------------------------------------------------------------------------

		window.clear(); // Always leave this at the bottom, as THIS is what updates the screen.
	}

	return 0;
}