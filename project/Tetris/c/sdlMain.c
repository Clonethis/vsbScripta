// for creating greatcode ?:  https://www.willusher.io/sdl2%20tutorials/2014/06/16/postscript-0-properly-finding-resource-paths


#include<SDL.h>

SDL_Window *win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
if (win == nullptr){
	std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
	SDL_Quit();
	return 1;
}