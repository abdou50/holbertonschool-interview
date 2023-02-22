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
    function
    """
    i = 0
    while i < len(data):
        size = 0
        shift = 1 << 7
        while shift & data[i]:
            size += 1
            shift >>= 1
        if size == 0:
            pass
        elif size == 1 or size > 4:
            return False
        else:
            for j in range(i + 1, i + size):
                if j >= len(data) or (data[j] >> 6) != 2:
                    return False
            i += size - 1
        i += 1
    return True
