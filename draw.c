#include "terrain.h"

#define WX(x, y) (0.7 * x - 0.7 * y)
#define WY(x, y, z) (0.3 * x + 0.3 * y - z)
/**
 * points_row - draw the transversal points
 * @x: initial abscissa
 * @y: initial order
 * @z: initial attitude
 *
 * Return: a pointer to the collection of oints
 */
SDL_Point *points_row(int x, int y, int z)
{
	SDL_Point *points;
	int i, cell_width = 100;
	int x_offset = (int) (WINDOW_WIDTH / 2);
	int y_offset = PADDING_TOP;

	points = malloc(8 * sizeof(SDL_Point));
	for (i = 0; i < 8; i++)
	{
		points[i].x = WX(x, y) + x_offset;
		points[i].y = WY(x, y, z) + y_offset;
		x += cell_width;
	}
	return (points);
}
/**
 * points_cln - draw the transversal points
 * @x: initial abscissa
 * @y: initial order
 * @z: initial attitude
 *
 * Return: a pointer to the collection of oints
 */
SDL_Point *points_cln(int x, int y, int z)
{
	SDL_Point *points;
	int i, cell_width = 100;
	int x_offset = (int) (WINDOW_WIDTH / 2);
	int y_offset = PADDING_TOP;

	points = malloc(8 * sizeof(SDL_Point));
	for (i = 0; i < 8; i++)
	{
		points[i].x = WX(x, y) + x_offset;
		points[i].y = WY(x, y, z) + y_offset;
		y += cell_width;
	}
	return (points);
}

SDL_Point point(int x, int y, int z)
{
	SDL_Point point;
	int i, cell_width = 100;
	int x_offset = (int) (WINDOW_WIDTH / 2);
	int y_offset = PADDING_TOP;

	point.x = WX(x, y) + x_offset;
	point.y = WY(x, y, z) + y_offset;
	return (point);
}

/**
 * draw_stuff - draws stuff in the renderer
 * @instance: terrain instance
 *
 * Return: (Success) if succeed
 * ------- (Fail) in fail
 */
int draw_stuff(SDL_Instance *instance, FILE *fp)
{
	int i = 0;
	char *line, *token;
	size_t size;
	ssize_t n_read;

	SDL_SetRenderDrawColor(instance->renderer, 255, 165, 0, SDL_ALPHA_OPAQUE);
	while ((n_read = getline(&line, &size, fp)) < 0)
	{
		token = strtok(line, " ");
		while (token)
		{
			SDL_RenderDrawLines(instance->renderer, points_row(0, i, 0), 8);
			SDL_RenderDrawLines(instance->renderer, points_cln(i, 0, 0), 8);
			token = strtok(NULL, " ");
		}
	}
	return (EXIT_SUCCESS);
}
