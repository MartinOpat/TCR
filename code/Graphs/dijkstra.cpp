#include "header.h"
vector<int> dijkstra(int n, int root, map<int, vector<pair<int, int>>>& g) {
	unordered_set<int> visited;
	vector<int> dist(n, INF);
    priority_queue<pair<int, int>> pq;
    dist[root] = 0;
    pq.push({0, root});
    while (!pq.empty()) {
        int node = pq.top().second;
        int d = -pq.top().first;
        pq.pop();

        if (in(node, visited)) continue;
        visited.insert(node);

        // In case of disconnected graphs
        if (not in(node, g)) continue;

        for (auto e : g[node]) {
            int neigh = e.first;
            int cost = e.second;
            if (dist[neigh] > dist[node] + cost) {
                dist[neigh] = dist[node] + cost;
                pq.push({-dist[neigh], neigh});
            }
        }
    }
    return dist;
}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q, s;
    cin >> n >> m >> q >> s;
    while (!(n == 0 && m == 0 && q == 0 && s == 0)) {
        map<int, vector<pair<int, int>>> g;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            g[u].push_back({v, w});
        }

        set<int> queries;
        vector<int> queries_help;
        int q_help = 0;
        while (q--) {
            int v;
            cin >> v;
            queries.insert(v);
            queries_help.push_back(v);
            q_help++;

        }

        
		vector<int> dist = dijkstra(n, s, g);
        for (auto query: queries_help) {
            if (dist[query] == INF) cout << "Impossible" << endl;
            else cout << dist[query] << endl;
        }

        cin >> n >> m >> q >> s;
    }

    return 0;
}