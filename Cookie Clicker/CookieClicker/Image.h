#pragma once

#include <SDL.h>

class Image
{
	SDL_Surface* PNGcookie{};
	SDL_Texture* cookieTexture = nullptr;

	bool success = false;
public:
	Image(const char* path, SDL_Renderer* renderer);
	~Image();
	bool wasSuccessfull() { return success; }
	SDL_Surface* getSurface() { return PNGcookie; }
	SDL_Texture* getTexture() { return cookieTexture; }
};