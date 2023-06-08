#include <stdio.h>
#include "search_algos.h"


/**
 *print_array -print array of
 *@array: array
 *@start: is the first
 *@end: is the last
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		if (i == end)
		{
			printf("%d", array[i]);
		}
		else
		{
			printf("%d, ", array[i]);
		}
	}
	printf("\n");
}
/**
 * search_into_array - function that print array of
 *@array:  is a pointer to the first element of the array to search in
 *@start: is the first index to print array
 *@end: the end index to print array
 *@value: is the last index to print array
 * Return: index of value
 */
int search_into_array(int *array, size_t start, size_t end, int value)
{
	size_t mid_value;

	if (start <= end)
	{
		print_array(array, start, end);
		mid_value = (start + end) / 2;
		if (array[mid_value] == value && array[mid_value - 1] != value)
		{
			return (mid_value);
		}
		else if (array[mid_value] < value)
		{
			return (search_into_array(array, mid_value + 1, end, value));
		}
		else
		{
			return (search_into_array(array, start, mid_value, value));
		}
	}
	return (-1);
}

/**
 * advanced_binary - function
 * @array: the array
 * @size: the size of the array
 * @value: the value
 * Return: the position or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array)
	{
		return (-1);
	}
	return (search_into_array(array, 0, size - 1, value));
}
