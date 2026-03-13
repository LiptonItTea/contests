def sign(a):
    if a > 0:
        return 1
    elif a == 0:
        return 0
    return -1

sides_vertical = {
    "NORTH": [0, 1],
    "EAST": [1, 0],
    "SOUTH": [0, -1],
    "WEST": [-1, 0],   
}

sides_diag = {
    "NORTHEAST": [1, 1],
    "SOUTHEAST": [1, -1],
    "SOUTHWEST": [-1, -1],
    "NORTHWEST": [-1, 1],
}

n, ex, ey = [int(el) for el in input().split(" ")]

side = input()
if side in sides_vertical:
    curr_sign_x, curr_sign_y = sides_vertical[side]
else:
    curr_sign_x, curr_sign_y = sides_diag[side]


enemies = []
for i in range(n):
    enemies.append([int(el) for el in input().split(" ")])

minlen = 1e10
minind = -1
for i in range(n):
    x, y = enemies[i]

    dx = x - ex
    dy = y - ey
    if side in sides_vertical and sign(dx) == curr_sign_x and sign(dy) == curr_sign_y:
        if minlen > dx ** 2 + dy ** 2:
            minlen = dx ** 2 + dy ** 2
            minind = i
    if side in sides_diag and sign(dx) == curr_sign_x and sign(dy) == curr_sign_y and abs(dx) == abs(dy):
        if minlen > dx ** 2 + dy ** 2:
            minlen = dx ** 2 + dy ** 2
            minind = i
    if dx == 0 and dy == 0:
        if minlen > dx ** 2 + dy ** 2:
            minlen = dx ** 2 + dy ** 2
            minind = i

if minind == -1:
    print(-1)
    exit()
print(enemies[minind][0], enemies[minind][1])