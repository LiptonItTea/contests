s = input()

study = [10 ** 9] * (len(s) - 3)
study_min = [10 ** 9] * (len(s) - 3)
for i in range(len(s) - 4):
    current = 0
    if s[i] == 's':
        current += 1
    if s[i + 1] == 't':
        current += 1
    if s[i + 2] == 'u':
        current += 1
    if s[i + 3] == 'd':
        current += 1
    if s[i + 4] == 'y':
        current += 1
    study_min[i + 1] = min(study_min[i], 5 - current)
    study[i + 1] = 5 - current

tbank = [10 ** 9] * (len(s) - 3)
tbank_min = [10 ** 9] * (len(s) - 3)
for i in range(len(s) - 4):
    current = 0
    if s[i] == 't':
        current += 1
    if s[i + 1] == 'b':
        current += 1
    if s[i + 2] == 'a':
        current += 1
    if s[i + 3] == 'n':
        current += 1
    if s[i + 4] == 'k':
        current += 1
    tbank_min[i + 1] = min(tbank_min[i], 5 - current)
    tbank[i + 1] = 5 - current
    
best = 10 ** 9
for i in range(5, len(s) - 3):
    best = min(best, tbank[i] + study_min[i - 5])
for i in range(5, len(s) - 3):
    best = min(best, study[i] + tbank_min[i - 5])

print(best)