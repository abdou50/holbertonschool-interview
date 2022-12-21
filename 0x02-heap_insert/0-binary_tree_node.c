#include "binary_trees.h"
/**
 * binary_tree_node - create a new node
 *
 * @parent: Pointer to the node to print
 * @value: value of the node
 *
 * Return: length of printed tree after process
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (!node)
		return (NULL);
	node->n = value;
	node->parent = parent;
	node->right = NULL;
	node->left = NULL;
	return (node);

}
