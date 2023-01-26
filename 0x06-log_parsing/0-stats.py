#!/usr/bin/python3

import sys


if __name__ == "__main__":
    status = {"200": 0,
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
        """ Read, parse and grab data"""
        try:
            parsed_line = line.split()
            status_code = parsed_line[-2]
            if status_code in status.keys():
                status[status_code] += 1
            return int(parsed_line[-1])
        except Exception:
            return 0

    def print_stats():
        """print stats"""
        print("File size: {}".format(size))
        for key in sorted(status.keys()):
            if status[key]:
                print("{}: {}".format(key, status[key]))

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
