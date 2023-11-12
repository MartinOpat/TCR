#include "header.h"

ll mod_pow(ll base, ll exp, ll mod) {
	if (mod == 1) return 0;
    if (exp == 0) return 1;
    if (exp == 1) return base;

	ll res = 1;
	base %= mod;
	while (exp) {
		if (exp % 2 == 1) res = (res * base) % mod;
		exp >>= 1;
		base = (base * base) % mod;
	}

	return res % mod;
}
