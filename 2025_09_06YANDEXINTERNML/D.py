n1 = int(input())
c1 = []

for i in range(n1):
    temp = input().split(" ")
    x1 = float(temp[0])
    y1 = float(temp[1])
    c1.append([x1, y1])

n2 = int(input())
c2 = []

for i in range(n2):
    temp = input().split(" ")
    x2 = float(temp[0])
    y2 = float(temp[1])
    c2.append([x2, y2])

temp = input().split(" ")
xp = float(temp[0])
yp = float(temp[1])

x = c1 + c2
y = [0] * n1 + [1] * n2

import numpy as np

x = np.array(x)
y = np.array(y)
x[:, 0] -= xp
x[:, 1] -= yp

from sklearn.svm import LinearSVC

svc = LinearSVC(random_state=39, C=1, fit_intercept=False, class_weight='balanced', tol=1e-8, max_iter=1000)
svc.fit(x, y)

y_pred = svc.predict(x)
for i in range(y_pred.shape[0]):
    if y_pred[i] != y[i]:
        print(-1)
        exit(0)

w = svc.coef_[0]

def get_best(w, x):
    best_dist = 1000000
    for i in range(x.shape[0]):
        best_dist = min(best_dist, np.abs(w[0] * x[i, 0] + w[1] * x[i, 1]))
    return best_dist / np.sqrt(w[1] ** 2 + w[0] ** 2)

# print(best_dist / np.sqrt(w[1] ** 2 + w[0] ** 2))

import math

alpha = math.atan2(-w[0], w[1])
alpha_res = get_best(w, x)

iters = 1000
delta = math.pi / 8

for i in range(iters):
    left = alpha - delta
    w = [-math.tan(left), 1]
    left_res = get_best(w, x)

    right = alpha + delta
    w = [-math.tan(right), 1]
    right_res = get_best(w, x)

    if left_res > alpha_res:
        alpha_res = left_res
        alpha = left
    
    if right_res > alpha_res:
        alpha_res = right_res
        alpha = right
    
    delta /= 2

print(alpha_res)