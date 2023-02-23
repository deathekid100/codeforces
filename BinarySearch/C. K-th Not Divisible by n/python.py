def kth(M, n):
    return M - M // n

def BS(n, k):
    L = 1
    R = n * k
    while L <= R:
        M = (L + R) // 2
        K = kth(M, n)
        if K == k and M % n != 0:
            return M
        if K < k:
            L = M + 1
        else:
            R = M - 1
    return 0

t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    print(BS(n, k))
