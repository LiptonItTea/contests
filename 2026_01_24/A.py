s = input()

ciphers = [0] * 10
for c in s:
    ciphers[ord(c) - ord('0')] += 1

# print(ciphers)
result = ""
for i in range(1, 10):
    if ciphers[i] != 0:
        result += str(i)
        ciphers[i] -= 1
        break

for i in range(10):
    while ciphers[i] != 0:
        result += str(i)
        ciphers[i] -= 1

print(result)