Sum = [[0 for i in range(200001)] for j in range(4)]

def Can(i, j):
    s1 = Sum[1][j] - Sum[1][i-1]
    s2 = Sum[2][j] - Sum[2][i-1]
    s3 = Sum[3][j] - Sum[3][i-1]
    return s1 > 0 and s2 > 0 and s3 > 0

def BS(s):
    # pre
    for i in range(len(s)):
        x = int(s[i])
        Sum[1][i] = Sum[1][i-1] if i > 0 else 0
        Sum[2][i] = Sum[2][i-1] if i > 0 else 0
        Sum[3][i] = Sum[3][i-1] if i > 0 else 0
        Sum[x][i] += 1

    if not Can(0, len(s) - 1):
        return 0

    mx = float('inf')

    for i in range(len(s)):
        L = i
        R = len(s) - 1
        while L <= R:
            M = (L + R) // 2
            if Can(i, M):
                R = M - 1
                mx = min(mx, M - i + 1)
                if mx == 3:
                    return 3
            else:
                L = M + 1
    return mx

t = int(input())
for _ in range(t):
    s = input().strip()
    print(BS(s))
