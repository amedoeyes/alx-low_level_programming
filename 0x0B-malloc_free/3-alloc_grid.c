#include <stdlib.h>

/**
 * alloc_grid - creates a 2d array of integers
 *
 * @width: width of grid
 * @height: height of grid
 *
 * Return: pointer to grid
 */

int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j, k;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);

	if (grid == NULL)
		return (NULL);

	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(sizeof(int) * width);

		if (grid[i] == NULL)
		{
			for (k = 0; k < i; k++)
			{
				free(grid[k]);
			}

			free(grid);
			return (NULL);
		}

		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}

	return (grid);
}
