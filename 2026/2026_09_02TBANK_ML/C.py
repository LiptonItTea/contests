n, t = map(int, input().split(" "))

h_counts = [n] * n
v_counts = [n] * n
d1_count = n
d2_count = n

arr = list(map(int, input().split(" ")))

for i in range(t):
    a = arr[i] - 1

    y = a // n
    x = a % n
    h_counts[y] -= 1
    v_counts[x] -= 1
    if y == x:
        d1_count -= 1
    if y == n - 1 - x:
        d2_count -= 1

    if h_counts[y] == 0 or v_counts[x] == 0 or d1_count == 0 or d2_count == 0:
        print(i + 1)
        exit(0)

print(-1)