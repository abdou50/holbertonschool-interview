#!/usr/bin/python3
"""
0-main
"""


def pascal_triangle(n):
    """"triangle de pascal arr[i] + [i - 1]"""
    if n <= 0:
        return []
    triangle = [[1]]
    for i in range(1, n):
        prev = triangle[-1]
        NEW = [1]
        for i in range(1, len(prev)):
            NEW.append(prev[i - 1] + prev[i])
        NEW.append(1)
        triangle.append(NEW)
    return triangle
