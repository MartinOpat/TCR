N = 100000 # arr max size
tree = [0] * (2 * N) # tre max size

def build(arr, n):
    for i in range(n):
        tree[n + i] = arr[i]

    for i in range(n - 1, 0, -1):
        tree[i] = tree[i << 1] + tree[i << 1 | 1]

def updateTreeNode(p, value, n):
    tree[p + n] = value
    p = p + n

    i = p  # move upward, update parents
    while i > 1:
        tree[i >> 1] = tree[i] + tree[i ^ 1]
        i >>= 1

def query(l, r, n):  # sum [l, r)
    res = 0
    l += n
    r += n
    while l < r:
        if l & 1:
            res += tree[l]
            l += 1
        if r & 1:
            r -= 1
            res += tree[r]
        l >>= 1
        r >>= 1
    return res
