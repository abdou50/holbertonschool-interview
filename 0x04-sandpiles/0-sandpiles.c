#include "sandpiles.h"

/**
 * sandpiles_sum - sandplis theory
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */

void addition(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
}
int is_stable(int grid[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}
void permutation(int grid1[3][3])
{
	int i = 0;
	int j = 0;
    int externe[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}};

    for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] = grid1[i][j] - 4;
				if ((i - 1) >= 0 && (i - 1) < 3)
					externe[i - 1][j] += 1;
				if ((j - 1) >= 0 && (j - 1) < 3)
					externe[i][j - 1] += 1;
				if ((i + 1) >= 0 && (i + 1) < 3)
					externe[i + 1][j] += 1;
				if ((j + 1) >= 0 && (j + 1) < 3)
					externe[i][j + 1] += 1;
			}
		}
	}
    addition(grid1, externe);
}
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	if (is_stable(grid1) == 0 || is_stable(grid2) == 0)
		return;
	addition(grid1, grid2);

	while (is_stable(grid1) != 1)
	{
		printf("=\n");
		print_grid(grid1);
		permutation(grid1);
	}
}
