	#include "terrain.h"
/**
 * draw_terrain - draws stuff in the instance renderer
 * @instance: the game instance draw
 * @grid: the attitude matrix
 * Return: void
 */
int draw_terrain(SDL_Instance *instance, SDL_Grid *grid)
{
	SDL_Point points[GRID_WIDTH][GRID_WIDTH];
	SDL_Point tr_points[GRID_WIDTH][GRID_WIDTH];
	int i, j, x, y;
	float a;

	a = grid->angle * M_PI / 180;
	for (i = 0; i < 8; i++)
	{	
		for (j = 0; j < 8; j++)
		{
			grid->x[i][j] = (i * CELL);
			grid->y[i][j] = (j * CELL);
			x = RX(grid->x[i][j], grid->y[i][j], a);
			y = RY(grid->x[i][j], grid->y[i][j], a);
			x = WX(x, y) + X_OFFSET;
			y = WY(x, y, grid->z[i][j]) + Y_OFFSET;
			points[i][j].x = x;
			points[i][j].y = y;
		}
	}
	transpose(points, tr_points);
	SDL_SetRenderDrawColor(instance->renderer, 40, 255, 150, 0);
	for (i = 0; i < 8; i++)
	{
		SDL_RenderDrawLines(instance->renderer, points[i], 8);
		SDL_RenderDrawLines(instance->renderer, tr_points[i], 8);
	}
	return (0);
}
