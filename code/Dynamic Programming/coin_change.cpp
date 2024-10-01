#include "header.h"
int count(vi& coins, int n, int sum) {
    vvi dp(n + 1, vi(sum + 1, 0));
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
