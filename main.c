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
int main(int ac, int **av)
{
	SDL_Instance instance;
	FILE *fp;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: terrain file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(av[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	if (init_instance(&instance) != 0)
	{
		fclose(fp);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_event() == FAIL)
			break;
		draw_stuff(&instance, fp);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (SUCCESS);
}