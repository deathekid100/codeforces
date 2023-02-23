def calc(p, k):
    return k + (5 * p * (p + 1)) // 2

def BS(n, k):
    ans = 0
    l = 0
    r = n

    while l <= r:
        m = (l + r) // 2
        c = calc(m, k)
        if c == 240:
            return m
        if c < 240:
            ans = m
            l = m + 1
        else:
            r = m - 1
    return ans

n, k = map(int, input().split())
print(BS(n, k))
