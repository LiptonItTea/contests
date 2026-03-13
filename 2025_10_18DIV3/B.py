t = int(input())

for _ in range(t):
    n = int(input())
    a = [int(el) for el in input().split(" ")]
    a = sorted(a)

    biggest = 0
    for i in range(n // 2):
        biggest = max(biggest, a[i * 2 + 1] - a[i * 2])
    print(biggest)