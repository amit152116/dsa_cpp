#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
map<int, set<int>> graph;

/*
 * Definition:
 *   Finds all Strongly Connected Components (SCCs) in a directed graph using
 * Tarjan's algorithm.
 *
 * Allowed Operations / Rules:
 *   - Graph is directed.
 *   - Traverse nodes using DFS.
 *   - Maintain a stack to track nodes in the current DFS path.
 *   - Each node has a low-link value representing the smallest reachable node
 *      in its DFS subtree.
 *
 * Recurrence Relation / Formula:
 *   - low_link[node] = min(node, min(low_link[child] for each child in DFS tree
 *      if child is on stack))
 *   - A node is the root of an SCC if low_link[node] == node.
 *
 * Edge Cases / Pitfalls:
 *   - Multiple edges between nodes.
 *   - Disconnected graph components.
 *   - Correctly marking nodes as not on stack after popping SCC.
 *
 * Complexity:
 *   - Time: O(V + E) where V = number of vertices, E = number of edges.
 *   - Space: O(V) for stack, low_link array, visited flags.
 *
 * Use Cases:
 *   - Detect cycles in directed graphs.
 *   - Identify independent modules in software dependency graphs.
 *   - Analyze strongly connected components in networks or social graphs.
 *
 * Comparison:
 *   - Faster than Kosaraju’s algorithm in practice because it uses a single DFS
 *      pass.
 *   - DFS-based, unlike BFS algorithms which cannot compute SCC directly.
 *
 * Implementation Notes:
 *   - DFS recursively visits unvisited nodes.
 *   - Use stack to keep track of nodes in the current DFS path.
 *   - Update low-link values based on children and nodes in the stack.
 *   - Increment SCC count when a root node of an SCC is found
 *   (low_link[node] == node).
 */
void tarjan(vector<bool>& visit, vector<int>& low_link, stack<int>& st,
            vector<bool>& onStack, int node, int& count) {
    st.push(node);
    visit[node]    = true;
    low_link[node] = node;
    onStack[node]  = true;
    for (auto i : graph[node]) {
        if (!visit[i]) {
            tarjan(visit, low_link, st, onStack, i, count);
        }
        if (onStack[i]) {
            low_link[node] = min(low_link[node], low_link[i]);
        }
    }

    if (low_link[node] == node) {
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            onStack[curr] = false;
            if (curr == node)
                break;
        }
        count++;
    }
    return;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 0}, {3, 2},
                                 {3, 4}, {4, 5}, {5, 0}, {5, 3}, {6, 4},
                                 {6, 7}, {7, 5}, {7, 6}};

    int n = 8;
    for (auto i : edges) {
        int u = i[0];
        int v = i[1];

        graph[u].insert(v);
    }
    vector<bool> visit(n);
    vector<int>  low_link(n);
    stack<int>   st;
    vector<bool> onStack(n);
    int          count = 0;
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            tarjan(visit, low_link, st, onStack, i, count);
        }
    }
    cout << "No of Strongly Connected Components (SCC) : " << count << endl;
    return 0;
}
