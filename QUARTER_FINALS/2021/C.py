import sys
import math
input = sys.stdin.readline

INF_NEG = -10**30

t = int(input())
for _ in range(t):
    n, k, x, y = map(int, input().split())
    people = []
    for _ in range(n):
        s, f = input().split()
        f = int(f)
        if s == 'A':
            vA = f
            vB = f - x
        else:  # s == 'B'
            vA = f - y
            vB = f
        d = vA - vB
        people.append((d, vA, vB))

    # Sort by d descending
    people.sort(key=lambda z: z[0], reverse=True)

    # Prefix: best sum of top-k vA among indices [0..i]
    import heapq
    pref = [INF_NEG] * n
    heapA = []
    sumA = 0
    for i in range(n):
        a = people[i][1]
        heapq.heappush(heapA, a)
        sumA += a
        if len(heapA) > k:
            sumA -= heapq.heappop(heapA)
        if len(heapA) == k:
            pref[i] = sumA

    # Suffix: best sum of top-k vB among indices [i..n-1]
    suf = [INF_NEG] * (n + 1)  # suf[i] uses indices i..n-1
    heapB = []
    sumB = 0
    for i in range(n - 1, -1, -1):
        b = people[i][2]
        heapq.heappush(heapB, b)
        sumB += b
        if len(heapB) > k:
            sumB -= heapq.heappop(heapB)
        if len(heapB) == k:
            suf[i] = sumB

    # Try every split: prefix [0..i] for A, suffix [i+1..n-1] for B
    ans = INF_NEG
    for i in range(k - 1, n - k):
        if pref[i] != INF_NEG and suf[i + 1] != INF_NEG:
            ans = max(ans, pref[i] + suf[i + 1])

    print(ans)
