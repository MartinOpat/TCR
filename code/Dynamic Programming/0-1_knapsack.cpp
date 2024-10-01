#include "header.h"
int main() {
	int n;
	vi coins(n); // possible coins to use
	int sum = 0; // their sum of the coins
	vi dp(sum + 1, 0); // dp[x] = 1 if sum x can be made
	dp[0] = 1;								  
	for (int c = 0; c < n; ++c)
		for (int x = sum; x >= 0; --x)
			if (dp[x]) dp[x + coins[c]] = 1; 
}
