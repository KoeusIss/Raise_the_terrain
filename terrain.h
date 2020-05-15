#ifndef _TERRAIN_H
#define _TERRAIN_H
/* Libraries */
#include <SDL2/SDL.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
/* Macros */
#define WINDOW_WIDTH 1260
#define WINDOW_HEIGHT 720
#define PADDING_TOP 170
#define PADDING_LEFT 50
#define FAIL 1
#define SUCCESS 0
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
int init_instance(SDL_Instance *);
int draw_stuff(SDL_Instance *instance, FILE *fp);
int poll_event(void);

#endif /* _TERRAIN_H */