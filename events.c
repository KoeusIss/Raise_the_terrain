#include "terrain.h"

/**
 * poll_events - handles the use event
 *
 * Return: (Success) if events goes well
 * ------- (Fail) if something goes wrong
 */
int poll_event(void)
{
	SDL_Event event;
	SDL_KeyboardEvent key;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				return (FAIL);
			case SDL_KEYDOWN:
				key = event.key;
			if (key.keysym.scancode == 0x29)
				return (FAIL);
			break;
		}
	}
	return (SUCCESS);
}
