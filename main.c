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
	int z[8][8];
	char *line, *token;
	ssize_t n;
	size_t size = 0;
	FILE *fp;
	int i = 0, j = 0;

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
	while ((n = getline(&line, &size, fp)) > 0)
	{
		j = 0;
		token = strtok(line, " ");
		while (token)
		{
			z[i][j++] = atoi(token);
			token = strtok(NULL, " ");
		}
		i++;
	}
	if (init_instance(&instance) != 0)
	{
		fclose(fp);
		free(line);
		exit(EXIT_FAILURE);	
	}
	while (1)
	{
		SDL_SetRenderDrawColor(instance.renderer, 0, 0, 0, 0);
		SDL_RenderClear(instance.renderer);
		if (poll_event() == 1)
			break;
		draw_terrain(&instance, z);
		SDL_RenderPresent(instance.renderer);
	}
	SDL_DestroyRenderer(instance.renderer);
	SDL_DestroyWindow(instance.window);
	SDL_Quit();
	free(line);
	fclose(fp);
	return (0);
}
