#pragma once
/*
	With SDL, we can usue the SDL TTF library extension in order to handle rendering text (using fonts) onto the screen.
	TTF_OpenFont requires:
		1.: Open Font						->	The font path, and the font size in order to open the font.
		2.: Render Message					->	The opened font , the 'text' and the color for RenderText_Solid.
		3.: Embed message into a texture	->	The renderer and the created surface ^ for CreateTextureFromSurface.

	SDL_QueryTexture seems to be the way to modify a texture after it's been loaded in. It requires the texture after it's been fully loaded, format and access (null)
	width, and the height. And when the width and height are passed in by reference, altering them elseqhere will alter the texture!! So we must create
	this relationship as soon as the font has been loaded into a texture.

	Render Copy is how you plaster a "portion" of a texture onto the renderer's context. I assume this would be useful
	for sprites. For now, we'll be using the entire texture. It asks for the renderer, the texture, sourceRect (portion that will be taken), and 
	destinationRect (from this rect is where we'll get the dimensions that the texture will be scaled to).
*/

#include <string>
#include <SDL.h>
#include <SDL_ttf.h>

class Text {
public:
	Text(SDL_Renderer* renderer, const std::string &font_path, int font_size, std::string &message_text, const SDL_Color &color);
	~Text();

	void display(SDL_Renderer* renderer, int x, int y) const;

	SDL_Texture* loadFont(SDL_Renderer* renderer, const std::string& font_path, int font_size, std::string& message_text, const SDL_Color& color);

private:
	SDL_Texture* _text_texture = nullptr;
	mutable SDL_Rect _text_rect;  // By simply declaring the object this way, the Rect gets initialized with default values. Mutable so our functions may mess with it.
};