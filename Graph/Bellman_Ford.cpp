#include <bits/stdc++.h>
using namespace std;

/*
 * Definition:
 *   Computes shortest distances from a source vertex to all other vertices in a
 * weighted graph. Supports negative edge weights but detects negative cycles.
 *
 * Allowed Operations / Rules:
 *   - Graph can be directed or undirected.
 *   - Edges may have negative weights, but no negative cycles for valid
 * shortest paths.
 *   - Relax all edges |V|-1 times.
 *   - Check for negative cycles in a final pass.
 *
 * Recurrence Relation / Formula:
 *   - dist[v] = min(dist[v], dist[u] + weight(u, v)) for all edges (u, v)
 *
 * Edge Cases / Pitfalls:
 *   - Source vertex distance initialized to 0, others to INT_MAX.
 *   - Negative cycles must be detected to avoid incorrect distances.
 *   - Overflow must be avoided when adding weights to INT_MAX.
 *
 * Complexity:
 *   - Time: O(V * E), V = number of vertices, E = number of edges.
 *   - Space: O(V) for distance array.
 *
 * Use Cases:
 *   - Shortest path calculations in weighted graphs.
 *   - Network routing with potential negative link weights.
 *   - Detecting arbitrage opportunities in finance (negative cycles).
 *
 * Comparison:
 *   - Works with negative weights unlike Dijkstra.
 *   - Slower than Dijkstra (O(VE) vs O(E + V log V)), but handles negative
 * weights.
 *
 * Implementation Notes:
 *   - Relax all edges |V|-1 times to ensure shortest distances.
 *   - Final iteration checks for negative cycles.
 *   - Use INT_MAX to represent infinity; set dist[source] = 0.
 */
void bellmanFord(int n, int source, const vector<vector<int>>& edges) {
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    // Relax edges |V|-1 times
    for (int j = 0; j < n - 1; j++) {
        for (auto i : edges) {
            int w = i[0], u = i[1], v = i[2];
            if (dist[u] != INT_MAX) {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    // Check for negative cycles
    bool cycle = false;
    for (auto i : edges) {
        int w = i[0], u = i[1], v = i[2];
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cycle   = true;
            dist[v] = INT_MIN;  // Mark as part of negative cycle
        }
    }

    if (cycle)
        cout << "Negative Cycle present." << endl;

    // Print distances
    for (int i = 1; i < n; i++) {
        cout << dist[i] << ' ';
    }
    cout << endl;
}

int main() {
    // {weight, vertex1, vertex2}
    vector<vector<int>> edges = {{5, 1, 2}, {6, 2, 3},  {2, 4, 3}, {9, 1, 4},
                                 {5, 3, 5}, {10, 5, 6}, {7, 6, 7}, {1, 7, 8},
                                 {1, 8, 5}, {-3, 6, 8}};

    int n      = 9;
    int source = 1;

    bellmanFord(n, source, edges);

    return 0;
}
