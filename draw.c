#include "terrain.h"

/**
 * draw_terrain - draws stuff in the instance renderer
 * @instance: the game instance draw
 * @z: the attitude matrix
 * Return: void
 */
int draw_terrain(SDL_Instance *instance, int z[8][8])
{
	SDL_Point points[8][8];
	SDL_Point tr_points[8][8];
	int i, j;

	for (i = 0; i < 8; i++)
	{	
		for (j = 0; j < 8; j++)
		{
			points[i][j].x = WX(j * CELL, i * CELL)
			+ X_OFFSET;
			points[i][j].y = WY(j * CELL, i * CELL, z[i][j])
			+ Y_OFFSET;
		}
	}
	transpose(points, tr_points);
	for (i = 0; i < 8; i++)
	{
		SDL_RenderDrawLines(instance->renderer, points[i], 8);
		SDL_RenderDrawLines(instance->renderer, tr_points[i], 8);
	}
	return (0);
}
