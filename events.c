#include "terrain.h"
/**
 * poll_events - handles the use event
 * @grid: the grid instance
 *
 * Return: (Success) if events goes well
 * ------- (Fail) if something goes wrong
 */
int poll_event(SDL_Grid *grid)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (1);
			case SDL_KEYDOWN:
				key = event.key;
			if (key.keysym.sym == SDLK_ESCAPE)
				return (1);
			if (key.keysym.sym == SDLK_LEFT)
				grid->angle += 1;
			if (key.keysym.sym == SDLK_RIGHT)
				grid->angle -= 1;
			break;
		}
	}
	return (0);
}
