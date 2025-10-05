#include <bits/stdc++.h>
using namespace std;

map<int, set<int>> graph, reverse_graph;

/*
 * Definition:
 *   Finds strongly connected components (SCCs) in a directed graph
 *   using Kosaraju's algorithm.
 *
 * Allowed Operations / Rules:
 *   - Works only on directed graphs.
 *   - Uses two DFS traversals:
 *       1. First DFS on original graph to compute finishing times.
 *       2. Second DFS on reversed graph in finishing-time order.
 *
 * Recurrence Relation / Formula:
 *   - DFS recursively visits unvisited neighbors.
 *   - Nodes reachable in the second DFS form a strongly connected component.
 *
 * Edge Cases / Pitfalls:
 *   - Graph must be directed; SCC is meaningless for undirected graphs.
 *   - Disconnected graphs are handled naturally.
 *
 * Complexity:
 *   - Time: O(V + E)
 *   - Space: O(V + E) for adjacency lists and visited arrays
 *
 * Use Cases:
 *   - Detecting cycles and strongly connected regions in graphs.
 *   - Compiler optimizations (finding cyclic dependencies).
 *   - Analyzing web link structures or social networks.
 *
 * Comparison:
 *   - Faster and simpler than Tarjan for explicit two-pass DFS.
 *   - Tarjan uses single DFS and maintains low-link values.
 *
 * Implementation Notes:
 *   - Uses a stack to store finishing times of the first DFS.
 *   - Reverses the graph for the second DFS.
 *   - Each DFS traversal marks nodes as visited to avoid reprocessing.
 */

// First DFS to compute finishing times
void dfs(vector<bool>& visit, stack<int>& st, int node) {
    visit[node] = true;
    for (auto neighbor : graph[node]) {
        if (!visit[neighbor])
            dfs(visit, st, neighbor);
    }
    st.push(node);
}

// DFS on reversed graph to find SCCs
void kosaraju(int node, vector<bool>& visit) {
    visit[node] = true;
    for (auto neighbor : reverse_graph[node]) {
        if (!visit[neighbor])
            kosaraju(neighbor, visit);
    }
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 0}, {3, 2},
                                 {3, 4}, {4, 5}, {5, 0}, {5, 3}, {6, 4},
                                 {6, 7}, {7, 5}, {7, 6}};
    int                 n     = 8;
    int                 count = 0;

    // Build graph and reversed graph
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].insert(v);
        reverse_graph[v].insert(u);
    }

    vector<bool> visit(n, false);
    stack<int>   st;

    // First DFS on original graph
    for (int i = 0; i < n; i++) {
        if (!visit[i])
            dfs(visit, st, i);
    }

    // Second DFS on reversed graph
    visit.assign(n, false);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!visit[node]) {
            count++;
            kosaraju(node, visit);
        }
    }

    cout << "No of Strongly Connected Components (SCC) : " << count << endl;
    return 0;
}
