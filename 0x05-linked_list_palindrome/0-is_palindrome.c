#include "lists.h"
/**
 * is_palindrome - checks if list is a palindrome
 * @head: pointer of list
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head)
{

	int size, size2, i, *arr, *arrrev, k;

	if (head == NULL)
	{
		return (1);
	}
	size = 0;
	arr = malloc(sizeof(listint_t));
	arrrev = malloc(sizeof(listint_t));
	while (*head)
	{
		arr[size] = (*head)->n;
		(*head) = (*head)->next;
		size++;
	}
	for (i = size; i > 0; i--)
	{
		arrrev[size2] = arr[i];
		size2++;
	}
	for (i = 0; i < size; i++)
	{
		if (arr[i] != arrrev[size - i])
			k = 1;
		else
			k = 2;
	}
	if (k == 1)
		return (0);
	return (1);
}
