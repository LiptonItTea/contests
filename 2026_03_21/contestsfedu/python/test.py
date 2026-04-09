from math import floor, ceil

w, h, d = map(int, input().split())
res =ceil((w * h - d * w) / (d * h ))
print(res)
