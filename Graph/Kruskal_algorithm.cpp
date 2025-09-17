#include <bits/stdc++.h>

#include "../Data Structure/DisjointSet.hpp"
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

/*
 * Definition:
 *   Finds the Minimum Spanning Tree (MST) of a connected, weighted, undirected
 * graph using Kruskal's algorithm.
 *
 * Allowed Operations / Rules:
 *   - Graph must be undirected and connected.
 *   - Edge weights can be positive or zero.
 *   - Use Disjoint Set (Union-Find) to detect cycles.
 *   - Add edges in ascending order of weight, ignoring edges that form a cycle.
 *
 * Recurrence Relation / Formula:
 *   - Sort edges by weight.
 *   - For each edge (u,v) in sorted order:
 *       if find_set(u) != find_set(v):
 *           union_sets(u,v) and add edge to MST
 *
 * Edge Cases / Pitfalls:
 *   - Graph must be connected; otherwise, MST does not exist.
 *   - Duplicate edges or self-loops must be handled carefully.
 *
 * Complexity:
 *   - Time: O(E log V) due to sorting and union-find operations.
 *   - Space: O(V + E) for storing edges and disjoint set.
 *
 * Use Cases:
 *   - Network design (laying cables with minimal cost).
 *   - Clustering algorithms.
 *   - Any system requiring minimal connectivity cost.
 *
 * Comparison:
 *   - Kruskal vs Prim:
 *       - Kruskal works better for sparse graphs.
 *       - Prim is more efficient for dense graphs.
 *
 * Implementation Notes:
 *   - Use Disjoint Set (Union-Find) with path compression for cycle detection.
 *   - Sort edges by weight before processing.
 */

int kruskalMST(vector<vector<int>>& edges, int n) {
    Disjoint_Set set;
    int          cost = 0;

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    // Process edges
    for (auto edge : edges) {
        int w = edge[0], u = edge[1], v = edge[2];

        int x = set.find_set(u);
        int y = set.find_set(v);

        if (x != y) {  // If no cycle
            set.union_sets(u, v);
            cost += w;
            cout << u << ' ' << v << endl;
        }
    }

    return cost;
}

int main() {
    fast;

    // {weight, vertex1, vertex2}
    vector<vector<int>> edges = {{5, 1, 2}, {6, 2, 3}, {2, 4, 3},
                                 {9, 1, 4}, {5, 3, 5}, {10, 5, 6},
                                 {7, 6, 7}, {1, 7, 8}, {1, 8, 5}};

    int n    = 8;  // Number of vertices
    int cost = kruskalMST(edges, n);

    cout << "Cost of MST: " << cost << endl;

    return 0;
}
