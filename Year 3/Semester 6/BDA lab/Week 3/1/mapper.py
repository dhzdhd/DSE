#! /usr/bin/python3
import sys

raw = sys.stdin
for line in raw:
    _, _, unit, _, sal = line.strip().split(",")
    print(f"{unit}\t{sal}")

