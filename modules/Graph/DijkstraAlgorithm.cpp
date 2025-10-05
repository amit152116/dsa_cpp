#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
#define Graph vector<set<pair<int, int>>>

/*
 * Definition:
 *   Computes the shortest distances from a source vertex to all other vertices
 *   in a weighted graph with non-negative edge weights using Dijkstra's
 * algorithm.
 *
 * Allowed Operations / Rules:
 *   - Graph can be directed or undirected.
 *   - Edge weights must be non-negative.
 *   - Use priority queue (or set) to always expand the node with minimum
 *      tentative distance.
 *
 * Recurrence Relation / Formula:
 *   - dist[v] = min(dist[v], dist[u] + weight(u, v)) for all adjacent nodes u
 *
 * Edge Cases / Pitfalls:
 *   - Negative edge weights break the algorithm; use Bellman-Ford for those
 *      cases.
 *   - Dense graphs can make the set-based implementation slow (O(V^2 log V)).
 *   - Always remove previous entries from the set before updating distances.
 *
 * Complexity:
 *   - Time: O((V + E) log V) using set or priority queue
 *   - Space: O(V + E) for adjacency representation, O(V) for distance array and
 *      set
 *
 * Use Cases:
 *   - GPS navigation and routing.
 *   - Network packet routing.
 *   - Resource optimization problems on graphs with non-negative weights.
 *
 * Comparison:
 *   - Faster than Bellman-Ford for graphs without negative edges.
 *   - Cannot handle negative edge weights unlike Bellman-Ford.
 *   - Slower than Floyd-Warshall for dense graphs if V is small and E ~ V^2.
 *
 * Implementation Notes:
 *   - Uses a `set` to act as a priority queue for node selection.
 *   - Update distance and re-insert node into the set if a shorter path is
 *      found.
 *   - Maintain distance array initialized to INT_MAX, source = 0.
 */
void dijkstra(Graph graph, int n) {
    int         source = 1;
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;
    set<pair<int, int>> st;  // {distance, vertex}
    st.insert({0, source});
    int count = 0;

    while (!st.empty()) {
        auto x       = *st.begin();
        int  node    = x.second;
        int  minDist = x.first;
        st.erase(x);

        for (auto i : graph[node]) {
            int child  = i.first;
            int weight = i.second;
            count++;

            if (dist[child] > dist[node] + weight) {
                if (dist[child] != INT_MAX) {
                    st.erase({dist[child], child});
                }
                dist[child] = dist[node] + weight;
                st.insert({dist[child], child});
            }
        }
    }

    cout << count << endl;
    for (int i = 1; i < n; i++) {
        cout << dist[i] << ' ';
    }
    cout << endl;
}

int main() {
    vector<vector<int>> edges = {{5, 1, 2}, {6, 2, 3},  {2, 4, 3}, {9, 1, 4},
                                 {5, 3, 5}, {10, 5, 6}, {7, 6, 7}, {1, 7, 8},
                                 {1, 8, 5}, {-3, 6, 8}};
    int                 m     = edges.size();
    int                 n     = 9;
    Graph               graph(n);
    for (int i = 0; i < m; i++) {
        int u = edges[i][1];
        int v = edges[i][2];
        int w = edges[i][0];
        // {vertex,weight}
        graph[u].insert({v, w});
    }

    dijkstra(graph, n);

    return 0;
}
