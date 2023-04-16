#include "Window.h"
#include <cstdio>
#include <SDL.h>

Window::Window(int width, int height) : success{}
{

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return;
	}
	
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			return;
		}
		
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			success = true;
		
}

Window::~Window() {
	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = nullptr;

	//Quit SDL subsystems
	SDL_Quit();
}

void Window::render(Image& image) {
	SDL_Rect rect{ 50, 50, 5 ,5 };

	//Apply the image
	SDL_BlitSurface(image.getResource(), nullptr, gScreenSurface, &rect);

	//Update the surface
	SDL_UpdateWindowSurface(gWindow);
}