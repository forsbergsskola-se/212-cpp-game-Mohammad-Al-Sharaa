/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO


#include "Font.h"
#include "Image.h"
#include "Window.h"

#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <string>

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 600;

int cookieCounter = 0;

TTF_Font* gFont = nullptr;

//Will be used for checking if the user has clicked inside the cookie texture
SDL_Rect cookieRect = {0, 0, 0, 0};

int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	//Start up SDL and create window
	if (!window.wasSuccessfull())
	{
		printf("Failed to initialize the!\n");
		return -1;
	}
	
	//Load media
	Image image{"assets/textures/Cookie.png", window.getRenderer()};
	if (!image.wasSuccessfull())
	{
		printf("Failed to load image!\n");
		return -1;
	}

	//Load font
	Font font{"assets/fonts/arial.ttf", 24};
	if (!font.wasSuccessfull())
	{
		printf("Failed to load font!\n");
		return -1;
	}

	int cookieWidth = 0;
	int cookieHeight = 0;
	SDL_QueryTexture(image.getTexture(), nullptr, nullptr, &cookieWidth, &cookieHeight);

	cookieRect = {100, 100, cookieWidth, cookieHeight};

	SDL_Event e;
	bool quit = false;

	//Mainloop
	while (!quit) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				quit = true;

			if (e.type == SDL_MOUSEMOTION) {
				int x, y;
				SDL_GetMouseState(&x, &y);
			//	std::cout << x << " : " << y << std::endl;
			}

			if (e.type == SDL_MOUSEBUTTONDOWN) {
				int x, y;
				SDL_GetMouseState(&x, &y);

				SDL_Point mousePointer = {x, y};

				//The user has clicked inside the cookie rect so increase the cookie counter
				if(SDL_PointInRect(&mousePointer, &cookieRect))
					cookieCounter++;
			}
		}

		window.beginRender(); //Clear the window
		{
			//Render all graphics to the window

			window.renderTexture(image, cookieRect.x, cookieRect.y);

			SDL_Color textColor = {0, 0, 0, 255};
			std::string cookieCounterText = "Click counter: " + std::to_string(cookieCounter);
			window.renderText(font, cookieCounterText.c_str(), 400, 200, textColor);
		}
		window.endRender(); //Update the window
	}

	return 0;	
}