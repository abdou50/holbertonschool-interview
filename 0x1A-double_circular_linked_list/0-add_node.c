#include "list.h"

/**
 * add_node_end - add at the ending
 * @list: the list
 * @str: The string
 *
 * Return:the new node
 */
List *add_node_end(List **list, char *str)
{
	List *new_node, *tmp;

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);
	new_node->str = strdup(str);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*list == NULL)
	{
		*list = new_node;
		new_node->next = new_node;
		new_node->prev = new_node;
		return (new_node);
	}
	tmp = *list;
	while (tmp->next != *list)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = *list;
	(*list)->prev = new_node;
	return (new_node);
}
/**
 * add_node_begin - add at the begining
 * @list: list
 * @str: The string
 *
 * Return: the new node
 */
List *add_node_begin(List **list, char *str)
{
    List *new, *temp;

    new = malloc(sizeof(List));
    if (new == NULL)
        return NULL;

    new->str = str;
    new->next = NULL;
    new->prev = NULL;

    if (*list == NULL)
    {
        *list = new;
    }
    else
    {
        temp = *list;
        new->next = temp;
        temp->prev = new;
        *list = new;
    }
    return (new);
}
