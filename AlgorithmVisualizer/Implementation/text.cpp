#include <iostream> // iostream for error handling.
#include "../Model/text.h" // Header file takes care of loading in all other dependencies for us.

Text::Text(SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message_text, const SDL_Color& color)
{
	_text_texture = loadFont(renderer, font_path, font_size, message_text, color);		// Load font will take everything and handle all steps of the font.
	SDL_QueryTexture(_text_texture, nullptr, nullptr, &_text_rect.w, &_text_rect.h);	// Given that our _text_rect isn't a pointer, we pass these properties in by reference.

}

void Text::display(SDL_Renderer* renderer, int x, int y) const // Every time we separate SDL into Classes, we want to handle the "rendering" as its own method.
{
	_text_rect.x = x;
	_text_rect.y = y;
	SDL_RenderCopy(renderer, _text_texture, nullptr, &_text_rect);
}

SDL_Texture* Text::loadFont(SDL_Renderer* renderer, const std::string& font_path, int font_size, const std::string& message_text, const SDL_Color& color)
{
	TTF_Font* font		= TTF_OpenFont(font_path.c_str(), font_size);				// Open Font
	//if (!font) { std::cerr << "Failed to load font\n"; }
	if (!font) { std::cout << TTF_GetError() << std::endl; }

	auto text_surface	= TTF_RenderText_Solid(font, message_text.c_str(), color);	// Render Message
	if (!text_surface) { std::cerr << "Failed to render text into a surface.\n"; }
					    
	auto text_texture	 = SDL_CreateTextureFromSurface(renderer, text_surface);		// Embed message into a texture
	if (!text_texture) { std::cerr << "Failed to embed message into a texture.\n"; }

	SDL_FreeSurface(text_surface);	// Free up the surface, otherwise you'll create a memory leak.
	TTF_CloseFont(font);			// Same thing here.

	return text_texture;
}
