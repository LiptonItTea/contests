n, m = map(int, input().split(" "))

def to_sept(x: int):
    result: list[int] = []
    x -= 1

    if x == 0:
        return [0]
    
    while x > 0:
        result.append(x % 7)
        x //= 7

    return result[::-1]

n7 = to_sept(n)
m7 = to_sept(m)

if len(n7) + len(m7) > 7:
    print(0)
    exit(0)

allowed_n = [n7[i] if i == 0 else 6 for i in range(len(n7))]
allowed_m = [m7[i] if i == 0 else 6 for i in range(len(m7))]

answer = 0
current: list[int] = []
def iterate(size: int):
    global answer
    if size < len(allowed_n):
        for i in range(allowed_n[size] + 1):
            current.append(i)
            iterate(size + 1)
            current.pop()
    elif size < len(allowed_n) + len(allowed_m):
        for i in range(allowed_m[size - len(allowed_n)] + 1):
            current.append(i)
            iterate(size + 1)
            current.pop()
    else:
        if current[:len(allowed_n)] > n7:
            return
        if current[len(allowed_n):] > m7:
            return
        # check
        check: set[int] = set()
        for el in current:
            if el in check:
                return
            check.add(el)
        answer += 1

iterate(0)
print(answer)