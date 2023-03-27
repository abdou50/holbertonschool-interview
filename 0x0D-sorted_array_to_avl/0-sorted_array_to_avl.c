#include "binary_trees.h"

/**
 * createavlnode - create a node
 * @n: value of node
 * @parent:parent node
 * Return: the node d
 */
avl_t *createavlnode(int n, avl_t *parent)
{
	avl_t *node = malloc(sizeof(*node));

	if (!new)
		return (NULL)node
	node->n = n;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * recursively - search where to add in tree
 * @parent: parent node
 * @array: array of values
 * @begin: begin of the array
 * @sizearray: size of the array
 * Return: null or avl
 */
avl_t *recursively(avl_t *parent, int *array, int begin, int sizearray)
{
	avl_t *new;
	int i;

	if (begin > sizearray)
		return (NULL);
	i = (begin + sizearray) / 2;
	new = createavlnode(array[i], parent);
	if (!new)
		return (NULL);
	new->left = recursively(new, array, begin, i - 1);
	new->right = recursively(new, array, i + 1, sizearray);
	return (new);
}

/**
 * sorted_array_to_avl - build AVL tree from array
 * @array: pointer to first element of array
 * @size: size of array
 *
 * Return:  root or null
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (recursively(NULL, array, 0, size - 1));
}
