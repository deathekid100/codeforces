def CanReadMBooks(a, M, n, t):
    sum = 0
    for i in range(M):
        sum += a[i]
    if sum <= t:
        return True
    for i in range(M, n):
        sum += a[i] - a[i - M]
        if sum <= t:
            return True
    return False

def BS(a, n, t):
    L = 0
    R = n
    ans = 0
    while L <= R:
        M = (L + R) // 2
        if CanReadMBooks(a, M, n, t):
            L = M + 1
            ans = M
        else:
            R = M - 1
    return ans

n, t = map(int, input().split())
a = list(map(int, input().split()))
print(BS(a, n, t))
