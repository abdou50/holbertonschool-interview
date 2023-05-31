#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void siftDown(int *array, int start, int end)
{
    int root = start;

    while (2 * root + 1 <= end) {
        int child = 2 * root + 1;
        int swapIndex = root;

        if (array[swapIndex] < array[child])
            swapIndex = child;

        if (child + 1 <= end && array[swapIndex] < array[child + 1])
            swapIndex = child + 1;

        if (swapIndex == root)
            return;
        else {
            swap(&array[root], &array[swapIndex]);
            root = swapIndex;
        }
    }
}
void heap_sort(int *array, size_t size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        siftDown(array, i, size - 1);

    for (int i = size - 1; i >= 0; i--) {
        swap(&array[0], &array[i]);
        print_array(array,size);
        siftDown(array, 0, i - 1);
    }
    }