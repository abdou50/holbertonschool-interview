#!/usr/bin/python3
"""
A character in UTF8 can be from 1 to 4 bytes long
For 1-byte character, the first bit is a 0, followed by its unicode code.
For n-bytes character, the first n-bits are all one's, the n+1 bit is 0,
followed by n-1 bytes with most significant 2 bits being 10.
This is how the UTF-8 encoding would work:
"""


def validUTF8(data):
    """
    :type data: List[int]
    :rtype: bool
    """
    count = 0
    for c in data:
        if count == 0:
            if (c >> 5) == 0b110:
                count = 1
            elif (c >> 4) == 0b1110:
                count = 2
            elif (c >> 3) == 0b11110:
                count = 3
            elif (c >> 7):
                return False
        else:
            if (c >> 6) != 0b10:
                return False
            count -= 1
    return count == 0
