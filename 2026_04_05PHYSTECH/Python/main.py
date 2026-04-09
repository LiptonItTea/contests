from math import gcd
from itertools import permutations


def solve():
    b = [1, 2, 3, 4]
    a = permutations(b, 4)
    p = [x for x in zip(a)]
    p = [x[0] for x in p]
    sms = []
    for y in p:
        res = []
        for i in range(4):
            res.append(b[i] + y[i])
        sms.append(res)
    mx = 0
    mn = 100000000000
    idxmn = -1
    idxmx = -1
    xors = []
    for i in range(24):
        xor = 0
        for y in sms[i]:
            xor ^= y
        if xor == 14:
            print(f'14:   {p[i]}')
        xors.append(xor)
    print(xors)
solve()
