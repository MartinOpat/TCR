#ifndef DISJOINTSET_H
#define DISJOINTSET_H

template <typename T>
class DisjointSet {
    typedef T *iterator;
    T *parent, n, *rank;

public:
    DisjointSet(T n);
    T find_set(T x);
    void union_sets(T x, T y);
};

#endif // DISJOINTSET_H
