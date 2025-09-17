#pragma once
#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

using namespace std;

class Disjoint_Set {
   private:
    int         n = 1e5;
    vector<int> parent;
    vector<int> size;

   public:
    Disjoint_Set() {
        parent = vector<int>(n);
        size   = vector<int>(n);
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
    }

    void make_set(int v) {
        parent[v] = v;
        size[v]   = 1;
    }

    int find_set(int v) {
        if (parent[v] == v)
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int v1, int v2) {
        int a = find_set(v1);
        int b = find_set(v2);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};
