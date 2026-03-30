data = input().split(" ")
n = int(data[0])
eta = int(data[1])
k = n // eta
a = n % eta

print(a * (k + 1) + eta * (k + 1) * k // 2)