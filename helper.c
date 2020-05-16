#include "terrain.h"

/**
 * transpose - transpose matrix
 * @a: the first matrix
 * @b: the second matrix
 *
 */
void transpose(SDL_Point a[8][8], SDL_Point b[8][8])
{
	int i, j;

	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
			b[i][j] = a[j][i];
}
