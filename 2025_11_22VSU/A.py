n = int(input())
a = [int(el) for el in input().split(" ")]

mod = int(1e9 + 7)

result = 0
curr = 1
if a[0] != 0:
    curr = a[0]
for i in range(1, n):
    if a[i - 1] != 0 and a[i] != 0:
        curr = (curr * a[i]) % mod
    elif a[i - 1] == 0 and a[i] != 0:
        curr = a[i]
    elif a[i - 1] != 0 and a[i] == 0:
        result = (result + curr) % mod
if a[-1] != 0:
    result = (result + curr) % mod
print(result)