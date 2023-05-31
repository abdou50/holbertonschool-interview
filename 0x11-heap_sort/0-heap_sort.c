#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap - swaps two values
 *
 * @a: value 1
 * @b: value 2
 */
void swap(int *a, int *b)
{
	int a1 = *a;
	int b1 = *b;

	*a = b1;
	*b = a1;
}
/**
 * siftDown - function
 *
 * @array: the array
 * @i: the value to start with
 * @end: the end
 * @size: the size
 */

void siftDown(int *array, size_t size, size_t i, size_t end)
{
	size_t max = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < size && array[left] > array[max])
		max = left;

	if (right < size && array[right] > array[max])
		max = right;

	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, end);
		siftDown(array, size, max, end);
	}
}

/**
 * heap_sort - this function implements a heap sort algorithm
 * @array: The array to sort
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t i;
	size_t end = size;

	if (array != NULL)
	{
		for (i = size / 2 - 1; (int)i >= 0; i--)
			siftDown(array, size, i, end);
		for (i = size - 1; i > 0; i--)
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
			siftDown(array, i, 0, end);
		}
	}
}
