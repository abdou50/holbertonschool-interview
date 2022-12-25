#include "binary_trees.h"
/**
 * binary_tree_size - count the size of the binary tree
 * @tree: the tree to count in
 * Return: the size
 **/
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t bt_size = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		bt_size = bt_size + binary_tree_size(tree->left);
	if (tree->right != NULL)
		bt_size = bt_size + binary_tree_size(tree->right);
	bt_size = bt_size + 1;
	return (bt_size);
}
/**
 * binary_tree_is_perfect - checks if the binary tree is perfect
 * @tree: the tree to check in
 * Return: 1 if ture 0 if fasle
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int left_size, right_size;

	if (tree == NULL)
		return (0);
	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);
	if (left_size == right_size)
		return (1);
	return (0);
}
/**
 * heap_check_father- check the root
 * @father: pointes to the father
 * @son:pointes to  the son
 */
void heap_check_father(heap_t **son, heap_t **father)
{
	heap_t *c_left, *c_right, *child = *son, *parent = *father;

	c_right = (*son)->right, c_left = (*son)->left;
	if (child->n > parent->n)
	{
		if (child->left)
			child->left->parent = parent;
		if (child->right)
			child->right->parent = parent;
		if (parent->left == child)
		{
			if (parent->right)
				parent->right->parent = child;
			child->right = parent->right;
			child->left = parent;
		}
		else
		{
			parent->left->parent = child;
			child->left = parent->left;
			child->right = parent;
		}
		if (parent->parent)
		{
			if (parent->parent->left == parent)
				parent->parent->left = child;
			else
				parent->parent->right = child;
		}
		else
		{
			*father = child;
		}
		child->parent = parent->parent;
		parent->parent = child;
		parent->left = c_left;
		parent->right = c_right;
	}
}
/**
 * heap_insert- insert in the heap
 * @root: pointer the root
 * @value: the value to insert*
 * Return: 1 on succes 0 if nothing done
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *newNode;

	if ((*root) == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	if (binary_tree_is_perfect(*root) || (!binary_tree_is_perfect((*root)->left)))
	{
		if ((*root)->left != NULL)
		{
			newNode = heap_insert(&((*root))->left, value);
			heap_check_father(&((*root)->left), root);
			return (newNode);
		}
		else
		{
			newNode = binary_tree_node(*root, value);
			(*root)->left = newNode;
			heap_check_father(&((*root)->left), root);
			return (newNode);
		}
	}
	else
	{
		if ((*root)->right != NULL)
		{
			newNode = heap_insert(&((*root)->right), value);
			heap_check_father(&((*root)->right), root);
			return (newNode);
		}
		else
		{
			newNode = binary_tree_node(*root, value);
			(*root)->right = newNode;
			heap_check_father(&((*root)->right), root);
			return (newNode);
		}
	}
	return (NULL);
}
