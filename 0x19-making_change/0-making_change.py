#!/usr/bin/python3
"""function"""


def makeChange(coins, total):
    """function"""
    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)
    count = 0

    while total != 0 and coins:
        while coins[0] <= total:
            total -= coins[0]
            count += 1

        coins.pop(0)

    if total != 0:
        return -1
    else:
        return count
