s, n = [int(el) for el in input().split(" ")]

pw = 1
result = 0
while True:
    data = [int(el) for el in input().split(" ")]
    good = False
    for el in data:
        if el != 0:
            good = True
            break
    if not good:
        break
    
    for el in data:
        result += el * pw
    pw *= s

sres = ""
while result > 0:
    sres += str(result % s)
    result //= s

print(sres[::-1])