def divInRange(min_val, max_val, k):
    min_val -= 1
    return max_val // k - (min_val // k)

def BS(n, k):
    L = 1
    R = n * k
    ans = 0
    while L <= R:
        M = (L + R) // 2
        min_val = n + M - 1
        max_val = n * M
        count = divInRange(min_val, max_val, k)

        if count > 0:
            ans = M
            R = M - 1
        else:
            L = M + 1
    return ans

t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    print(BS(n, k))
