#include "search.h"
/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 *
 * @list: Pointer to the head of the skip list to search in
 * @value: Value to search for
 *
 * Return: Pointer on the first node or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i;
	skiplist_t *first, *temp;

	if (!list)
		return (NULL);

	first = list,
    temp = list;

	while (first && first->next && (first->n) < value)
	{
		temp = first;

		if (first->express)
		{
			first = first->express;

			printf("Value checked at index [%lu] = [%d]\n",
					first->index, first->n);
		}
		else
			while (first->next)
				first = first->next;
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
			temp->index, first->index);

	for (i = temp->index;
			i <= (first->index) && (temp->n <= value);
			i++, temp = temp->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", i, temp->n);
		if (temp && (temp->n) == value)
			return (temp);
	}

	if (temp)
		printf("Value checked at index [%lu] = [%d]\n", i, temp->n);

	return (NULL);
}
