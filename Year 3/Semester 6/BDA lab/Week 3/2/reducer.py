#! /usr/bin/python3

import sys

raw = sys.stdin
d = {}

for line in raw:
    year, temp = line.strip().split("\t")
    
    if year not in d:
        d[year] = [int(temp)]
        continue
    d[year].append(int(temp))

for k, v in d.items():
    print(f"{k}\t{sum(v)/len(v)}\t{min(v)}\t{max(v)}")
