#include "Image.h"
#include <SDL.h>
#include <cstdio>

bool Image::loadMedia(const char* path)
{
	//Loading success flag
	bool success = true;

	//Load splash image
	PNGcookie = SDL_LoadBMP(path);
	if (!PNGcookie)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "img/PNGcookie.bmp", SDL_GetError());
		success = false;
	}

	return success;
}

Image::~Image() {
	SDL_FreeSurface(PNGcookie);
	PNGcookie = nullptr;
}