#include <stdlib.h>

/**
 * free_grid - free a 2d array
 *
 * @grid: pointer to grid
 * @height: height of grid
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}

	free(grid);
}
