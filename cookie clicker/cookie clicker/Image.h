#pragma once
#include<SDL.h>
class Image
{
	SDL_Surface* PNGcookie{};
	bool loadMedia(const char* path);
	bool success;
public:
	Image(const char* path) {
		success = loadMedia(path);
	}
	~Image();
	bool wasSuccessfull() { return success; }
	SDL_Surface* getResource() { return PNGcookie; }
};

