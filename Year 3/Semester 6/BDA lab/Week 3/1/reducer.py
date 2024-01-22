#! /usr/bin/python3

import sys

raw = sys.stdin
d = {}

for line in raw:
    unit, sal = line.strip().split("\t")
    
    if unit not in d:
        d[unit] = int(sal)
        continue
    d[unit] += int(sal)

for k, v in d.items():
    print(f"{k}\t{v}")
