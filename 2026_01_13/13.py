n, l = [int(el) for el in input().split(" ")]

for i in range(n):
    data = input()

    depth = 0
    j = 0
    result = ""
    while j < len(data):
        if data[j] in '([':
            depth += 1
        elif data[j] in ')]':
            depth -= 1
        else:
            if depth == l:
                while j < len(data) and data[j] not in '([])':
                    result += data[j]
                    j += 1
                continue
        j += 1
    
    if result == "":
        print('()')
    else:
        print(result)