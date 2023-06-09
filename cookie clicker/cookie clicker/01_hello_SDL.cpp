/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include "Window.h"
#include "Image.h"
#include <iostream>

//Starts up SDL and creates window



//Loads individual image


//Current displayed PNG image


//Screen dimension constants

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;



int main(int argc, char* args[])
{
	Window window{ SCREEN_WIDTH, SCREEN_HEIGHT };
	//Start up SDL and create window
	if (!window.wasSuccessfull())
	{
		printf("Failed to initialize!\n");
		return -1;
	}
	
		//Load media
		Image image{"img/PNGcookie.bmp"};
		if (!image.wasSuccessfull())
		{
			printf("Failed to load media!\n");
			return -1;
		}

			//Hack to get window to stay up
			SDL_Event e; bool quit = false;
			while (!quit) {
				while (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) quit = true;

					if (e.type == SDL_MOUSEMOTION) {
						int x, y;
						SDL_GetMouseState(&x, &y);
						std::cout << x << " : " << y << std::endl;
					}

					if (e.type == SDL_MOUSEBUTTONDOWN) {
						int x, y;
						SDL_GetMouseState(&x, &y);
						if (x >= 253 && y >= 205 && x <= 340 && y <= 263) {
							if (e.button.button == SDL_BUTTON_LEFT) {
								std::cout << "Left mouse button is down" << std::endl;
							}
						}
					}
				}
				window.render(image);
			}

	return 0;	
}
