def solve():
    import sys
    input = sys.stdin.readline
    
    n, k = map(int, input().split())
    a = list(map(int, input().split()))

    from collections import defaultdict

    count = defaultdict(int)
    l = 0
    unique = 0
    ans = 0

    for r in range(n):
        if count[a[r]] == 0:
            unique += 1
        count[a[r]] += 1

        while unique > k:
            count[a[l]] -= 1
            if count[a[l]] == 0:
                unique -= 1
            l += 1

        ans = max(ans, r - l + 1)

    print(ans)
solve()