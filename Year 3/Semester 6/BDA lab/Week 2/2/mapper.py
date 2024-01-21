#!/usr/bin/python3

import sys


def main():
    for line in sys.stdin:
        matrix, _, pos_ele = line.strip().partition(",")
        posi, posj, value = pos_ele.split(",")
        print(f"{matrix}\t{posi},{posj}\t{value}")


main()
