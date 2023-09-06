#!/usr/bin/python3
"""sunctions"""


def isWinner(x, nums):
    """functions"""
    if not nums or x < 1:
        return None
    max_n = max(nums)
    filters = [True for _ in range(max(max_n + 1, 2))]
    for i in range(2, int(pow(max_n, 0.5)) + 1):
        if not filters[i]:
            continue
        for j in range(i * i, max_n + 1, i):
            filters[j] = False
    filters[0] = filters[1] = False
    c = 0
    for i in range(len(filters)):
        if filters[i]:
            c += 1
        filters[i] = c
    p_1 = 0
    for max_n in nums:
        p_1 += filters[max_n] % 2 == 1
    if p_1 * 2 == len(nums):
        return None
    if p_1 * 2 > len(nums):
        return "Maria"
    return "Ben"
