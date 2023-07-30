#include "Image.h"

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Image::Image(const char* path, SDL_Renderer* renderer) : success{}
{
	//Load with SDL_Image
	PNGcookie = IMG_Load(path);
	if (!PNGcookie)
	{
		printf("Unable to load image %s! SDL Error: %s\n", path, IMG_GetError());
		return;
	}

	cookieTexture = SDL_CreateTextureFromSurface(renderer, PNGcookie);

	if (!cookieTexture)
	{
		printf("Unable to create texture for image %s! SDL Error: %s\n", path, SDL_GetError());
		return;
	}

	success = true;
}

Image::~Image() {
	SDL_DestroyTexture(cookieTexture);
	cookieTexture = nullptr;

	SDL_FreeSurface(PNGcookie);
	PNGcookie = nullptr;
}