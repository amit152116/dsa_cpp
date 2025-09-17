#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
#define Graph map<int, set<int>>
#define Visit unordered_map<int, bool>

/*
 * Breadth-First Search (BFS)
 * ---------------------------
 * Definition:
 *   Traverses a graph level by level, visiting all nodes at the current depth
 *   before moving to the next level.
 *
 * Allowed Operations / Rules:
 *   - Works for directed or undirected graphs.
 *   - Can handle disconnected graphs by iterating over all vertices.
 *
 * Recurrence Relation / Formula:
 *   - Uses a queue to process nodes in FIFO order.
 *   - For each node, enqueue all unvisited neighbors.
 *
 * Edge Cases / Pitfalls:
 *   - Ensure all nodes are visited in disconnected graphs.
 *   - Avoid revisiting nodes to prevent infinite loops.
 *
 * Complexity:
 *   - Time: O(V + E) for adjacency list.
 *   - Space: O(V) for visited array and queue.
 *
 * Implementation Notes:
 *   - Uses `queue` to maintain the current frontier.
 *   - Iterates through all vertices to handle disconnected components.
 */
void bfs(Graph graph) {
    fast;
    cout << endl << " BFS : ";
    Visit      visited;
    queue<int> st;
    for (int item = 0; item < graph.size(); item++) {
        if (visited[item] == false) {
            st.push(item);
            visited[item] = true;

            while (!st.empty()) {
                int i = st.front();
                st.pop();
                cout << i << ' ';
                for (auto j : graph[i]) {
                    if (visited[j] == false) {
                        visited[j] = true;
                        st.push(j);
                    }
                }
            }
        }
    }

    return;
}

/*
 * Depth-First Search (DFS)
 * -------------------------
 * Definition:
 *   Traverses a graph by exploring as far as possible along each branch
 *   before backtracking.
 *
 * Allowed Operations / Rules:
 *   - Works for directed or undirected graphs.
 *   - Can handle disconnected graphs by iterating over all vertices.
 *
 * Recurrence Relation / Formula:
 *   - Recursive approach: for each node, recursively visit all unvisited
 * neighbors.
 *
 * Edge Cases / Pitfalls:
 *   - Stack overflow for very deep graphs in recursion.
 *   - Ensure visited array is reset for multiple DFS calls.
 *
 * Complexity:
 *   - Time: O(V + E) for adjacency list.
 *   - Space: O(V) for visited array + recursion stack.
 *
 * Comparison:
 *   - DFS vs BFS:
 *       - DFS uses stack/recursion, explores depth first.
 *       - BFS uses queue, explores breadth first.
 *
 * Implementation Notes:
 *   - Uses a recursive helper `dfs_recursion`.
 *   - Iterates all vertices to handle disconnected graphs.
 */
void dfs_recursion(Graph graph, int item, Visit& visited) {
    cout << item << ' ';
    visited[item] = true;
    for (auto i : graph[item]) {
        if (!visited[i]) {
            dfs_recursion(graph, i, visited);
        }
    }
    return;
}

void dfs(Graph graph, Visit visited) {
    for (int i = 0; i < graph.size(); i++) {
        if (visited[i] == false) {
            dfs_recursion(graph, i, visited);
        }
    }
    return;
}

/*
 * Topological Sort (DFS-based)
 * -----------------------------
 * Definition:
 *   Orders nodes in a Directed Acyclic Graph (DAG) such that for every edge
 *   u → v, u comes before v in the ordering.
 *
 * Allowed Operations / Rules:
 *   - Only works for DAGs (no cycles allowed).
 *   - Can be implemented using DFS or Kahn’s Algorithm (indegree + queue).
 *
 * Recurrence Relation / Formula:
 *   - Perform DFS, and push nodes to a stack after all neighbors are visited.
 *   - Pop stack to get topological order.
 *
 * Edge Cases / Pitfalls:
 *   - Graph must be acyclic; otherwise, topological order is undefined.
 *   - Ensure all disconnected components are processed.
 *
 * Complexity:
 *   - Time: O(V + E)
 *   - Space: O(V) for visited array + stack.
 *
 * Example:
 *   DAG edges: 5 → 0, 4 → 0, 4 → 1, 2 → 3, 3 → 1
 *   Topological Sort output: 4 5 2 3 1 0 (one possible order)
 *
 * Use Cases:
 *   - Task scheduling.
 *   - Build systems / compilation order.
 *   - Prerequisite ordering in courses.
 *
 * Comparison:
 *   - DFS-based vs Kahn’s Algorithm:
 *       - DFS uses recursion and stack.
 *       - Kahn’s Algorithm uses indegree counting and queue.
 *
 * Implementation Notes:
 *   - Uses a recursive helper `topological_dfs`.
 *   - Stack stores nodes after visiting all neighbors.
 *   - Iterates all vertices to handle disconnected DAG components.
 */
void topological_dfs(Graph graph, int node, stack<int>& st, Visit& visited) {
    visited[node] = true;
    for (auto i : graph[node]) {
        if (!visited[i]) {
            topological_dfs(graph, i, st, visited);
        }
    }
    st.push(node);
}

