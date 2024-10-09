from collections import defaultdict
def dfs(s, adj, visited, topological):
    if visited[s]:
        return
    visited[s] = True
    for i in adj[s]:
        dfs(i, adj, visited, topological)
    topological.append(s)
    print(topological, s)
    
n, m = map(int, input().split())
adjacency_dict = defaultdict(set)
for _ in range(m):
    a, b = map(int, input().split())
    adjacency_dict[b].add(a)

visited = [False] * (n + 1)
topological = []

for i in range(1, n + 1):
    if not visited[i]:
        dfs(i, adjacency_dict, visited, topological)

print(topological)

topological_from_1 = []
i = 0
found = False
while i < len(topological):
    if not found:
        if topological[i] == 1:
            found = True
            topological_from_1.append(1)
    else:
        topological_from_1.append(topological[i])
    i += 1

dp_path_length = [0] * (n + 1)
dp_path_length[1] = 1
ancestor_array = [0] * (n + 1)
ancestor_array[1] = 0

for i in topological_from_1:
    for j in adjacency_dict[i]:
        if dp_path_length[i] < dp_path_length[j] + 1 and dp_path_length[j]:
            dp_path_length[i] = dp_path_length[j] + 1
            ancestor_array[i] = j

i = n
path = []
while i != 0:
    path.append(i)
    i = ancestor_array[i]

if len(path) < 2:
    print("IMPOSSIBLE")
    exit()

path.reverse()
print(len(path))
print(*path)
