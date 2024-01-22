#! /usr/bin/python3
import sys

raw = sys.stdin
for line in raw:
    year, temp = line.strip().split(",")
    print(f"{year}\t{temp}")

