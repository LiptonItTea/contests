import requests

def solve():
    server = input()
    port = int(input())
    a = int(input())
    b = int(input())

    resp = requests.get(f"{server}:{port}", params={"a": a, "b": b})
    
    # подготовка результата result
    json = resp.json()
    result = sorted(json['result'])
    check = json['check']

    output = ""
    for r in result:
        output += str(r) + " "
    output += '\n'
    output += check
    print(output)

solve()