#include "header.h"
#define graph unordered_map<ll, unordered_set<ll>>
vi bfs(int n, graph& g, vi& roots) {
    vi parents(n+1, -1); // nodes are 1..n
    unordered_set<int> visited;
    queue<int> q;
    for (auto x: roots) {
        q.emplace(x);
        visited.insert(x);
    }
    while (not q.empty()) {
        int node = q.front();
        q.pop();

        for (auto neigh: g[node]) {
            if (not in(neigh, visited)) {
                parents[neigh] = node;
                q.emplace(neigh);
                visited.insert(neigh);
            }
        }
    }
    return parents;
}
vi reconstruct_path(vi parents, int start, int goal) {
    vi path;
    int curr = goal;
    while (curr != start) {
        path.push_back(curr);
        if (parents[curr] == -1) return vi(); // No path, empty vi
        curr = parents[curr];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());
    return path;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
    graph g;
    int a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;

        if (not in(a, g)) g[a] = {b};
        else g[a].insert(b);

        if (not in(b, g)) g[b] = {a};
        else g[b].insert(a);
	}

    vi roots = {1};
    vi ans = reconstruct_path(bfs(n, g, roots), 1, n);
    if (ans.size() == 0) cout << "IMPOSSIBLE" << endl;
    else cout << ans.size() << endl << ans << endl;

	return 0;
}