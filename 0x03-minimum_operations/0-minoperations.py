#!/usr/bin/python3
""" calucle pgcd like
12 devided by 2 = 6 => 6 / 2 = 3 => 3 / 3 = 1
it's 7 => 2 + 2 + 3
"""


def minOperations(n):
    """
    method that calculates the fewest operations
    """
    new = n
    i = 2
    count = 0
    if (not isinstance(n, int)):
        return 0
    if n < 2:
        return 0
    while new != 1:
        if new % i == 0:
            new = new / i
            count += i
        else:
            i = i + 1
    return count
