def BS(a, n, x):
    L, R, ans = 0, n - 1, 0
    while L <= R:
        M = (L + R) // 2
        if a[M] >= x:
            ans = M
            R = M - 1
        else:
            L = M + 1
    print(ans + 1)

n = int(input())
a = [0] * n
a[0] = int(input())
for i in range(1, n):
    x = int(input())
    a[i] = a[i - 1] + x
q = int(input())
for i in range(q):
    x = int(input())
    BS(a, n, x)
