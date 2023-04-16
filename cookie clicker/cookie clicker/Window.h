#pragma once
#include "Image.h"
class Window
{
	//The window we'll be rendering to
	SDL_Window* gWindow{};

	//The surface contained by the window
	SDL_Surface* gScreenSurface{};

	bool success;

	

public:
	Window(int width, int height);
	~Window();
	bool wasSuccessfull() { return success; }
	void render(Image& image);
};