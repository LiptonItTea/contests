t = int(input())

for _ in range(t):
    n = int(input())
    s = input()

    prefa = [0] * (n + 1)
    for i in range(n):
        prefa[i + 1] = prefa[i]
        if s[i] == 'a':
            prefa[i + 1] += 1

    prefb = [0] * (n + 1)
    for i in range(n):
        prefb[i + 1] = prefb[i]
        if s[i] == 'b':
            prefb[i + 1] += 1

    # solve for a
    resulta = 0
    for i in range(n):
        if s[i] == 'a':
            resulta += min(prefb[i + 1], prefb[n] - prefb[i + 1])

    # solve for b
    resultb = 0
    for i in range(n):
        if s[i] == 'b':
            resultb += min(prefa[i + 1], prefa[n] - prefa[i + 1])

    print(min(resulta, resultb))