#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root:  pointer to the root
 *
 * Return: 1 or 0 
 */

int heap_extract(heap_t **root)
{
	int value = 0, check = 1;
	size_t height = 0, level = 0;
	heap_t *left = NULL, *right = NULL, *last = NULL;

	if (root == NULL || *root == NULL)
		return (0);
	value = (*root)->n;
	left = (*root)->left;
	right = (*root)->right;
	height = binary_tree_height(*root);
	for (level = 0; level <= height; level++)
		getting(*root, level, &last);
	freez(root, &left, &right, &last);
	while (last && check)
		swapping(root, last, &check);
	return (value);
}
/**
 * binary_tree_height - function
 * @root: pointer to the root
 *
 * Return: returns the height of the overall tree
 */

size_t binary_tree_height(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + binary_tree_height(root->left));
}

/**
 * getting - finds first location that does not have a right child

 * @root: pointer to the root 
 * @level: the level
 * @last: last node
 * Return: 1 or 0
 */

void getting(heap_t *root, size_t level, heap_t **last)
{
	if (root == NULL)
		return;
	if (level == 0)
		(*last) = root;
	getting(root->left, level - 1, last);
	getting(root->right, level - 1, last);
}

/**
 * freez - extracts and frees the root node, then
 * @root: double pointer to root node to extract
 * @left: double pointer to root node's left child or NULL
 * @right: double pointer to root node's right child or NULL
 * @last: double pointer to last node from level order traversal
 */

void freez(heap_t **root, heap_t **left,
		heap_t **right, heap_t **last)
{
	if (*last == *root)
	{
		free(*root);
		*root = NULL;
		*last = NULL;
		return;
	}
	if ((*last)->parent->left == (*last))
		(*last)->parent->left = NULL;
	else if ((*last)->parent->right == (*last))
		(*last)->parent->right = NULL;
	(*last)->parent = NULL;
	free(*root);
	*root = *last;

	if ((*left) != (*last))
	{
		(*last)->left = (*left);
		if (*left)
			(*left)->parent = (*last);
	}
	if ((*right) != (*last))
	{
		(*last)->right = (*right);
		if (*right)
			(*right)->parent = (*last);
	}
}

/**
 * swapping - swaps nodes
 * @root:  pointer to root
 * @current: pointer to current node
 * @done: int to tell if it's done
 */

void swapping(heap_t **root, heap_t *current, int *done)
{
	heap_t *max = NULL, *left = current->left, *right = current->right;

	max = current;
	if (left && left->n > max->n)
		max = left;
	if (right && right->n > max->n)
		max = right;
	if (current == max)
	{
		*done = 0;
		return;
	}
	max->parent = current->parent;
	if (current->parent == NULL)
		*root = max;
	else if (current->parent->left == current)
		current->parent->left = max;
	else if (current->parent->right == current)
		current->parent->right = max;
	current->left = max->left;
	if (max->left)
		max->left->parent = current;
	current->right = max->right;
	if (max->right)
		max->right->parent = current;
	if (max == left)
	{
		max->right = right;
		if (right)
			right->parent = max;
		max->left = current;
	}
	else if (max == right)
	{
		max->left = left;
		if (left)
			left->parent = max;
		max->right = current;
	}
	current->parent = max;
}
