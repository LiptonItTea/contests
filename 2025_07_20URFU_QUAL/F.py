import requests

def solve():
    server = input()
    port = int(input())
    a = int(input())
    b = int(input())

    resp = requests.get(f"{server}:{port}", params={"a": a, "b": b})
    
    # подготовка результата result
    arr = sorted(resp.json(), reverse=True)

    output = ""
    for i in arr:
        if i < 0:
            continue
        output += str(i) + "\n"
    print(output)
    
solve()