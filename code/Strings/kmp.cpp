#include "header.h"
void compute_prefix_function(string &w, vi &prefix) {
	prefix.assign(w.length(), 0);
	int k = prefix[0] = -1;

	for(int i = 1; i < w.length(); ++i) {
		while(k >= 0 && w[k + 1] != w[i]) k = prefix[k];
		if(w[k + 1] == w[i]) k++;
		prefix[i] = k;
	}
}
vi knuth_morris_pratt(string &s, string &w) {
	int q = -1;
	vi prefix, positions;
	compute_prefix_function(w, prefix);
	for(int i = 0; i < s.length(); ++i) {
		while(q >= 0 && w[q + 1] != s[i]) q = prefix[q];
		if(w[q + 1] == s[i]) q++;
		if(q + 1 == w.length()) {
			// Match at position (i - w.length() + 1)
            positions.push_back(i - w.length() + 1);
			q = prefix[q];
		}
	}
    return positions;
}
