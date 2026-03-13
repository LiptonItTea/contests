k, l, m, n = [int(el) for el in input().split(" ")]

amount = int(input())
seen = set()
result = 0
for _ in range(amount):
    x, y, z, w = [int(el) for el in input().split(" ")]
    seen.add((x, y, z, w))

for x, y, z, w in seen:
    for u in range(-1, 2):
        for i in range(-1, 2):
            for j in range(-1, 2):
                for h in range(-1, 2):
                    if k < x + i or x + i <= 0 or l < y + j or y + j <= 0 or m < z + h or z + h <= 0 or n < w + u or w + u <= 0:
                        continue
                    if (x + i, y + j, z + h, w + u) in seen:
                        print(x + i, y + j, z + h, w + u)
                        continue
                    result += 1

    # result -= 1 # central-most

print(result)