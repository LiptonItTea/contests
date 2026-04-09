def solve(b, s):
    def f(d):
        return 2 * d ** 3 + 3 * d ** 2 * b + d * b ** 2 - 2 * s * b

    def df(d):
        return 6 * d ** 2 + 6 * b * d + b ** 2

    def newton(f, df, start_x=0, eps=1e-6):
        x = start_x
        prev_x = x - 1

        while abs(x - prev_x) > eps:
            delta = f(x) / df(x)
            prev_x = x
            x -= delta

        return x

    return newton(f, df, start_x=int(1e9))


print(solve(10, 10))