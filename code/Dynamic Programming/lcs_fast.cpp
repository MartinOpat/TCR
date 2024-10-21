#include "../header.h"
#include "../Data Structures/fenwick_tree.cpp"
int lcs(int k, vector<int>& A, vector<int>& B) {
    int lenA = A.size();
    int lenB = B.size();

    // Determine the number of distinct elements from max element in A and B
    int n = max(*max_element(A.begin(), A.end()), *max_element(B.begin(), B.end())) + 1;

    vector<vector<int>> C(n);
    for (int j = 0; j < lenB; ++j) {
        C[B[j]].push_back(j);
    }

    int ans = 0;
    FenwickTree<int> fenwick(lenB + 1);
    for (int i = 0; i < lenA; ++i) {
        int a = A[i];
        for (int j = C[a].size() - 1; j >= 0; --j) {
            int pos = C[a][j];
            int x = fenwick.query(pos) + 1;
            fenwick.update(pos + 1, x);  // Convert to 1-based index
            ans = max(ans, x);
        }
    }
    return ans;
}