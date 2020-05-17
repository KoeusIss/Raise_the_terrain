#include "terrain.h"

/**
 * main - main function
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
	SDL_Instance instance;
	SDL_Grid grid;

	memset((void *) &grid, 0, sizeof(grid));
	if (ac != 2)
	{
		fprintf(stderr, "Usage: terrain file\n");
		exit(EXIT_FAILURE);
	}
	/* Get attitudes from file */
	if (get_attitudes(av[1], &grid) < 0)
		exit(EXIT_FAILURE);
	/* Initialize instances: Window and Renderer */
	if (init_instance(&instance) != 0)
		exit(EXIT_FAILURE);	
	/* Infinite loop for arts */
	while (1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_event(&grid) == 1)
			break;
		draw_terrain(&instance, &grid);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	return (0);
}
