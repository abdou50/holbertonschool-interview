#include "sort.h"

/**
 * merge_sort - Sorts an array
 * @array: The array
 * @size: size
 */
void merge_sort(int *array, size_t size)
{
	int *tmp = malloc(size * sizeof(int));

	if (tmp == NULL)
		return;

	merging(array, size, tmp);
	free(tmp);
}

/**
 * merging - Merges two sorted arrays into one sorted array
 *
 * @array: array
 * @size: size
 * @tmp:temp
 */
void merging(int *array, size_t size, int *tmp)
{
	size_t left = size / 2, right = size - left;
	size_t i = 0, j = 0, f = 0;
	int *right_array = array + left;

	if (size <= 1)
		return;

	merging(array, left, tmp);
	merging(right_array, right, tmp);

	for (i = 0; i < left; i++)
		tmp[i] = array[i];

	printf("Merging...\n[left]: ");
	print_array(array, left);
	printf("[right]: ");
	print_array(right_array, right);

	i = 0;

	while (i < left || j < right)
	{
		while (j < right && (i >= left || right_array[j] < tmp[i]))
			array[f++] = right_array[j++];
		while (i < left && (j >= right || right_array[j] >= tmp[i]))
			array[f++] = tmp[i++];
	}

	printf("[Done]: ");
	print_array(array, size);
}
