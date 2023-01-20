#include "lists.h"
/**
 * is_palindrome - checks if singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head)
{

	int n, i, flag = 0;
	int arr[100];

	if (head == NULL)
	{
		return (1);
	}
	n = 0;
	while (*head)
	{
		arr[n] = (*head)->n;
		n++;
		(*head) = (*head)->next;
	}
	for (i = 0; i <= n / 2 && n != 0; i++)
	{
		if (arr[i] != arr[n - i - 1])
		{
			flag = 1;
			break;
		}
	}
	if (flag == 1)
		return (0);
	else
		return (1);
}

