#pragma once
#include<SDL.h>
class Image
{
	SDL_Surface* PNGcookie{};
	bool success;
public:
	Image(const char* path);
	~Image();
	bool wasSuccessfull() { return success; }
	SDL_Surface* getResource() { return PNGcookie; }
};

