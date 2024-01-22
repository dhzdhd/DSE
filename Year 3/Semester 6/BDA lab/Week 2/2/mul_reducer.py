#!/usr/bin/python3

import sys
import numpy as np


def main():
    raw = sys.stdin

    m1 = [[0] * 3 for _ in range(3)]
    m2 = [[0] * 3 for _ in range(3)]
    for line in raw:
        matrix, pos, value = line.split("\t")
        match matrix:
            case "a":
                m1[int(pos[0])][int(pos[-1])] = int(value)
            case "b":
                m2[int(pos[0])][int(pos[-1])] = int(value)

    m3 = np.matmul(m1, m2)
    for l in range(len(m3)):
        for i in range(len(m3[l])):
            print(f"c\t{l},{i}\t{m3[l][i]}")


main()
