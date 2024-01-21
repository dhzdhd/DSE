#!/usr/bin/python3

import sys


def main():
    for line in sys.stdin:
        regd, name, marks = line.strip().split(",")
        print(f"{regd}\t{name}\t{marks}")


main()
