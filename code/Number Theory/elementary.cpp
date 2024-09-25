#include "header.h"
ll gcd(ll a, ll b) { while (b) { a %= b; swap(a, b); } return a; } 
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll mod(ll a, ll b) { return ((a % b) + b) % b; }
// Finds x, y s.t. ax + by = d = gcd(a, b).
void extended_euclid(ll a, ll b, ll &x, ll &y, ll &d) {
	ll xx = y = 0;
	ll yy = x = 1;
	while (b) {
		ll q = a / b;
		ll t = b; b = a % b; a = t;
		t = xx; xx = x - q * xx; x = t;
		t = yy; yy = y - q * yy; y = t;
	}
	d = a;
}
// solves ab = 1 (mod n), -1 on failure
ll mod_inverse(ll a, ll n) {
	ll x, y, d;
	extended_euclid(a, n, x, y, d);
	return (d > 1 ? -1 : mod(x, n));
}
// All modular inverses of [1..n] mod P in O(n) time.
vi inverses(ll n, ll P) {
	vi I(n+1, 1LL);
	for (ll i = 2; i <= n; ++i)
		I[i] = mod(-(P/i) * I[P%i], P);
	return I;
}
// (a*b)%m
ll mulmod(ll a, ll b, ll m){
	ll x = 0, y=a%m;
	while(b>0){
		if(b&1) x = (x+y)%m;
		y = (2*y)%m, b /= 2;
	}
	return x % m;
}
// Finds b^e % m in O(lg n) time, ensure that b < m to avoid overflow!
ll powmod(ll b, ll e, ll m) {
	ll p = e<2 ? 1 : powmod((b*b)%m,e/2,m);
	return e&1 ? p*b%m : p;
}
// Solve ax + by = c, returns false on failure.
bool linear_diophantine(ll a, ll b, ll c, ll &x, ll &y) {
	ll d = gcd(a, b);
	if (c % d) {
		return false;
	} else {
		x = c / d * mod_inverse(a / d, b / d);
		y = (c - a * x) / b;
		return true;
	}
}

// Description: Tonelli-Shanks algorithm for modular square roots. Finds $x$ s.t. $x^2 = a \pmod p$ ($-x$ gives the other solution). O(\log^2 p) worst case, O(\log p) for most $p$
ll sqrtmod(ll a, ll p) {
	a %= p; if (a < 0) a += p;
	if (a == 0) return 0;
	assert(powmod(a, (p-1)/2, p) == 1); // else no solution
	if (p % 4 == 3) return powmod(a, (p+1)/4, p);
	// a^(n+3)/8 or 2^(n+3)/8 * 2^(n-1)/4 works if p % 8 == 5
	ll s = p - 1, n = 2;
	int r = 0, m;
	while (s % 2 == 0)
		++r, s /= 2;
	/// find a non-square mod p
	while (powmod(n, (p - 1) / 2, p) != p - 1) ++n;
	ll x = powmod(a, (s + 1) / 2, p);
	ll b = powmod(a, s, p), g = powmod(n, s, p);
	for (;; r = m) {
		ll t = b;
		for (m = 0; m < r && t != 1; ++m)
			t = t * t % p;
		if (m == 0) return x;
		ll gs = powmod(g, 1LL << (r - m - 1), p);
		g = gs * gs % p;
		x = x * gs % p;
		b = b * g % p;
	}
}
