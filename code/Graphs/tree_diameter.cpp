#include "header.h"
const int mxN = 2e5 + 5;
int n, d[mxN];	// distance array
vi adj[mxN];	// tree adjacency list
void dfs(int s, int e) {
	d[s] = 1 + d[e];	   // recursively calculate the distance from the starting node to each node
	for (auto u : adj[s]) { // for each adjacent node
		if (u != e) dfs(u, s);	// don't move backwards in the tree
	}
}
int main() {
	// read input, create adj list
	dfs(0, -1);									  // first dfs call to find farthest node from arbitrary node
	dfs(distance(d, max_element(d, d + n)), -1);  // second dfs call to find farthest node from that one
	cout << *max_element(d, d + n) - 1 << '\n';	 // distance from second node to farthest is the diameter
}
