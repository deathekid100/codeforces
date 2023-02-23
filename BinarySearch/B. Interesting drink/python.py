def binary_search(a, x):
    ans = 0
    l = 0
    r = len(a) - 1
    while l <= r:
        m = (l + r) // 2
        if a[m] <= x:
            ans = m + 1
            l = m + 1
        else:
            r = m - 1
    return ans

n = int(input())
a = list(map(int, input().split()))
a.sort()
q = int(input())
for i in range(q):
    x = int(input())
    print(binary_search(a, x))
