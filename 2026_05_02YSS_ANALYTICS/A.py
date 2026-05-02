n = int(input())
our = input()
adv = input()

pref = []
for i in range(n + 1):
    pref.append([0] * 3)
for i in range(n):
    pref[i + 1][0] = pref[i][0] + (1 if adv[i] == 'a' else 0)
    pref[i + 1][1] = pref[i][1] + (1 if adv[i] == 'b' else 0)
    pref[i + 1][2] = pref[i][2] + (1 if adv[i] == 'c' else 0)

counts = [0] * 3
for i in range(n):
    counts[ord(our[i]) - ord('a')] += 1

result = []
for i in range(n):
    for c in range(3):
        if chr(ord('a') + c) == adv[i]:
            continue
        if counts[c] == 0:
            continue

        counts[c] -= 1

        good = True
        for j in range(3):
            if counts[j] > (n - i - 1) - (pref[n][j] - pref[i + 1][j]):
                good = False
                break

        if good:
            result.append(chr(ord('a') + c))
            break

        counts[c] += 1

print("".join(result))