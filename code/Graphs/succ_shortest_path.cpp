#include "header.h"
// map<node, map<node, pair<cost, capacity>>>
#define graph unordered_map<int, unordered_map<int, pair<ld, int>>>  
graph g;
const ld infty = 1e60l;  // Change if necessary
ld fill(int n, vld& potential) {  // Finds max flow, min cost
	priority_queue<pair<ld, int>> pq;
	vector<bool> visited(n+2, false);
	vi parent(n+2, 0);
	vld dist(n+2, infty);
	dist[0] = 0.l;
	pq.emplace(make_pair(0.l, 0));
	while (not pq.empty()) {
		int node = pq.top().second;
		pq.pop();
		if (visited[node]) continue;
		visited[node] = true;
		for (auto& x : g[node]) {
			int neigh = x.first;
			int capacity = x.second.second;
			ld cost = x.second.first;
			if (capacity and not visited[neigh]) {
				ld d = dist[node] + cost + potential[node] - potential[neigh];
				if (d + 1e-10l < dist[neigh]) {
					dist[neigh] = d;
					pq.emplace(make_pair(-d, neigh));
					parent[neigh] = node;
	}}}}

	for (int i = 0; i < n+2; i++) {
		potential[i] = min(infty, potential[i] + dist[i]);
	}
	if (not parent[n+1]) return infty;
	ld ans = 0.l;
	for (int x = n+1; x; x=parent[x]) {
		ans += g[parent[x]][x].first;
		g[parent[x]][x].second--;
		g[x][parent[x]].second++;
	}
	return ans;
}