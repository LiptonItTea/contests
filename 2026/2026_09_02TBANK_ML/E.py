n, k = map(int, input().split(" "))

arr = sorted(list(map(int, input().split(" "))))

neg = []
zero = 0
pos = []
for i in range(n):
    if arr[i] < 0:
        neg.append(arr[i])
    elif arr[i] == 0:
        zero += 1
    else:
        pos.append(arr[i])

neg = sorted(neg, reverse=True)

def count_less(array: list[int], c: int):
    result = 0
    i = 0
    j = len(array) - 1
    while i < j:
        while i < j and array[i] * array[j] >= c:
            j -= 1
        if i < j:
            result += j - i
            i += 1
    return result

mx = max(abs(x) for x in arr)

l = -mx * mx
r = mx * mx + 1
while r - l > 1:
    c = (l + r) // 2

    count = 0
    if c > 0:
        count += len(neg) * len(pos)
        count += len(neg) * zero
        count += zero * len(pos)
        count += zero * (zero - 1) // 2
        count += count_less(pos, c) + count_less(neg, c)
    elif c == 0:
        count += len(neg) * len(pos)
    else: # negative
        j = 0
        for i in reversed(range(len(pos))):
            while j < len(neg) and neg[j] * pos[i] >= c:
                j += 1
            count += len(neg) - j
    
    if count < k:
        l = c
    else:
        r = c

print(r - 1)