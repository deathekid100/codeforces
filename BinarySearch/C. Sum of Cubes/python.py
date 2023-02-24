import bisect

def pre():
    pow3 = [i ** 3 for i in range(1000001)]
    return pow3

def is_pow3(n):
    if n <= 0:
        return False
    x = bisect.bisect_left(pow3, n)
    return x < len(pow3) and pow3[x] == n

def search(n):
    x = int(n ** (1 / 3.00000))
    for i in range(1, x + 1):
        pi = pow3[i]
        R = n - pi
        if is_pow3(R):
            print("YES")
            return
    print("NO")

pow3 = pre()
t = int(input())
for _ in range(t):
    n = int(input())
    search(n)
