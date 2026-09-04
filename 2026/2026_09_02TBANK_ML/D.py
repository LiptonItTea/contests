n, k = map(int, input().split(" "))

found = set()
idx = 0
result = []
while k > 0:
    place = min(n - idx, k + 1)
    k -= place - 1
    result.append(place)
    found.add(place)
    idx += 1

for i in range(n):
    if (i + 1) not in found:
        result.append(i + 1)

print("".join([str(el) + " " for el in result]))