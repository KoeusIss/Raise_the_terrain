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
#define WINDOW_WIDTH 1260
#define WINDOW_HEIGHT 720
#define PADDING_TOP 170
#define PADDING_LEFT 50
#define WX(x, y) (0.7 * x - 0.7 * y)
#define WY(x, y, z) (0.3 * x + 0.3 * y - z)
#define X_OFFSET (WINDOW_WIDTH / 2)
#define Y_OFFSET 150
#define CELL 120
extern int angle;
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

/* Prototypes */
int init_instance(SDL_Instance *instance);
int draw_terrain(SDL_Instance *instance, int z[8][8]);
int poll_event(void);
void transpose(SDL_Point a[8][8], SDL_Point b[8][8]);

#endif /* _TERRAIN_H */