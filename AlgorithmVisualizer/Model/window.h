#pragma once
/*
When using SDL we will always need to initialize a window. 
SDL_CreateWindow requires:
	title, position (x,y), size (w,h) and flags.
 We want the window to have the ability to listen for events.
 We need the window to be able to paint any extra elements into the screen.
*/

#include <string>
#include <SDL.h>

class Window {
public:
    // Constructor and Destructor
    Window(const std::string& title, int width, int height);
    ~Window();

    // Public methods.
    void pollEvents(SDL_Event& event); // Receive the event directly by reference, so can directly test it.
    void clear() const;
    inline bool isClosed() const { return _closed; } // Return private property so that only class methods may modify it.

private:
    // Properties for initializing SDL_Window
    std::string _title;
    int _width = 800;
    int _height = 600;

    // Bool that will determine the status of our loop.
    bool init();
    bool _closed = false;

    // Property that will hold the initialized SDL_Window
    SDL_Window* _window = nullptr;

public:
    static SDL_Renderer* renderer;
    /*
        SDL uses renderers in order to paint each created objects onto the screen it seems, so we'll use a global
        variable in order to pass it to all other separately managed items.
    */
};