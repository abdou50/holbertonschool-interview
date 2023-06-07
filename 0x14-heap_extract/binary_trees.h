#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;
typedef binary_tree_t heap_t;

void binary_tree_print(const heap_t *);
int heap_extract(heap_t **root);
void swapping(heap_t **root, heap_t *current, int *done);
void freez(heap_t **root, heap_t **left,
		heap_t **right, heap_t **last);
void getting(heap_t *root, size_t level, heap_t **last);
size_t binary_tree_height(heap_t *root);
#endif
