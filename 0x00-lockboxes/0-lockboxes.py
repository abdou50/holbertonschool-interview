#!/usr/bin/python3
"""function"""


def canUnlockAll(boxes):
    t = [0]
    for j, i in enumerate(boxes):
        for keys in i:
            if keys != j and keys not in t:
                t.append(keys)
    if len(t) == len(boxes):
        return True
    return False
