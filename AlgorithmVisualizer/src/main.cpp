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
			if (arr[held]->h < arr[i]->h) {
				std::cout << "Held (" << held << ").h is NOT larger than index(" << i << ").h" << std::endl;
				held = i;

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
				
				std::cout << "made a switch" << std::endl;
			}
			std::cout << "New order: " << std::endl;
			for (int j = 0; j < size; j++) {
				std::cout << "\t" << j+1 << " -- x : " << arr[j]->x << " -- h :" << arr[j]->h << std::endl;
			}

			SDL_SetRenderDrawColor(Window::renderer, 255, 255, 255, 255);
			for (int o = 0; o < size; o++) {
				
				arr[o]->x = 20 + ( 40 * o);
				SDL_RenderFillRect(Window::renderer, arr[o]);
			}
			std::cout << "update order : " << std::endl;
			window.clear();
			SDL_Delay(20);
		}

		if (count == 0) {
			finished = true;
		}
		else {
			held = 0;
			count = 0;
		}
		

	}
	
}

void dynamic_array(SDL_Rect arr[20]) {
	
	for (int i = 0; i < 20; i++) {
		SDL_Rect newRect;
		newRect.w = 20;
		newRect.h = rand() % 300 + 100;

		newRect.x = 20 + (40 * i);
		newRect.y = 600 - newRect.h;
		arr[i] = newRect;
	}

}

void render_rects(SDL_Rect* arr[20]) {
	SDL_SetRenderDrawColor(Window::renderer, 255, 255, 255, 255);
	for (int i = 0; i < 20; i++) {
		SDL_RenderFillRect(Window::renderer, arr[i]);
	}
}



int main(int argc, char *argv) {
	// ------------------------------------------------------------------------------
	SDL_Rect hit1;	hit1.w = 20;	hit1.h = 100;	hit1.x = 20;	hit1.y = 600 - hit1.h; 
	SDL_Rect hit2;	hit2.w = 20;	hit2.h = 120;	hit2.x = 60;	hit2.y = 600 - hit2.h;
	SDL_Rect hit3;	hit3.w = 20;	hit3.h = 140;	hit3.x = 100;	hit3.y = 600 - hit3.h;
	SDL_Rect hit4;	hit4.w = 20;	hit4.h = 160;	hit4.x = 140;	hit4.y = 600 - hit4.h;
	SDL_Rect hit5;	hit5.w = 20;	hit5.h = 180;	hit5.x = 180;	hit5.y = 600 - hit5.h;
	SDL_Rect hit6;	hit6.w = 20;	hit6.h = 200;	hit6.x = 220;	hit6.y = 600 - hit6.h;
	SDL_Rect hit7;	hit7.w = 20;	hit7.h = 220;	hit7.x = 260;	hit7.y = 600 - hit7.h;
	SDL_Rect hit8;	hit8.w = 20;	hit8.h = 240;	hit8.x = 300;	hit8.y = 600 - hit8.h;
	SDL_Rect hit9;	hit9.w = 20;	hit9.h = 260;	hit9.x = 340;	hit9.y = 600 - hit9.h;
	SDL_Rect hit10;	hit10.w = 20;	hit10.h = 280;	hit10.x = 380;	hit10.y = 600 - hit10.h;
	SDL_Rect hit11;	hit11.w = 20;	hit11.h = 300;	hit11.x = 420;	hit11.y = 600 - hit11.h;
	SDL_Rect hit12;	hit12.w = 20;	hit12.h = 320;	hit12.x = 460;	hit12.y = 600 - hit12.h;
	SDL_Rect hit13;	hit13.w = 20;	hit13.h = 340;	hit13.x = 500;	hit13.y = 600 - hit13.h;
	SDL_Rect hit14;	hit14.w = 20;	hit14.h = 360;	hit14.x = 540;	hit14.y = 600 - hit14.h;
	SDL_Rect hit15;	hit15.w = 20;	hit15.h = 380;	hit15.x = 580;	hit15.y = 600 - hit15.h;
	SDL_Rect hit16;	hit16.w = 20;	hit16.h = 400;	hit16.x = 620;	hit16.y = 600 - hit16.h;
	SDL_Rect hit17;	hit17.w = 20;	hit17.h = 420;	hit17.x = 660;	hit17.y = 600 - hit17.h;
	SDL_Rect hit18;	hit18.w = 20;	hit18.h = 440;	hit18.x = 700;	hit18.y = 600 - hit18.h;
	SDL_Rect hit19;	hit19.w = 20;	hit19.h = 460;	hit19.x = 740;	hit19.y = 600 - hit19.h;
	SDL_Rect hit20;	hit20.w = 20;	hit20.h = 480;	hit20.x = 780;	hit20.y = 600 - hit20.h;

	int positions[] = {20, 60, 100, 140};

	SDL_Rect* items[20] = { &hit7, &hit17, &hit16, &hit2, &hit15, &hit4, &hit19, &hit8, &hit9, &hit3, &hit1, &hit5, &hit20, &hit14, &hit13, &hit11, &hit12, &hit6, &hit10, &hit18 };
	for (int i = 0; i < 20; i++) {
		items[i]->x = 20 + (40 * i);
	}
	
	// ------------------------------------------------------------------------------

	SDL_Event event;

	Window window("Algorithm Visualizer - Hector Ledesma", 820, 600); // Creating the window will initialize everything.
	Text title(Window::renderer, "res/msyh_console.ttf", 24, "Bubble Sort.", {255, 255, 255, 255});

	bool finishSort = false;
	
	while (!window.isClosed()) {

		if (SDL_PollEvent(&event)) {
			window.pollEvents(event);
		}
		title.display(Window::renderer, 20, 20);

		// ------------------------------------------------------------------------------
		
		
		render_rects(items);
		// ------------------------------------------------------------------------------
		window.clear(); // Always leave this at the bottom, as THIS is what updates the screen.
		bubbleSort(finishSort, items, 20, window);
		
	}

	return 0;
}