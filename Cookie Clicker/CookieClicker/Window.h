#pragma once

#include "Font.h"
#include "Image.h"

class Window
{
	//The window we'll be rendering to
	SDL_Window* gWindow = nullptr;
	SDL_Renderer* gRenderer = nullptr;

	bool success = false;

public:
	Window(int width, int height);
	~Window();
	bool wasSuccessfull() { return success; }
	void beginRender();
	void endRender();
	void renderTexture(Image& image, int x, int y);
	void renderText(Font& font, const char* text, int x, int y, SDL_Color& color);
	SDL_Renderer* getRenderer() {return gRenderer;}
};