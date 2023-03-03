arr = [0] * 100002

def get_l(n):
    L = 0
    R = 100001
    ans = 0
    while L <= R:
        M = (L + R) // 2
        if arr[M] == n:
            return M
        elif arr[M] < n:
            L = M + 1
            ans = M
        else:
            R = M - 1
    return ans

arr[0] = 2
for i in range(1, 100002):
    arr[i] = arr[i - 1] + 3 * i + 2

t = int(input())
for i in range(t):
    n = int(input())
    c = 0
    while n > 1:
        c += 1
        L = get_l(n)
        n -= arr[L]
    print(c)
