#include "terrain.h"
/*
gcc -Wall -Werror -pedantic -Wextra *.c -o terrain `sdl2-config --cflags` `sdl2-config --libs`
*/

/**
 * main - main function
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: Always 0
 */
int main(void)
{
	SDL_Instance instance;

	if (init_instance(&instance) != 0)
	{
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_event() == FAIL)
			break;
		draw_stuff(&instance);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (SUCCESS);
}