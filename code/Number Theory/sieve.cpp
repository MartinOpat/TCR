#include "header.h"

vector<ll> primes;
void getprimes(ll n) {
    vector<bool> p(n, true);
    p[0] = false;
    p[1] = false;
    for(ll i = 0; i < n; i++) {
        if(p[i]) {
            primes.push_back(i);
            for(ll j = i*2; j < n; j+=i) {
                p[j] = false;
            }
        }
    }
}
