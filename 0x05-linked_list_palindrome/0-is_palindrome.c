#include "lists.h"
/**
 * is_palindrome - checks if singly linked list is a palindrome
 * @head: pointer to head of list
 * Return: 0 or 1
 */
int is_palindrome(listint_t **head){

	int size ,i, *arr, *arrrev ,k;

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
		size++;
        (*head) = (*head)->next;
	}
    for (i = 0; i < size; i++)
    {
        printf("%d /", arr[i]);
    }
    printf("\n");

    for (i = size-1; i>=0; i--){
       arrrev[size-1-i] = arr[i];
    }
    for (i = 0; i < size; i++)
    {
        printf("%d /", arrrev[i]);
    }
    printf("\n");
    for (i = 0; i<size; i++)
    {
        if(arr[i] != arrrev[i])
            k = 1;
        else 
            k = 2;
    }
    if (k == 1)
        return 0;
    return 1;
}