void topological_sort(Graph graph) {
    cout << " Topological Sort :";
    stack<int> st;
    Visit      visited;
    for (int i = 0; i < graph.size(); i++) {
        if (visited[i] == false) {
            topological_dfs(graph, i, st, visited);
        }
    }
    while (!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << endl;
    return;
}

/*
 * Topological Sort using Indegree (Kahn's Algorithm)
 * -------------------------------------------------
 * Definition:
 *   Orders nodes in a Directed Acyclic Graph (DAG) such that for every edge
 *   u → v, u comes before v in the ordering. Uses BFS and indegree counting.
 *
 * Allowed Operations / Rules:
 *   - Only works for DAGs (no cycles allowed).
 *   - Computes indegree for each node and processes nodes with 0 indegree.
 *
 * Recurrence Relation / Formula:
 *   - Initialize indegree for all nodes.
 *   - Push all nodes with indegree 0 into a queue.
 *   - While the queue is not empty:
 *       - Pop node, append to topological order.
 *       - Reduce indegree of all neighbors by 1.
 *       - If neighbor’s indegree becomes 0, enqueue it.
 *
 * Edge Cases / Pitfalls:
 *   - If a cycle exists, not all nodes will be processed (queue becomes empty
 * before all nodes are visited).
 *   - Graph must be directed.
 *
 * Complexity:
 *   - Time: O(V + E) — visiting all nodes and all edges once.
 *   - Space: O(V) — indegree array + queue + output array.
 *
 * Example:
 *   DAG edges: 5 → 0, 4 → 0, 4 → 1, 2 → 3, 3 → 1
 *   Topological Sort output: 4 5 2 3 1 0 (one possible order)
 *
 * Use Cases:
 *   - Task scheduling.
 *   - Course prerequisite ordering.
 *   - Build system dependency resolution.
 *
 * Comparison:
 *   - BFS (Kahn's) vs DFS-based topological sort:
 *       - BFS uses indegree and queue.
 *       - DFS uses recursion and stack.
 *       - BFS can detect cycles naturally by checking if all nodes were
 * processed.
 *
 * Implementation Notes:
 *   - Uses a vector `degree` to track indegrees.
 *   - Uses a queue to process nodes with 0 indegree.
 *   - Appends nodes to `sorted` vector for final topological order.
 */
void kahnSort(Graph graph) {
    vector<int> degree(graph.size(), 0);
    for (auto it : graph) {
        for (auto ele : it.second) degree[ele]++;
    }

    queue<int> q;
    for (int i = 0; i < graph.size(); i++) {
        if (degree[i] == 0)
            q.push(i);
    }
    vector<int> sorted;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        sorted.push_back(node);

        for (auto it : graph[node]) {
            degree[it]--;
            if (degree[it] == 0)
                q.push(it);
        }
    }
    cout << "Topological Sort: ";
    for (auto it : sorted) {
        cout << it << ' ';
    }
    cout << endl;
}

// -----------------------------    Cycle detection in Graph
// ----------------------------
bool cycle_detect(Graph graph, Visit& visited, int node, vector<bool>& stack) {
    stack[node] = true;

    visited[node] = true;
    for (auto i : graph[node]) {
        if (stack[i])
            return true;
        if (!visited[i] && cycle_detect(graph, visited, i, stack)) {
            return true;
        }
    }

    stack[node] = false;
    return false;
}

// ----------------------------------------   Eulerian Path
// ---------------------------------------
void eulerian_path() {}

// ---------------------------------------   Eulerian Circuit
// --------------------------------------
void eulerian_circuit() {}

int main() {
    int   arr1[][2] = {{0, 1}, {0, 6}, {0, 5}, {1, 2}, {1, 4},
                       {2, 6}, {3, 2}, {5, 3}, {4, 3}};
    int   m         = sizeof(arr1) / sizeof(arr1[0]);
    int   n         = 7;
    Graph graph;
    for (int i = 0; i < m; i++) {
        int x = arr1[i][0];
        int y = arr1[i][1];
        graph[x].insert(y);
    }
    cout << endl << "Graph 1 : " << endl;
    for (auto i : graph) {
        cout << i.first << "-> ";
        for (auto j : i.second) {
            cout << j << ' ';
        }
        cout << endl;
    }
    bfs(graph);
    cout << endl << " DFS :";
    Visit visit1;
    dfs(graph, visit1);
    cout << endl;
    topological_sort(graph);
    cout << endl;
    kahnSort(graph);

    // ------------------        Graph 2      -----------------------
    int arr2[][2] = {{2, 0},  {2, 1}, {1, 3},  {0, 3},  {4, 0},  {4, 3},
                     {4, 5},  {3, 7}, {3, 6},  {6, 8},  {7, 8},  {7, 9},
                     {5, 10}, {5, 9}, {10, 9}, {9, 12}, {9, 11}, {8, 11}};
    m             = sizeof(arr2) / sizeof(arr2[0]);
    n             = 13;
    graph.clear();
    for (int i = 0; i < m; i++) {
        int x = arr2[i][0];
        int y = arr2[i][1];
        graph[x].insert(y);
    }
    cout << endl << "Graph 2 : " << endl;
    for (auto i : graph) {
        cout << i.first << "-> ";
        for (auto j : i.second) {
            cout << j << ' ';
        }
        cout << endl;
    }

    bfs(graph);
    cout << endl << " DFS :";
    Visit visit2;
    dfs(graph, visit2);
    cout << endl;
    topological_sort(graph);
    kahnSort(graph);
    vector<bool> stack(n, false);
    visit2.clear();
    for (int i = 0; i < n; i++) {
        if (!visit2[i] && cycle_detect(graph, visit2, i, stack)) {
            cout << " Cycle Detected " << endl;
            break;
        }
    }

    return 0;
}
