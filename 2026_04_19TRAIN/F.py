l, r = map(int, input().split(" "))

result = -1
for m in range(int(1e6), 1, -1):
    if l % m == 0 and l + m <= r:
        result = max(m, result)
        print(l, l + m)
        quit()
    if l - l % m + 2 * m <= r:
        result = max(m, result)
        print(l - l % m + m, l - l % m + 2 * m)
        quit()

if result == -1:
    print(l, l + 1)
    quit()
