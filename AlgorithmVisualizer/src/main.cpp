#include <iostream>
#include <SDL.h>
#undef main

int main(int argc, char *argv) {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cerr << "SDL failed to initialize\n";
	}
	else {
		std::cout << "Success!\n";
	}

	return 0;
}