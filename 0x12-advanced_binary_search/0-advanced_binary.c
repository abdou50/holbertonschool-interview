#include <stdio.h>
#include "search_algos.h"

/**
 * advanced_binary - function
 * @array: the array
 * @size: the size of the array
 * @value: the value
 * Return: the position or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (binary_search(array, 0, size - 1, value));
}
/**
 * binary_search - function
 * @array: the array
 * @start: the start
 * @end: the end
 * @value: the value
 * Return: the position or -1
 */
int binary_search(int *array, int start, int end, int value)
{
	int mid, i;

	if (start > end)
		return (-1);

	mid = start + (end - start) / 2;
	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");

	if (array[mid] == value)
	{
		if (mid == 0 || array[mid - 1] != value)
			return (mid);
		else
			return (binary_search(array, start, mid - 1, value));
	}
	else if (array[mid] < value)
		return (binary_search(array, mid + 1, end, value));
	else
		return (binary_search(array, start, mid - 1, value));
}
