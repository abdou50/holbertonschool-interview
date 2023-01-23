#ifndef sandpiles_h
#define sandpiles_h
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void permutation(int grid1[3][3]);
static void print_grid(int grid[3][3]);
int is_stable(int grid[3][3]);
void addition(int grid1[3][3], int grid2[3][3]);
#endif
