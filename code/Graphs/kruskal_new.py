class UnionFind:
    def __init__(self, n):
        self.parent = [-1]*n
    
    def find(self, x):
        if self.parent[x] < 0:
            return x
        self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def connect(self, a, b):
        ra = self.find(a)
        rb = self.find(b)
        if ra == rb:
            return False
        if self.parent[ra] > self.parent[rb]:
            self.parent[rb] += self.parent[ra]
            self.parent[ra] = rb
        else:
            self.parent[ra] += self.parent[rb]
            self.parent[rb] = ra
        return True

# Full MST is len(spanning==n-1)
def kruskal(n, edges):
    uf = UnionFind(n)
    spanning = []
    # Sort edges by asc. weight (check+-)
    edges.sort(key = lambda d: -d[2])
    while edges and len(spanning) < n-1:
        u, v, w = edges.pop()
        if not uf.connect(u, v):
            continue
        spanning.append((u, v, w))
    return spanning