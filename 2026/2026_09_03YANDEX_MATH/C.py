k = int(input())

n, m = 120, 120

field = []
for i in range(n):
    field.append(['#'] * m)
field[0][0] = field[0][1] = field[0][2] = field[1][2] = field[2][2] = field[1][0] = field[2][0] = field[2][1] = '.'

for i in range(1, 58):
    j = i * 2
    field[j][j + 1] = field[j][j + 2] = field[j + 1][j + 2] = field[j + 2][j + 2] = field[j + 1][j] \
                    = field[j + 2][j] = field[j + 2][j + 1] = '.'

for i in range(n):
    field[i][m - 1] = '.'

bink = []
while k > 0:
    bink.append(k % 2)
    k //= 2

for i in range(len(bink)):
    if bink[i] == 1:
        for j in range(2 * i, m):
            field[i * 2][j] = '.'

print(n, m)
for i in range(n):
    print("".join(field[i]))