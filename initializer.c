#include "terrain.h"
/**
 * init_instance - initializes the terrain instance
 * @instance: terrain instance
 *
 * Descriptioin: Creates the two instance for the terrain
 * Creates a window with WIN_WIDTH and WIN_HEIGHT centered
 * in the user screen view
 *
 * Return: (Success) if windows and renderer successfully created
 * ------- (Fail) in any wrong in creation
 */
int init_instance(SDL_Instance *instance)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		fprintf(stderr, "SDL::Initialize Error: %s\n", SDL_GetError());
		return (FAIL);
	}
	instance->window = SDL_CreateWindow("SDL2 \\o/",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	if (instance->window == NULL)
	{
		fprintf(stderr, "SDL::Createwindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (FAIL);
	}
	instance->renderer = SDL_CreateRenderer(instance->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (instance->renderer == NULL)
	{
		SDL_DestroyWindow(instance->window);
		fprintf(stderr, "SDL::CreateRendrer Error: %s\n", SDL_GetError());
		SDL_Quit();
		return (FAIL);
	}
	return (SUCCESS);
}