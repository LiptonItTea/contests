n = int(input())
links = []
for i in range(n + 1):
    links.append([])

for i in range(n):
    u, v = map(int, input().split(" "))
    links[u - 1].append(v - 1)

def make_canonical(curr):
    children = []
    for next in links[curr]:
        children.append(make_canonical(next))

    children = sorted(children)

    return "(" + "".join(children) +  ")"

canonical = make_canonical(0)

dp = {"()": 1.0}

class Node:
    cons = []

def parse(string: str, pos = 0):
    v = Node()
    pos += 1

    while pos < len(string) and string[pos] == '(':
        v.cons.append(parse(string, ))