from math import floor

data = []
while True:
    num, den = [int(el) for el in input().split(" ")]
    if num == 0 and den == 0:
        break

    data.append((num, den))

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

cur_num = data[0][0]
cur_den = data[0][1]
for num, den in data[1:]:
    temp = cur_den

    cur_den *= den
    cur_num *= den

    num *= temp
    den *= temp

    cur_num += num

    div = gcd(max(cur_num, cur_den), min(cur_num, cur_den))
    cur_num //= div
    cur_den //= div

if cur_num % cur_den == 0:
    print(cur_num // cur_den)
    exit(0)

q = cur_den
k2 = 0
while q % 2 == 0:
    q //= 2
    k2 += 1
k5 = 0
while q % 5 == 0:
    q //= 5
    k5 += 1

if q == 1:
    print(cur_num / cur_den)
    exit(0)

k = 1
temp = 10
while temp % q != 1:
    temp = (temp * 10) % q
    k += 1

shit = []
shit_state = (cur_num % cur_den) * 10
for i in range(k2 + k5 + k):
    shit.append(str(shit_state // cur_den))
    shit_state = (shit_state % cur_den) * 10

# todo maybe floor * 10 for better accuracy
# print(k2 + k5, shit)
print(cur_num // cur_den, ".", "".join(shit[:k2 + k5]), f"({"".join(shit[k2 + k5:])})", sep="")