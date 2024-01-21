#!/usr/bin/python3

import sys


def main():
    raw = sys.stdin

    d = {}
    for line in raw:
        word, amount = line.split("\t")

        if word not in d:
            d[word] = int(amount)
            continue
        d[word] += int(amount)

    for k, v in d.items():
        print(f"{k}\t{v}")


main()
