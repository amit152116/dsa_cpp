#include <bits/stdc++.h>

#include "../Data Structure/Disjoint_set.hpp"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

//* Time Complexity : O(ElogV)

// For adjancency matix time complexity of Prims is O(V^2)
// and it is good for denser graphs.

map<int, set<pair<int, int>>> graph;
int                           prims_MST(int n = 9) {
    int cost = 0;

    vector<int>  dist(n, INT_MAX);
    vector<bool> visit(n, false);
    vector<int>  parent(n, -1);
    int          source = 1;

    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;
    while (!st.empty()) {
        auto x   = *st.begin();
        int  u   = x.second;
        int  w   = x.first;
        visit[u] = true;
        cost += w;
        int v = parent[u];
        cout << v << ' ' << u << endl;
        st.erase(x);
        for (auto i : graph[u]) {
            int child  = i.first;
            int weight = i.second;
            if (visit[child]) {
                continue;
            }
            if (dist[child] > weight) {
                st.erase({dist[child], child});
                dist[child] = weight;
                st.insert({dist[child], child});
                parent[child] = u;
            }
        }
    }

    cout << "Cost of MST : " << cost << endl;
    return cost;
}

int main() {
    // {weight,vertex1,vertex2}
    vector<vector<int>> edges = {{5, 1, 2}, {6, 2, 3}, {2, 4, 3},
                                 {9, 1, 4}, {5, 3, 5}, {10, 5, 6},
                                 {7, 6, 7}, {1, 7, 8}, {1, 8, 5}};

    for (auto i : edges) {
        int w = i[0];
        int u = i[1];
        int v = i[2];

        graph[u].insert({v, w});
        graph[v].insert({u, w});
    }

    prims_MST();
    return 0;
}
