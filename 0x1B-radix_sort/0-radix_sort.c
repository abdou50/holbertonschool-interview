#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * MAX - Get the maximum element from the array
 * @array: The input array
 * @size: The size of the array
 *
 * Return: The maximum element in the array
 */
int MAX(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counts - Perform counting sort based on a significant digit
 * @array: The input array
 * @size: The size of the array
 * @exp: The significant digit to consider
 */
void counts(int *array, int size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	int i;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sort an array
 * @array: The array
 * @size: The size
 */
void radix_sort(int *array, size_t size)
{
	int max;
	int exp;
	size_t i;

	if (!array || size < 2)
		return;

	max = MAX(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counts(array, size, exp);

		for (i = 0; i < size; i++)
			if (i == size - 1)
			{
				printf("%d", array[i]);
			}
			else
			{
				printf("%d, ", array[i]);
			}
		printf("\n");
	}
}
