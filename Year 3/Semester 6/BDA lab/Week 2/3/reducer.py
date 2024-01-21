#!/usr/bin/python3

import sys

current_name = None


def main():
    sorted_names = []

    for line in sys.stdin:
        regd, name, marks = line.strip().split("\t")
        sorted_names.append((regd, name, marks))

    for regd, name, marks in sorted(sorted_names, key=lambda v: v[1]):
        print(f"{regd}\t{name}\t{marks}")


main()
