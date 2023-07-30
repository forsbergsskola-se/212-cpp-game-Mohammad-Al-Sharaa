#include "Window.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cstdio>

Window::Window(int width, int height) : success{}
{
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return;
	}

	//Initialize SDL_Image
	if(IMG_Init(IMG_INIT_PNG) == 0)
	{
		printf("SDL_Image could not initialize! SDL_Image Error: %s\n", IMG_GetError());
		return;
	}

	//Initialize SDL_TTF
	if(TTF_Init() == -1)
	{
		printf("SDL_TTF could not initialize! SDL_TTF Error: %s\n", TTF_GetError());
		return;
	}
	
	//Create window
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RendererFlags::SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return;
	}

	//Activate blending so that transparency can be used on textures
	SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);

	success = true;
}

Window::~Window() {
	//Destroy window and the renderer
	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	//Quit SDL_TTF
	TTF_Quit();
	//Quit SDL_Image
	IMG_Quit();
	//Quit SDL subsystems
	SDL_Quit();
}

void Window::beginRender()
{
	//Clear the window to white
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderClear(gRenderer);
}

void Window::endRender()
{
	//Update the window
	SDL_RenderPresent(gRenderer);
}

void Window::renderTexture(Image& image, int x, int y) {
	SDL_Texture* texture = image.getTexture();
	int textureWidth = 0;
	int textureHeight = 0;

	//Get the texture size
	SDL_QueryTexture(texture, nullptr, nullptr, &textureWidth, &textureHeight);

	SDL_Rect rect = { x, y, textureWidth, textureHeight };

	//Render the texture
	SDL_RenderCopy(gRenderer, texture, nullptr, &rect);
}

void Window::renderText(Font& font, const char* text, int x, int y, SDL_Color& color)
{
	//Create the text surface
	SDL_Surface* textSurface = TTF_RenderText_Solid(font.getFont(), text, color);

	if(!textSurface)
		return;

	SDL_Texture* textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);

	if(!textTexture)
	{
		//Destroy the surface to avoid memory leak
		SDL_FreeSurface(textSurface);
		textSurface = nullptr;

		return;
	}

	int textureWidth = 0;
	int textureHeight = 0;

	//Get the texture size
	SDL_QueryTexture(textTexture, nullptr, nullptr, &textureWidth, &textureHeight);

	SDL_Rect rect = { x, y, textureWidth, textureHeight };

	//Render the texture
	SDL_RenderCopy(gRenderer, textTexture, nullptr, &rect);

	//Destroy the texture to avoid memory leak
	SDL_DestroyTexture(textTexture);
	textTexture = nullptr;

	//Destroy the surface to avoid memory leak
	SDL_FreeSurface(textSurface);
	textSurface = nullptr;
}