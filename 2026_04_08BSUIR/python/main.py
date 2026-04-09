

def solve():
    s = input()
    print(kmp_search(s, "ai")[0])

t = int(input())
for _ in range(t):
    solve()