#pragma once
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pl pair<ll, ll>
#define pi pair<int, int>
#define vl vector<ll>
#define vi vector<int>
#define vpl vector<pl>
#define vpi vector<pi>
#define in(el, cont) (cont.find(el) != cont.end())

constexpr int INF  = 2000000010;
constexpr ll LLINF = 9000000000000000010LL;

template <typename T, template <typename ELEM, typename ALLOC = std::allocator<ELEM> > class Container>
std::ostream& operator<<(std::ostream& o, const Container<T>& container) {
	typename Container<T>::const_iterator beg = container.begin();
    o << *beg++;
	while (beg != container.end()) {
		o << " " << *beg++;
	}
	return o;
}
