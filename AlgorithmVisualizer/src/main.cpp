#include "../Model/window.h"
#include <iostream>
#include <SDL.h>
#undef main

int main(int argc, char *argv) {

	Window window("Algorithm Visualizer - Hector Ledesma", 800, 600); // Creating the window will initialize everything.

	while (!window.isClosed()) {
		window.clear(); // Always leave this at the bottom, as THIS is what updates the screen.
	}

	return 0;
}