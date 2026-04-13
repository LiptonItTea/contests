from math import floor

n, k = map(float, input().split())
a = pow(floor(n / k), 3)
b = pow(floor((n + k / 2) / k), 3)
if k % 2:
    print(a)
else:
    print(a + b)