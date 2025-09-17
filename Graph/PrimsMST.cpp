#include <bits/stdc++.h>

#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

map<int, set<pair<int, int>>> graph;

/*
 * Definition:
 *   Computes the Minimum Spanning Tree (MST) of a connected, weighted,
 * undirected graph using Prim's algorithm.
 *
 * Allowed Operations / Rules:
 *   - Graph must be undirected and connected.
 *   - Edge weights can be positive or zero.
 *   - Select edges incrementally, always choosing the minimum-weight edge
 *      connecting a visited node to an unvisited node.
 *
 * Recurrence Relation / Formula:
 *   - Start from a source vertex.
 *   - While there are unvisited vertices:
 *       - Select edge (u,v) with minimum weight where u is visited and v is
 *          unvisited.
 *       - Add v to MST and update distances for adjacent unvisited vertices.
 *
 * Edge Cases / Pitfalls:
 *   - Graph must be connected; otherwise, MST does not exist.
 *   - Multiple edges between same vertices are allowed; only the smallest
 *      weight counts.
 *   - Avoid revisiting nodes by marking them visited.
 *
 * Complexity:
 *   - Time: O(E log V) using a set or priority queue.
 *           O(V^2) if using adjacency matrix without a heap, good for dense
 *          graphs.
 *   - Space: O(V + E) for adjacency list and auxiliary arrays.
 *
 * Use Cases:
 *   - Network design (minimum cost connectivity, like laying cables).
 *   - Designing efficient pipelines, power grids, and transport networks.
 *   - Clustering algorithms in machine learning.
 *
 * Comparison:
 *   - Prim vs Kruskal:
 *       - Prim is efficient for dense graphs (especially with adjacency
 *          matrix).
 *       - Kruskal works better for sparse graphs.
 *
 * Implementation Notes:
 *   - Uses a set to maintain the minimum edge efficiently (like a priority
 *      queue).
 *   - Maintains `dist` array for minimum edge weight to MST and `parent` array
 *      for MST edges.
 *   - Iteratively adds the vertex with minimum connecting edge to the MST.
 */
int primsMST(int n = 9) {
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

    primsMST();
    return 0;
}
