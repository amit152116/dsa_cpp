#include <bits/stdc++.h>

#include "../Data Structure/Disjoint_set.hpp"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

//* Time Complexity : O(ElogV)
int main() {
    // {weight,vertex1,vertex2}
    vector<vector<int>> edges = {{5, 1, 2}, {6, 2, 3}, {2, 4, 3},
                                 {9, 1, 4}, {5, 3, 5}, {10, 5, 6},
                                 {7, 6, 7}, {1, 7, 8}, {1, 8, 5}};
    Disjoint_Set        set;
    int                 cost = 0;

    // Sorting according to weights of edges
    sort(edges.begin(), edges.end());

    // If cycle is made by certain edge, we will not add the cost and ignore it.
    // Using the Disjoint Set to find the cycle.
    for (auto i : edges) {
        int w = i[0];
        int u = i[1];
        int v = i[2];

        int x = set.find_set(u);
        int y = set.find_set(v);
        if (x == y)
            continue;
        else {
            set.union_sets(u, v);
            cost += w;
            cout << u << ' ' << v << endl;
        }
    }
    cout << "Cost of MST : " << cost << endl;
    return 0;
}
