#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: pointer to the grid
 * @height: height of the grid
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int h;

	if (grid == NULL)
		return;

	for (h = 0; h < height; h++)
		free(grid[h]);

	free(grid);
}
