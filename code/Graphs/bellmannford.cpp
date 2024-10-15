#include "header.h"
// Switch vi and vvpi to vl and vvpl if necessary
void bellmann_ford_extended(vvpi &e, int source, int goal, vi &dist, vb &cyc) {
    dist.assign(e.size(), INF);
    cyc.assign(e.size(), false); // true when u is in a <0 cycle
    dist[source] = 0;

    // Perform n-1 relaxations
    for (int iter = 0; iter < e.size() - 1; ++iter) {
        bool relax = false;
        for (int u = 0; u < e.size(); ++u) {
            if (dist[u] == INF) continue;
            for (auto &edge : e[u]) {
                int v = edge.first, w = edge.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    relax = true;
                }
            }
        }
        if (!relax) break;
    }
    // Step to detect any reachable negative cycles
    for (int u = 0; u < e.size(); ++u) {
        if (dist[u] == INF) continue;
        for (auto &edge : e[u]) {
            int v = edge.first, w = edge.second;
            if (dist[u] + w < dist[v]) {
                // If we can still relax, mark the node in the negative cycle
                dist[v] = -INF;
                cyc[v] = true;
            }
        }
    }
    // Propagate neg. cycle detection to all reachable nodes (if necessary)
    bool change = true;
    while (change) {
        change = false;
        for (int u = 0; u < e.size(); ++u) {
            if (!cyc[u]) continue;
            for (auto &edge : e[u]) {
                int v = edge.first;
                if (!cyc[v]) {
                    cyc[v] = true;
                    dist[v] = -INF;
                    change = true;
                }
            }
        }
    }
}
