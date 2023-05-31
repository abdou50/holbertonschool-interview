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
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
 * siftDown - function
 *
 * @array: the array
 * @start: the value to start with
 * @end: the end
 * @size: the size
 */
void siftDown(int *array, int start, int end, size_t size)
{
	int root = start;

	while (2 * root + 1 <= end)
	{
		int child = 2 * root + 1;
		int swapIndex = root;

		if (array[swapIndex] < array[child])
			swapIndex = child;

		if (child + 1 <= end && array[swapIndex] < array[child + 1])
			swapIndex = child + 1;

		if (swapIndex == root)
			break;
        else
        {
		swap(&array[root], &array[swapIndex]);
		print_array(array, size);
		root = swapIndex;
        }
	}
}
/**
 * heap_sort - function
 * @array: the array
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		siftDown(array, i, size - 1, size);

	for (i = size - 1; i >= 0; i--)

	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		siftDown(array, 0, i - 1, size);
	}
}
