#include "menger.h"
/**
* menger - function
* @level: the level
*/
void menger(int level)
{
	int size, i, j;

	if (level < 0)
	{
		return;
	}

	size = pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i % 3 == 1 && j % 3 == 1)
			{
				printf(" ");
			}
			else
			{
				draw(j, i, level);
			}
		}
		printf("\n");
	}
}
/**
* draw - function
* @x: int
* @y: int
* @level: the level
*/
void draw(int x, int y, int level)
{
	int size, cx, cy;

	if (level == 0)
	{
		printf("#");
	}
	else
	{
		size = pow(3, level - 1);
		cx = x / 3;
		cy = y / 3;

		if (cx % 3 == 1 && cy % 3 == 1)
		{
			printf(" ");
		}
		else
		{
			draw(x % size, y % size, level - 1);
		}
	}
}
