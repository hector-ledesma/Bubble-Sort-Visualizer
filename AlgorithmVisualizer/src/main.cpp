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

void bubbleSort(bool& finished, SDL_Rect **arr, int size, Window &window) {
	/*
	Receive whole array? Or only receive current item being held and the next one ot be compared?
	I believe the whole array should be passed, as that would give the function full freedom and control.

		1.:	Count how many swaps have happened.
				a.:	If 0, terminate.
		2.:	Grab index to be compared against other items. (Start with 0 by default).
		3.:	Compare current index with the next item
				a.:	If held item is smaller (.height) leave it at that location, and make the next item the held item.
				b.:	If held item is larger, move held item's pointer to a temp location, move the adjacent smaller item to held item's index location, then move held item to adjacent item index. Then add +1 to count.
	*/
	int held = 0;
	std::cout << "We enter the function" << std::endl;

	while (!finished) {
		std::cout << "We enter the while loop" << std::endl;
		int count = 0;

		for (int i = 1; i < size; i++) {
			//std::cout << "We enter the for loop." << std::endl;
			if (arr[held]->h < arr[i]->h) {
				std::cout << "Held (" << held << ").h is NOT larger than index(" << i << ").h" << std::endl;
				held = i;
				SDL_RenderClear(Window::renderer);
				SDL_Delay(100);
				std::cout << "no switch" << std::endl;
				std::cout << "Held is now " << held << std::endl;
			}
			else if (arr[held]->h > arr[i]->h) {
				std::cout << "Held (" << held << ").h is larger than index(" << i << ").h" << std::endl;

				SDL_Rect* placeholder = arr[held];
				std::cout << "Placeholder is now held: " << placeholder->h << std::endl;
				arr[held] = arr[i];
				arr[i] = placeholder;

				count++;
				held = i;
				SDL_RenderClear(Window::renderer);
				SDL_Delay(300);
				std::cout << "made a switch" << std::endl;
			}
			std::cout << "New order: " << std::endl;
			for (int j = 0; j < size; j++) {
				std::cout << "\t" << j+1 << " -- x : " << arr[j]->x << " -- h :" << arr[j]->h << std::endl;
			}
			for (int o = 0; o < 4; o++) {
				items[i]->x = positions[i];
				//std::cout << "Index --- " << i << " --- height --- " << items[i]->h << std::endl;
			}
		}

		if (count == 0) {
			finished = true;
		}
		else {
			held = 0;
		}
		

	}
	
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
	SDL_Rect* items[] = { &hit3, &hit1, &hit4, &hit2 };
	for (int i = 0; i < 4; i++) {
		items[i]->x = positions[i];
		//std::cout << "Index --- " << i << " --- height --- " << items[i]->h << std::endl;
	}
	
	// ------------------------------------------------------------------------------

	SDL_Event event;

	Window window("Algorithm Visualizer - Hector Ledesma", 800, 600); // Creating the window will initialize everything.
	Text title(Window::renderer, "res/msyh_console.ttf", 24, "This is a test", {255, 255, 255, 255});

	bool finishSort = false;

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
		
		for (int i = 0; i < 4; i++) {
			items[i]->x = positions[i];
			//std::cout << "Index --- " << i << " --- height --- " << items[i]->h << std::endl;
		}
		window.clear(); // Always leave this at the bottom, as THIS is what updates the screen.
		SDL_Delay(300);
		bubbleSort(finishSort, items, 4, window);
		
	}

	return 0;
}