#include "../Model/window.h"
#include <iostream>

// Only const properties can be initalized within the class. So we initialize it here to nullptr for best practice.
SDL_Renderer* Window::renderer = nullptr;

Window::Window(const std::string& title, int width, int height) :
	_title(title), _width(width), _height(height) 
{
	/*
		Init will be the function that takes care of initializing an SDL_Window using the passed
		int parameters when initializing this class. It will return a bool that will be assigned
		to our _closed property.
	*/
	_closed = !init();
}

Window::~Window() 
{
	/*
	Every single created object from SDL is done so in the HEAP, therefore they must all 
	be manually deconstructed.
	*/
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(renderer);
}

bool Window::init() {

	// First, attempt to initialize SDL. SDL_Init returns 0 on success.
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initialize SDL.\n";
		return false;
	}

	// Create a window object and assign it to our pointer.
	_window = SDL_CreateWindow(
		_title.c_str(), // Turn our string into a *char.
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		0
		);

	// If this fails, then our _window property will remain a nullptr.
	if (_window == nullptr) {
		std::cerr << "Failed to create window.\n";
		return false;
	}

	// Create the renderer that will be used accross our app.
	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr) {
		std::cerr << "Failed to create renderer.\n";
		return false;
	}

	// If everything goes right, return true.
	return true;
}

void Window::pollEvents(SDL_Event& event) {

}

void Window::clear() const {
	SDL_RenderPresent(renderer); // Passes in our renderer.
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Assigns the color value. My assumption is that this will affect the last object that was brought to life.
	SDL_RenderClear(renderer); // Tells the render to go picasso and paint stuff into the screen.
}