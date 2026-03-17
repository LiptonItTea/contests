
    # ll n, eta;
    # cin >> n >> eta;

    # ll k = n / eta;
    # ll a = n % eta;

    # cout << a * (k + 1) + eta * (k + 1) * k / 2;  
data = input().split(" ")
n = int(data[0])
eta = int(data[1])
k = n // eta
a = n % eta

print(int(a * (k + 1) + eta * (k + 1) * k / 2))