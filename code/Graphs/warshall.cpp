#include "header.h"
// g[i][j] = infty if not path from i to j
// if g[i][i] < 0, i is contained in a negative cycle
void warshall(vvl& g) {
    for (int k=0; k<g.size(); ++k) { 
        for (int i=0; i<g.size(); ++i) { 
            for (int j=0; j<g.size(); ++j) {
                if (g[i][k] < LLONG_MAX and g[k][j] < LLONG_MAX and g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
}}}}}