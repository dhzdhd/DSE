#!/usr/bin/python3

import sys


def main():
    raw = sys.stdin

    for line in raw:
        matrix, pos, value = line.strip().split("\t")
        print(f"{matrix}\t{pos[::-1]}\t{value}")


main()
