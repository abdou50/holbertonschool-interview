#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"
avl_t *createavlnode(int n, avl_t *parent)
{
  avl_t *node = malloc(sizeof(*node));
  node->n = n;
  node->left = NULL;
  node->right = NULL;
  node->parent = parent;
  return (node);
}

/**
 * print_t - Stores recursively each level in an array of strings
 *
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of printed tree after process
 */

avl_t *recursively(int *array, int begin, int sizearray, avl_t *parent)
{
    avl_t *node;
    int i;

    i = (begin + sizearray) / 2;
    node = createavlnode(array[i], parent);
    if (!node)
        return (NULL);
    node->right = recursively(array, i + 1 , sizearray - 1, node);
    node->left = recursively(array, begin, i - 1 ,node);
    return(node);
}
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    return(recursively(array, 0, size, NULL));
}
