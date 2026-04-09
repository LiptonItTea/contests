s = input()
n = len(s)
full = n * (n - 1) // 2
cnt = 0
for i in range(n):
    for j in range(i + 1, n):
        if s[i] > s[j]:
            cnt += 1
print(min(full - cnt, cnt))
