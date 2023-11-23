
// 	// Function to find edges to be added to make the graph strongly connected
// 	vector<pi> findEdgesToAdd(const vi &sources, const vi &sinks) {
// 		vector<pi> edges_to_add;
// 		if (C == 1) return edges_to_add;
// 		// Assuming that there is at least one node in both sources and sinks
// 		for (int i = 0; i < max(sources.size(), sinks.size()); i++) {
// 			int src = sources[i % sources.size()];
// 			int sink = sinks[i % sinks.size()];
// 			if (src == sink) {
// 				sink = sinks[(i + 1) % sinks.size()];
// 				edges_to_add.push_back({sink, src});
// 				sink = sinks[i % sinks.size()];
// 				src = sources[(i + 1) % sources.size()];
// 				i++;
// 			}
// 			edges_to_add.push_back({sink, src});  // Edge from sink to source
// 		}
// 		return edges_to_add;
// 	}

// 	vector<pi> findEdgesToAdd2(const vi &sources, const vi &sinks) {
// 		vector<pi> edges_to_add;
// 		if (C == 1) return edges_to_add;
// 		bool same = sources.size() == sinks.size();
// 		if (same) {
// 			for (int i = 0; i < sinks.size(); i++) {
// 				if (sources[i] != sinks[i]) {
// 					same = false;
// 					break;
// 				}
// 			}
// 		}
// 		if (same) {
// 			for (int i = 0; i < sinks.size(); i++) {
// 				edges_to_add.push_back({sources[i], sinks[(i + 1) % sinks.size()]});
// 			}
// 		} else {
// 			for (int i = 0; i < max(sources.size(), sinks.size()); i++) {
// 				int src = sources[i % sources.size()];
// 				int sink = sinks[i % sinks.size()];
// 				if (src == sink) {
// 					sink = sinks[(i + 1) % sinks.size()];
// 					edges_to_add.push_back({sink, src});
// 					sink = sinks[i % sinks.size()];
// 					src = sources[(i + 1) % sources.size()];
// 					i++;
// 				}
// 				edges_to_add.push_back({sink, src});  // Edge from sink to source
// 			}
// 		}
// 		return edges_to_add;
// 	}

// 	vpi findEdgesToAdd3(const vi &sources, const vi &sinks) {
// 		vpi edges_to_add;
// 		if (C == 1) return edges_to_add;

// 		for (int i = 0; i < min(sources.size(), sinks.size()); i++) {
// 			if (sources[i] == sinks[i]) {
// 				int j = i;
// 				while (sources[j] == sinks[j]) {
// 					if (j + 1 == min(sources.size(), sinks.size()))
// 						break;
// 					else {
// 						edges_to_add.push_back({sources[j], sinks[j + 1]});
// 						j++;
// 					}
// 				}
// 				edges_to_add.push_back({sources[j], sinks[i]});
// 				i = j;
// 			} else {
// 				edges_to_add.push_back({sources[i], sinks[i]});
// 			}
// 		}

// 		for (int i = min(sources.size(), sinks.size()); i < max(sources.size(), sinks.size()); i++) {
// 			if (sources.size() < sinks.size()) {
// 				edges_to_add.push_back({(sinks[i]+1) % C, sinks[i]});
// 			} else {
// 				edges_to_add.push_back({sources[i], (sources[i]+1) % C});
// 			}
// 		}

// 		return edges_to_add;
// 	}

// 	vector<array<int, 2>> findEdgesToAdd4(const vector<vector<int>>& adj, int num_sccs, const vector<int>& scc_id) {
// 		if (num_sccs == 1) return {};
// 		auto n = size(adj);
// 		vector<vector<int>> scc_adj(num_sccs);
// 		vector<bool> zero_in(num_sccs, 1);
// 		for (int i = 0; i < n; i++)
// 			for (int v : adj[i]) {
// 				if (scc_id[i] == scc_id[v]) continue;
// 				scc_adj[scc_id[i]].push_back(scc_id[v]);
// 				zero_in[scc_id[v]] = 0;
// 			}
// 		vector<bool> vis(num_sccs);
// 		auto dfs = [&](auto&& self, int u) -> int {
// 			if (empty(scc_adj[u])) return u;
// 			for (int v : scc_adj[u])
// 				if (!vis[v]) {
// 					vis[v] = 1;
// 					int zero_out = self(self, v);
// 					if (zero_out != -1) return zero_out;
// 				}
// 			return -1;
// 		};
// 		vector<array<int, 2>> edges;
// 		vector<int> in_unused;
// 		for (int i = 0; i < num_sccs; i++)
// 			if (zero_in[i]) {
// 				vis[i] = 1;
// 				int zero_out = dfs(dfs, i);
// 				if (zero_out != -1) edges.push_back({zero_out, i});
// 				else in_unused.push_back(i);
// 			}
// 		for (int i = 1; i < size(edges); i++) swap(edges[i][0], edges[i - 1][0]);
// 		for (int i = 0; i < num_sccs; i++)
// 			if (empty(scc_adj[i]) && !vis[i]) {
// 				if (!empty(in_unused)) {
// 					edges.push_back({i, in_unused.back()});
// 					in_unused.pop_back();
// 				} else edges.push_back({i, num_sccs - 1});
// 			}
// 		for (int u : in_unused) edges.push_back({0, u});
// 		vector<int> to_node(num_sccs);
// 		for (int i = 0; i < n; i++) to_node[scc_id[i]] = i;
// 		for (auto& [u, v] : edges) u = to_node[u], v = to_node[v];
// 		return edges;
// 	}
// };

// int main() {
// 	int n;
// 	cin >> n;
// 	vvi edges;
// 	int temp;
// 	for (int i = 0; i < n; i++) {
// 		cin >> temp;
// 		edges.push_back({temp - 1});
// 	}

// 	Tarjan tj(edges);
// 	vi scc;
// 	vvi scc_graph;
// 	tj.scc_collapse(scc, scc_graph);

// 	vi sources, sinks;
// 	tj.findSourcesAndSinks(scc_graph, sources, sinks);

// 	unordered_map<int, int> mapping;
// 	for (int i = 0; i < scc.size(); i++) {
// 		mapping[scc[i]] = i;
// 	}

// 	// cout << sources << endl << sinks << endl;
// 	auto edges_to_add = tj.findEdgesToAdd4(edges, tj.C, scc);

// 	cout << edges_to_add.size() << endl;
// 	for (auto x : edges_to_add) {
// 		cout << mapping[x[1]] + 1 << " " << mapping[x[0]] + 1 << endl;
// 	}
// }