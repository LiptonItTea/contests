def f(n, k, x):
    if x > k * n or x < n:
        return 1e20
    return abs(n * (k + 1) - 2 * x)

n = int(input())
k = int(input())
s1 = int(input())
s2 = int(input())

f1 = f(n, k, s1)
f2 = f(n, k, s2)

if (f1 < f2):
    print("First")
elif(f1 == f2):
    print("Equal")
else:
    print("Second")