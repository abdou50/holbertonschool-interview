#!/usr/bin/python3
""" function"""

import sys


if __name__ == "__main__":
    st_file = {"200": 0,
               "301": 0,
               "400": 0,
               "401": 0,
               "403": 0,
               "404": 0,
               "405": 0,
               "500": 0}
    count = 1
    size = 0

    def parse_line(line):
        """ Read parse"""
        try:
            parsed_line = line.split()
            status_code = parsed_line[-2]
            if status_code in st_file.keys():
                st_file[status_code] += 1
            return int(parsed_line[-1])
        except Exception:
            return 0

    def print_stats():
        """print stats """
        print("File size: {}".format(size))
        for key in sorted(st_file.keys()):
            if st_file[key]:
                print("{}: {}".format(key, st_file[key]))

    try:
        for line in sys.stdin:
            size += parse_line(line)
            if count % 10 == 0:
                print_stats()
            count += 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
