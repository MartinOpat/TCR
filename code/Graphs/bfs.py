from collections import deque
def bfs(g, roots, n):
    q = deque(roots)
    explored = set()
    distances = [0 if v in roots else float('inf') for v in range(n)]
    while len(q) != 0:
        node = q.popleft()
        if node in explored: continue
        explored.add(node)
        for neigh in g[node]:
            if neigh not in explored:
                q.append(neigh)
                if distances[neigh] == float('inf'):
                    distances[neigh] = distances[node] + 1
    return distances
