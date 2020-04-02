#pragma once

/*
	Based on what little I've seen, right about every single thing that is rendered into the screen using SDL, is done so with the power of rectangles.
	SDL_Rects only ask for:
		1.: Dimensions	->	w, h.
		2.: Position	->	x, y.
		3.:	Color		->	r, g, b, alpha.

	Using a user-define type allows us to set all these properties to private once defined, as well as keep any functions contained to each individual object.

	It would also let us create texture in a much more organized manner.
*/

#include "window.h" // We handle importing window.h here so we don't have to in rect.cpp

class Rect {
public:
	Rect(int w, int h, int x, int y, int r, int g, int b, int a);
	~Rect();

	// Must always have our function to render into the screen.
	void draw(SDL_Renderer* renderer) const; // If a function will not alter any of the object's properties (or at least shouldn't) make sure to mark it as const.

	// Function to listen for input.
	void pollEvents(SDL_Event& event);

private:
	int _w, _h;
	int _x, _y;
	int _r, _g, _b, _a;
};