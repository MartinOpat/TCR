#include "header.h"
void warshall(vvl g) {  // g[i][j] = infty if not path from i to j
    for (int i=0; i<g.size(); ++i) { 
        for (int j=0; j<g.size(); ++j) { 
            for (int k=0; k<g.size(); ++k) {
                if (g[i][k] < LLINF and g[k][j] < LLINF and g[i][j] > g[i][k] + g[k][j]) {
                    g[i][j] = g[i][k] + g[k][j];
}}}}}