t = int(input())

for _ in range(t):
    n = int(input())
    arr = [int(el) for el in input().split(" ")]

    zeros = 0
    negs = 0
    for i in range(n):
        if arr[i] < 0:
            negs += 1
        elif arr[i] == 0:
            zeros += 1
            
    print(zeros + negs % 2 * 2)