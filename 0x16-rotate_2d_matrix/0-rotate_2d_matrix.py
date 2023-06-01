#!/usr/bin/python3
"""
Test 0x16 - Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """matrix rotate"""
    n = len(matrix)
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
    for i in range(n):
        matrix[i] = matrix[i][::-1]
