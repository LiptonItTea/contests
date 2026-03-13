import re

regex = re.compile(
    r'^M{0,3}(CM|CD|D?C{0,3})'
    r'(XC|XL|L?X{0,3})'
    r'(IX|IV|V?I{0,3})$'
)

def roman(roman: str) -> int:
    values = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    total = 0
    prev_value = 0

    for char in reversed(roman.upper()):
        value = values.get(char)

        if value < prev_value:
            total -= value
        else:
            total += value
            prev_value = value

    return total

dec = []
while True:
    data = input()
    if data == '0':
        break
    if not data or not regex.match(data):
        print(0)
        exit(0)
    
    try:
        dec.append(roman(data))
    except Exception:
        print(0)
        exit(0)

dec = sorted(dec, reverse=True)
chosen = set()
for el in dec:
    if el in chosen:
        continue
    chosen.add(el)
    if len(chosen) == 3:
        break

if len(chosen) < 3:
    print(0)
    exit(0)

result = 1
for el in chosen:
    result *= el

nums = {i: c for i, c in enumerate('0123456789abcdefghijklmnopqrstuvwxyz')}
sres = ""
while result > 0:
    sres += nums[result % 36]
    result //= 36

print(sres[::-1])