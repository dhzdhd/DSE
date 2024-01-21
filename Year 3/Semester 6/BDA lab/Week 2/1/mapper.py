#!/usr/bin/python3

import sys


def main():
    for line in sys.stdin:
        for word in line.strip().split():
            print(f"{word}\t1")


main()
