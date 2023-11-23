#include "header.h"
// calculate amount of nodes in each node's subtree
const int mxN = 2e5 + 5;
int n, cnt[mxN];
vi adj[mxN];
void dfs(int s = 0, int e = -1) {
	cnt[s] = 1;	 // count leaves as one
	for (int u : adj[s]) {
		dfs(u, s);
		cnt[s] += cnt[u];  // add up nodes of the subtrees
	}
}
