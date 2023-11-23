# include "header.h"
ll phi(ll n) {  // \Phi(n)
    ll ans = 1;
    for (ll i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            ans *= i-1;
            n /= i;
            while (n % i == 0) {
                ans *= i;
                n /= i;
            }
        }
    }
    if (n > 1) ans *= n-1;
    return ans;
}
vi phis(int n) {  // All \Phi(i) up to n
	vi phi(n + 1, 0LL);
	iota(phi.begin(), phi.end(), 0LL);
	for (ll i = 2LL; i <= n; ++i)
		if (phi[i] == i)
			for (ll j = i; j <= n; j += i)
				phi[j] -= phi[j] / i;
	return phi;
}