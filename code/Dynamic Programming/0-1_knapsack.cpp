#include "header.h"
// given a number of coins, calculate all possible distinct sums
int main() {
	int n;
	vi coins(n);  // all possible coins to use
	int sum = 0;		   // sum of the coins
	vi dp(sum + 1, 0);				  // dp[x] = 1 if sum x can be made
	dp[0] = 1;								  // sum 0 can be made
	for (int c = 0; c < n; ++c)				  // first iteration: sums with first
		for (int x = sum; x >= 0; --x)		  // coin, next first 2 coins etc
			if (dp[x]) dp[x + coins[c]] = 1;  // if sum x valid, x+c valid
}
