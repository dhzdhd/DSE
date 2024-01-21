#!/usr/bin/python3

import sys


def main():
    raw = sys.stdin

    d = {}
    for line in raw:
        _, pos, value = line.split("\t")

        if pos not in d:
            d[pos] = int(value)
            continue
        d[pos] += int(value)

    for k, v in d.items():
        print(f"c\t{k}\t{v}")


main()
