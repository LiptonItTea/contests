n = int(input())
arr = list(map(int, input().split(" ")))

arr = sorted(arr)

for i in range(2, n):
    if arr[0] + arr[1] != arr[i]:
        print("NO")
        exit(0)

print("YES")