#include "Font.h"

#include <iostream>

Font::Font(const char* path, const int textSize)
{
	//Load font with SDL_TTF
	font = TTF_OpenFont(path, 24);
	if (!font)
	{
		printf("Failed to load font lazy.ttf! TTF Error: %s\n", TTF_GetError());
		return;
	}

	success = true;
}

Font::~Font()
{
	TTF_CloseFont(font);
	font = nullptr;
}