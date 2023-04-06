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
	skiplist_t *express = list, *curr = list;

	if (!list)
		return (NULL);

	while (express && express->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				express->index, express->n);
		curr = express;
		express = express->express;
	}

	if (express)
		printf("Value found between indexes [%lu] and [%lu]\n",
				curr->index, express->index);
	else
		printf("Value found between indexes [%lu] and [%lu]\n",
				curr->index, curr->index);

	while (curr && curr->n < value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				curr->index, curr->n);
		curr = curr->next;
	}

	if (curr && curr->n == value)
	{
		printf("Value checked at index [%lu] = [%d]\n",
				curr->index, curr->n);
		return (curr);
	}

	return (NULL);
}
