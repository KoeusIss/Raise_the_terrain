#include "terrain.h"

int get_attitudes(char *filename, SDL_Grid *grid)
{
	FILE *fp;
	ssize_t n;
	size_t size = 0;
	char *line, *token;
	int i = 0, j = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open the file %s\n", filename);
		return (EXIT_FAILURE);
	}
	while ((n = getline(&line, &size, fp)) > 0)
	{
		j = 0;
		token = strtok(line, " ");
		while (token)
		{
			grid->z[i][j++] = atoi(token);
			token = strtok(NULL, " ");
		}
		i++;
	}
	free(line);
	return (EXIT_SUCCESS);
}