#ifndef _TERRAIN_H
#define _TERRAIN_H
/* Libraries */
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
/* Macros */
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define GRID_WIDTH 8
#define X_OFFSET (WINDOW_WIDTH / 2)
#define Y_OFFSET -150
#define CELL 120
#define R_OFF_X 380
#define R_OFF_Y 400
#define WX(x, y) (0.5 * x - 0.5 * y)
#define WY(x, y, z) (0.5 * x + 0.5 * y - z)
#define RX(x, y, a) ((x - R_OFF_X) * cos(a) - (y - R_OFF_Y) * sin(a) + R_OFF_X)
#define RY(x, y, a) ((x - R_OFF_X) * sin(a) + (y - R_OFF_Y) * cos(a) + R_OFF_Y)
/**
 * Struct SDL_Instance - data structure for game instance
 * @window: the game window
 * @renderer: the game renderer
 *
 * Description: a data structure for all game instance such as
 * window, rendere, texture, screen ...
 */
typedef struct SDL_Instance
{
	SDL_Window *window;
	SDL_Renderer *renderer;
} SDL_Instance;

/**
 * Struct SDL_Grid - data structure for grid
 * @x: abscissa of the grid points
 * @y: orders of the grid points
 * @z: attitude of the gric points
 * @angle: angle rotation
 *
 * Descrioption: data structure for the grid
 */
typedef struct SDL_Grid
{
	int x[GRID_WIDTH][GRID_WIDTH];
	int y[GRID_WIDTH][GRID_WIDTH];
	int z[GRID_WIDTH][GRID_WIDTH];
	int angle;
} SDL_Grid;

/* Prototypes */
int get_attitudes(char *filename, SDL_Grid *grid);
int init_instance(SDL_Instance *instance);
int poll_event(SDL_Grid *grid);
int draw_terrain(SDL_Instance *instance, SDL_Grid *grid);
void transpose(SDL_Point a[GRID_WIDTH][GRID_WIDTH],
	SDL_Point b[GRID_WIDTH][GRID_WIDTH]);

#endif /* _TERRAIN_H */