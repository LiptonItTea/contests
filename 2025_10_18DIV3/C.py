t = int(input())

for _ in range(t):
    data = input().split(" ")
    n = int(data[0])
    k = int(data[1])

    a = [int(el) for el in input().split(" ")]
    remap = [0] * (n + 1)
    for i in range(n):
        remap[a[i]] += 1

    result = 0
    for i in range(k):
        if remap[i] == 0:
            result += 1
    if remap[k] != 0 and result < remap[k]:
        result += remap[k] - result
    print(result)