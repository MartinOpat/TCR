#include "header.h"
// Returns total distinct ways to make sum using n coins of
// different denominations
int count(vi& coins, int n, int sum) {
    // 2d dp array where n is the number of coin
    // denominations and sum is the target sum
    vector<vector<int> > dp(n + 1, vector<int>(sum + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
 
            // without using the current coin,
            dp[i][j] += dp[i - 1][j];

            // using the current coin
            if ((j - coins[i - 1]) >= 0)
                dp[i][j] += dp[i][j - coins[i - 1]];
        }
    }
    return dp[n][sum];
}
