#include "../Model/window.h"
#include "../Model/text.h"
#include "../Model/rect.h"
#include <algorithm>
#include <array>
#include <iostream>
#undef main


void flip(SDL_Rect& rect1, SDL_Rect& rect2) {
	int hold = rect1.x;
	rect1.x = rect2.x;
	rect2.x = hold;
}

void bubbleSort(int* count, SDL_Rect *arr[], int size) {
	/*
	Receive whole array? Or only receive current item being held and the next one ot be compared?
	I believe the whole array should be passed, as that would give the function full freedom and control.

		1.:	Count how many swaps have happened.
			a.:	If 0, terminate.
		2.:	
	*/

	for (int i = 0; i < size; i++) {
		std::cout << "Rect at index: " << i << " has a height of: " << arr[i]->h << std::endl;
	}

	*count += 1; // Why doesn't ++ work here?
	SDL_Delay(50000);
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

	int positions[] = {20, 60, 100, 140};
	SDL_Rect* items[] = { &hit1, &hit2, &hit3, &hit4 };

	for (int i = 0; i < 4 ; i++) {
		items[i]->x = positions[i];
		std::cout << "Index --- " << i << " --- height --- " << items[i]->h << std::endl;
	}
	// ------------------------------------------------------------------------------

	SDL_Event event;

	Window window("Algorithm Visualizer - Hector Ledesma", 800, 600); // Creating the window will initialize everything.
	Text title(Window::renderer, "res/msyh_console.ttf", 24, "This is a test", {255, 255, 255, 255});

	int bubbleCount = 0;
	while (!window.isClosed()) {

		if (SDL_PollEvent(&event)) {
			window.pollEvents(event);
		}
		title.display(Window::renderer, 20, 20);

		// ------------------------------------------------------------------------------
		SDL_SetRenderDrawColor(Window::renderer, 255, 255, 255, 255);

		SDL_RenderFillRect(Window::renderer, items[0]);
		SDL_RenderFillRect(Window::renderer, items[1]);
		SDL_RenderFillRect(Window::renderer, items[2]);
		SDL_RenderFillRect(Window::renderer, items[3]);

		//flip(*items[0], *items[2]);
		//SDL_Delay(500);
		
		// ------------------------------------------------------------------------------

		window.clear(); // Always leave this at the bottom, as THIS is what updates the screen.
		bubbleSort(&bubbleCount, items, 4);
	}

	return 0;
}