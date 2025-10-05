#include <bits/stdc++.h>
using namespace std;
#define INF 99999

/*
 * Definition:
 *   Computes shortest paths between all pairs of vertices in a directed graph
 *   using dynamic programming (Floyd-Warshall algorithm).
 *
 * Allowed Operations / Rules:
 *   - Graph must be directed.
 *   - Edge weights can be negative but no negative cycles allowed for correct
 * distances.
 *   - Use DP to iteratively improve distances through intermediate vertices.
 *
 * Recurrence Relation / Formula:
 *   - dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]) for all vertices k
 *
 * Edge Cases / Pitfalls:
 *   - Self-loops with negative weights indicate a negative cycle.
 *   - INF values represent no direct edge.
 *
 * Complexity:
 *   - Time: O(V^3), where V = number of vertices.
 *   - Space: O(V^2) for distance matrix.
 *
 * Example:
 *   Input adjacency matrix:
 *     0   5  INF  10
 *     INF 0   3   INF
 *     INF INF 0    1
 *     INF 2  INF   0
 *   Output distance matrix:
 *     0   5   8   9
 *     INF 0   3   4
 *     INF INF 0   1
 *     INF 2   5   0
 *
 * Use Cases:
 *   - All-pairs shortest path calculations.
 *   - Graphs with small number of vertices (dense or weighted).
 *
 * Comparison:
 *   - Handles negative edge weights unlike Dijkstra.
 *   - Slower than Dijkstra for single-source shortest paths.
 *
 * Implementation Notes:
 *   - Initialize distance matrix with adjacency matrix.
 *   - Iteratively update distances considering each vertex as an intermediate.
 *   - Detect negative cycles by checking dist[i][i] < 0 after updates.
 */
void floydWarshall(vector<vector<int>> graph) {
    int                 V    = graph.size();
    vector<vector<int>> dist = graph;

    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Detect negative cycles
    bool cycle = false;
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Negative Cycle present." << endl;

    // Print distance matrix
    for (auto row : dist) {
        for (auto val : row) {
            cout << val << ' ';
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, 2, INF, 0}};

    floydWarshall(graph);

    return 0;
}
