def lcp(x, y, P):
    res = 0
    if x == y:
        return n - x 
    for k in range(len(P) - 1, -1, -1):
        if x >= n or y >= n:
            break
        if P[k][x] == P[k][y]:
            x += 1 << k
            y += 1 << k
            res += 1 << k
    return res
