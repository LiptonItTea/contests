n = int(input())
one = input()
two = input()

three = [0] * n
not_zero = n - 1
for i in range(n):
    three[i] = int(not (one[i] == two[i]))
    
    if three[i] == 1 and not_zero == n - 1:
        not_zero = i

print("".join(map(str, three[not_zero:])))