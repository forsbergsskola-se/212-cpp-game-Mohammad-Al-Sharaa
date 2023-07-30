#pragma once

#include <SDL_ttf.h>

class Font
{
	TTF_Font* font = nullptr;

	bool success = false;
public:
	Font(const char* path, const int textSize);
	~Font();
	bool wasSuccessfull() { return success; }
	TTF_Font* getFont() { return font; }
};