#include "../header.h"

template<size_t len>
struct pair_hash { // To make it hashable (pair<int, bitset<len>>)
    std::size_t operator()(const std::pair<int, std::bitset<len>>& p) const {
        std::size_t h1 = std::hash<int>{}(p.first);
        std::size_t h2 = std::hash<std::bitset<len>>{}(p.second);
        return h1 ^ (h2 << 1);
    }
};
#define MAXN 1000
std::bitset<MAXN> bs;
// bs.set(idx) <- set idx-th bit (1)
// bs.reset(idx) <- reset idx-th bit (0)
// bs.flip(idx) <- flip idx-th bit
// bs.test(idx) <- idx-th bit == 1
// bs.count() <- number of 1s
// bs.any() <- any bit == 1