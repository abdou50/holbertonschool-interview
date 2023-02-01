#include "lists.h"
/**
 * check_cycle -  frees a listint_t list
 * @list: pointer to list
 * Return: 1 or 0
 */
int check_cycle(listint_t *list)
{
	listint_t *fast;
	listint_t *slow;

	if (!list || !list->next)
		return (0);
	fast = list->next->next;
	slow = list->next;
	while (slow && fast && fast->next)
	{
		if (fast == slow)
			return (1);
		fast = fast->next->next;
		slow = slow->next;
	}
	return (0);
}
