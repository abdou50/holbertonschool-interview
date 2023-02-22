#include "slide_line.h"

void pushl(int *arr, size_t n)
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
void mergel(int *list, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (list[i] != 0)
			if (list[i] == list[i + 1])
			{
				list[i + 1] *= 2;
				list[i] = 0;
			}
		break;
	}

}
void pushr(int *arr, size_t n)
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
void merger(int *list, size_t size)
{
	size_t i;

	for (i = size; i > 0; i--)
	{
		if (list[i] != 0)
			if (list[i] == list[i - 1])
			{
				list[i - 1] *= 2;
				list[i] = 0;
			}
		break;
	}

}
int slide_line(int *line, size_t size, int direction)
{
	if (line == 0)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		pushr(line, size);
		merger(line, size);
		pushr(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		pushl(line, size);
		mergel(line, size);
		pushl(line, size);
	}
	else
		return (0);
	return (1);
}
