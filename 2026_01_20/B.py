s = input()

a = 0
ab = 0
abc = 0
for i in range(len(s)):
    if s[i] == 'a':
        a += 1
    elif s[i] == 'b':
        ab += a
    elif s[i] == 'c':
        abc += ab

print(abc)