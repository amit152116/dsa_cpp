#include <bits/stdc++.h>

#include "../Data Structure/DisjointSet.hpp"
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
void bfs(Graph graph, int item = 0) {
    fast;
    cout << endl << " BFS :";
    Visit      visited;
    queue<int> st;
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
void dfs(Graph graph, Visit& visited, int item = 0) {
    cout << item << ' ';
    visited[item] = true;
    for (auto i : graph[item]) {
        if (!visited[i]) {
            dfs(graph, visited, i);
        }
    }
    return;
}

// -----------------------------    DFS in Graph    ----------------------------
/* When to use DFS in graph?
    1. No. of Connected Components
    2. Compute Minimum Spanning Tree of graph
    3. Detect and find cycles in graph
    4. Checking if graph is Bipartite
    5. Find Strongly Connected Components
    6. Topological sort of graph
    7. Find bridge and articulation point
    8. Find argumenting path in network flow
    9. Generate Mazes
*/

// -----------    Cycle detection in Graph -----------------
bool cycle_detect(Graph graph, Visit& visited, int node, int parent) {
    visited[node] = true;
    for (auto i : graph[node]) {
        if (i != parent) {
            if (visited[i]) {
                return true;
            } else if (cycle_detect(graph, visited, i, node)) {
                return true;
            }
        }
    }
    return false;
}

// -----------------------------    Connected Graph ----------------------------
int connected_graph(Graph graph, Visit& visited, int node) {
    int x         = 1;
    visited[node] = true;
    for (auto i : graph[node]) {
        if (!visited[i]) {
            x += connected_graph(graph, visited, i);
        }
    }
    return x;
}

// ----------------    Bipartite Graph by DFS ------------------------

bool isBipartite_Graph(Graph graph, Visit& visited, int node, vector<int>& set,
                       int color) {
    if (set[node] != -1 and set[node] != color) {
        return false;
    }
    set[node] = color;
    if (visited[node]) {
        return true;
    }
    visited[node] = true;
    for (auto i : graph[node]) {
        if (!isBipartite_Graph(graph, visited, i, set, color ^ 1)) {
            return false;
        }
    }
    return true;
}

// -----------------------------   Eulerian Path    ----------------------------
void eulerian_path() {}

// ------------------------- Eulerian Circuit ----------------------------
void eulerian_circuit() {}

// -----------------------------   Adjancey Matrix ----------------------------
vector<vector<int>> adjacency_matrix(int n, int arr[][2]) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        int x        = arr[i][0];
        int y        = arr[i][1];
        matrix[x][y] = 1;
        matrix[y][x] = 1;
    }
    return matrix;
}

// -----------------------------  Finding Center of Rooted Tree
// ----------------------
vector<int> find_center(Graph graph) {
    vector<int> center;
    return center;
}

int main() {
    int   arr1[][2] = {{0, 1}, {0, 6}, {1, 2}, {1, 4},
                       {2, 6}, {3, 2}, {5, 3}, {4, 3}};
    int   m         = sizeof(arr1) / sizeof(arr1[0]);
    int   n         = 7;
    Graph graph;
    for (int i = 0; i < m; i++) {
        int x = arr1[i][0];
        int y = arr1[i][1];
        graph[x].insert(y);
        graph[y].insert(x);
    }
    cout << endl << "Graph 1 : " << endl;
    for (auto i : graph) {
        cout << i.first << "-> ";
        for (auto j : i.second) {
            cout << j << ' ';
        }
        cout << endl;
    }

    auto matrix = adjacency_matrix(m, arr1);

    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    bfs(graph);
    cout << endl << " DFS :";
    Visit visit1;
    dfs(graph, visit1);
    cout << endl;

    // ----------------------    Cycle detection Using Disjoint Sets
    // ------------------
    bool cycle = false;

    Disjoint_Set disjoint_set;
    for (auto i : arr1) {
        int u = i[0];
        int v = i[1];
        int x = disjoint_set.find_set(u);
        int y = disjoint_set.find_set(v);
        if (x == y) {
            cycle = true;
            break;
        } else {
            disjoint_set.union_sets(u, v);
        }
    }
    if (cycle) {
        cout << " Cycle detected" << endl;
    } else {
        cout << " No Cycle detected" << endl;
    }

    vector<int> arr;
    visit1.clear();
    for (int i = 0; i < n; i++) {
        if (!visit1[i]) {
            arr.push_back(connected_graph(graph, visit1, i));
        }
    }
    cout << " Connected Part :";
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << endl;

    vector<int> set(n, -1);
    visit1.clear();
    for (int i = 0; i < n; i++) {
        if (!visit1[i]) {
            if (!isBipartite_Graph(graph, visit1, i, set, 0)) {
                cout << "Graph is not Bipartite" << endl;
                break;
            }
        }
    }
    cout << " Color of Graph :";
    for (auto i : set) {
        cout << i << ' ';
    }
    cout << endl;

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
        graph[y].insert(x);
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
    visit2.clear();
    for (int i = 0; i < n; i++) {
        if (!visit2[i] && cycle_detect(graph, visit2, i, -1)) {
            cout << "Cycle Detected " << endl;
            break;
        }
    }

    vector<int> color_set(n, -1);
    visit2.clear();
    for (int i = 0; i < n; i++) {
        if (!visit2[i] && !isBipartite_Graph(graph, visit2, i, color_set, 0)) {
            cout << "Not Bipartite Graph" << endl;
            break;
        }
    }

    int arr3[][2] = {{2, 0},  {1, 3},  {4, 0},  {4, 3}, {4, 5},  {3, 7},
                     {3, 6},  {6, 8},  {7, 8},  {7, 9}, {5, 10}, {5, 9},
                     {10, 9}, {9, 12}, {9, 11}, {8, 11}};
    m             = sizeof(arr3) / sizeof(arr3[0]);
    n             = 13;
    graph.clear();
    for (int i = 0; i < m; i++) {
        int x = arr3[i][0];
        int y = arr3[i][1];
        graph[x].insert(y);
        graph[y].insert(x);
    }
    cout << endl << "Graph 3 : " << endl;
    for (auto i : graph) {
        cout << i.first << "-> ";
        for (auto j : i.second) {
            cout << j << ' ';
        }
        cout << endl;
    }
    visit2.clear();
    for (int i = 0; i < n; i++) {
        if (!visit2[i] && cycle_detect(graph, visit2, i, -1)) {
            cout << "Cycle Detected " << endl;
            break;
        }
    }
}
