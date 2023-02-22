#include "slide_line.h"

void pushr(int *arr, size_t n)
{
	size_t i, j;
	int aux;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
			{
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
}

void merger(int *array, size_t size)
{
    size_t i;

	for (i = size - 1; i + 1 > 1; i--)
	{
		if (array[i] == array[i - 1])
		{
			array[i - 1] *= 2;
			array[i] = 0;
			--i;
		}
	}
}
void pushl(int *arr, size_t n)
{
	size_t i, j;
	int aux;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] < arr[j + 1])
			{
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
}
void mergel(int *array, size_t size)
{
    size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (array[i] == array[i + 1])
		{
			array[i + 1] *= 2;
			array[i] = 0;
			++i;
		}
	}
}
int slide_line(int *line, size_t size, int direction)
{
	if (line == 0)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		pushl(line, size);
		mergel(line, size);
		pushl(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		pushr(line, size);
		merger(line, size);
		pushr(line, size);
	}
	else
		return (0);
	return (1);
}
