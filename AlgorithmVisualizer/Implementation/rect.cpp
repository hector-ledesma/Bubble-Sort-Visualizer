#include "../Model/rect.h"

// Assigning all these properties on Construction means they're protected forever.
Rect::Rect(int w, int h, int x, int y, int r, int g, int b, int a) :
	_w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{
}

Rect::~Rect()
{
}

void Rect::draw(SDL_Renderer* renderer) const
{
	// First thing, create an actual SDL_Rect
	SDL_Rect rect = { _x, _y, _w, _h };

	// Always assign a color.
	SDL_SetRenderDrawColor(renderer, _r, _g, _b, _a);
	// Fill up the rect after assigning it
	SDL_RenderFillRect(renderer, &rect);
}

void Rect::pollEvents(SDL_Event& event)
{
}