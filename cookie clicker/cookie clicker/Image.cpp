#include "Image.h"
#include <SDL.h>
#include <cstdio>

Image::Image(const char* path) : success{}
{
	

	//Load splash image
	PNGcookie = SDL_LoadBMP(path);
	if (!PNGcookie)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}

	success = true;
}

Image::~Image() {
	SDL_FreeSurface(PNGcookie);
	PNGcookie = nullptr;
}