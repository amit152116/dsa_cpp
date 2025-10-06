#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

class Node {
   public:
    int   val;
    Node* left;
    Node* right;

    explicit Node(int val) : val(val), left(nullptr), right(nullptr) {}
};

void display(Node* root, string prefix = "", bool isLeft = true) {
    if (root == nullptr) {
        cout << "Empty tree";
        return;
    }

    if (root->right) {
        display(root->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(root->val) + "\n";

    if (root->left) {
        display(root->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

// ------------------------------------     Inorder Traversal
// ---------------------------------------
void inOrder_traversal(Node* root, vector<int>& arr) {
    stack<Node*> st;
    while (!st.empty() || root) {
        while (root) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        arr.push_back(root->val);
        root = root->right;
    }
}

// ------------------------------------     Preorder Traversal
// ---------------------------------------
void preOrder_traversal(Node* root, vector<int>& arr) {
    stack<Node*> st;
    while (!st.empty() || root) {
        while (root) {
            if (root->right)
                st.push(root->right);
            arr.push_back(root->val);
            root = root->left;
        }
        if (!st.empty()) {
            root = st.top();
            st.pop();
        }
    }
    return;
}

// ------------------------------------     Postorder Traversal
// ---------------------------------------
void postOrder_traversal(Node* root, vector<int>& arr) {
    if (root == NULL) {
        return;
    }
    postOrder_traversal(root->left, arr);
    postOrder_traversal(root->right, arr);
    arr.push_back(root->val);
}

// ------------------------------------     Level Order Traversal / BFS
// ---------------------------------------
void levelOrder_traversal(Node* root, vector<int>& arr) {
    queue<Node*> st;
    st.push(root);
    int level = 1;
    while (!st.empty()) {
        int n = st.size();
        for (int i = 0; i < n; i++) {
            root = st.front();
            st.pop();
            arr.push_back(root->val);
            if (root->left)
                st.push(root->left);
            if (root->right)
                st.push(root->right);
        }
        level++;
    }
    cout << "Levels: " << level << endl;
}

// -----------------------------    Build Tree using Inorder and Preorder
// ----------------------------
int search(vector<int> inorder, int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == key) {
            return i;
        }
    }
    return -1;
}

Node* buildTree_PreOrder(vector<int> preorder, vector<int> inorder, int start,
                         int end) {
    if (start > end) {
        return NULL;
    }
    static int idx  = 0;
    int        curr = preorder[idx];
    idx++;
    Node* node  = new class Node(curr);
    int   pos   = search(inorder, start, end, curr);
    node->left  = buildTree_PreOrder(preorder, inorder, start, pos - 1);
    node->right = buildTree_PreOrder(preorder, inorder, pos + 1, end);
    return node;
}

// -----------------------------    Build Tree using Inorder and Postorder
// ----------------------------
Node* buildTree_PostOrder(vector<int> postorder, vector<int> inorder, int start,
                          int end) {
    if (start > end) {
        return NULL;
    }
    static int idx  = postorder.size() - 1;
    int        curr = postorder[idx];
    idx--;
    Node* node = new Node(curr);
    int   pos  = search(inorder, start, end, curr);

    node->right = buildTree_PostOrder(postorder, inorder, pos + 1, end);
    node->left  = buildTree_PostOrder(postorder, inorder, start, pos - 1);
    return node;
}

// -----------------------------    NO. of Nodes of Tree
// ----------------------------
int countNodes(Node* root) {
    if (!root) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// -----------------------------    Sum of Nodes of Tree
// ----------------------------
int sumNodes(Node* root) {
    if (!root) {
        return 0;
    }
    return root->val + sumNodes(root->left) + sumNodes(root->right);
}

// -----------------------------    Height of Binary Tree
// ----------------------------
int treeHeight(Node* root) {
    if (!root) {
        return 0;
    }
    int left  = treeHeight(root->left);
    int right = treeHeight(root->right);
    return max(left, right) + 1;
}

// -----------------------------    Diameter of Binary Tree - 1
// ---------------------------- Time complexity = O(n^2)
int treeDiameter(Node* root) {
    if (!root) {
        return 0;
    }
    int lh = treeHeight(root->left);
    int rh = treeHeight(root->right);

    int ldia = treeDiameter(root->left);
    int rdia = treeDiameter(root->right);
    return max(lh + rh + 1, max(ldia, rdia));
}

// -----------------------------    Diameter of Binary Tree - 2
// ---------------------------- Time complexity = O(n)
int treeDiameter(Node* root, int& height) {
    if (!root) {
        height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int ldia = treeDiameter(root->left, lh);
    int rdia = treeDiameter(root->right, rh);
    height   = max(lh, rh) + 1;
    return max(lh + rh + 1, max(ldia, rdia));
}

// -----------------------------    Sum Replacement of Binary Tree
// ----------------------------

void sum_replacement(Node*& root) {
    if (!root) {
        return;
    }
    sum_replacement(root->left);
    sum_replacement(root->right);
    if (root->left) {
        root->val += root->left->val;
    }
    if (root->right) {
        root->val += root->right->val;
    }
    return;
}

// -----------------------------    Check Balanced Binary Tree
// ----------------------------
bool isBalanced(Node* root, int& height) {
    if (!root)
        return true;
    int lh = 0, rh = 0;
    if (isBalanced(root->left, lh) == false)
        return false;
    if (isBalanced(root->right, rh) == false)
        return false;
    height   = max(lh, rh) + 1;
    int diff = abs(lh - rh);
    return diff > 1 ? false : true;
}

// -----------------------------    Right View of Binary Tree
// ----------------------------

void right_view(Node* root) {
    queue<Node*> st;
    st.push(root);
    int sum = 0;
    while (!st.empty()) {
        int n = st.size();
        for (int i = 0; i < n; i++) {
            root = st.front();
            st.pop();
            if (root->left)
                st.push(root->left);
            if (root->right)
                st.push(root->right);
            if (i == n - 1)
                sum += root->val;
        }
    }
}

// -----------------------------    Top View of Binary Tree
// ----------------------------
void top_view(Node* root) {
    if (!root)
        return;

    map<int, int>           mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        root        = q.front().first;
        int viewIdx = q.front().second;
        q.pop();
        if (mp.find(viewIdx) == mp.end()) {
            mp[viewIdx] = root->val;
        }
        if (root->left) {
            q.push({root->left, viewIdx - 1});
        }
        if (root->right) {
            q.push({root->right, viewIdx + 1});
        }
    }
    for (auto i : mp) {
        cout << i.second << ' ';
    }
    return;
}

// -----------------------------    Bottom View of Binary Tree
// ----------------------------
void bottom_view(Node* root) {
    if (!root)
        return;

    map<int, int>           mp;
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        root        = q.front().first;
        int viewIdx = q.front().second;
        q.pop();
        mp[viewIdx] = root->val;
        if (root->left) {
            q.push({root->left, viewIdx - 1});
        }
        if (root->right) {
            q.push({root->right, viewIdx + 1});
        }
    }
    for (auto i : mp) {
        cout << i.second << ' ';
    }
    return;
}

// -----------------------------    Lowest Common Ancestor Recursively
// ----------------------------
//*     Soution 2: Can also be solved be storing the path to both nodes and
// finding last common path node.
//*     Time Complexity=O(n)

Node* LCA(Node* root, int n1, int n2) {
    if (!root) {
        return NULL;
    }
    if (root->val == n1 || root->val == n2) {
        return root;
    }
    Node* left  = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    if (left && right) {
        return root;
    }
    if (!left && !right) {
        return NULL;
    }
    return left ? left : right;
}

// -----------------------------    Shortest Distance b/w 2 Nodes
// ----------------------------

int find_dist(Node* root, int k, int dist) {
    if (!root)
        return -1;
    if (root->val == k) {
        return dist;
    }
    int left = find_dist(root->left, k, dist + 1);
    if (left != -1) {
        return left;
    }
    return find_dist(root->right, k, dist + 1);
}

int dist_nodes(Node* root, int n1, int n2) {
    Node* lca = LCA(root, n1, n2);

    int d1 = find_dist(lca, n1, 0);
    int d2 = find_dist(lca, n2, 0);

    return d1 + d2;
}

// -----------------------------    Flatten the Binary Tree
// ----------------------------

Node* flatten_tree(Node* head) {
    stack<Node*> st;

    // Create a dummy node to help construct the flattened tree
    Node* dummy = new Node(-1);
    Node* temp  = dummy;  // Pointer to track the last node in the new list
    Node* root  = head;

    while (!st.empty() || root) {
        while (root) {
            // If the current node has a right child, push it to the stack
            if (root->right)
                st.push(root->right);

            // Link current node to the flattened list
            dummy->right = root;     // Use right pointer for flattened list
            dummy->left  = nullptr;  // Ensure left is null
            dummy        = root;     // Move dummy to the current node

            // Move to left child (pre-order traversal)
            root = root->left;
        }

        // If the left chain is exhausted, pop from the stack
        if (!st.empty()) {
            root = st.top();
            st.pop();
        }
    }

    // Return the right child of dummy, which is the actual head of flattened
    // tree
    return temp->right;
}

// -----------------------------    Max Path Sum in Binary Tree
// ----------------------------

int max_pathSum(Node* root, int& maxSum) {
    if (!root)
        return 0;

    int left  = max(0, max_pathSum(root->left, maxSum));
    int right = max(0, max_pathSum(root->right, maxSum));

    int current = root->val + left + right;  // max path *through* this node
    maxSum      = max(maxSum, current);      // update global max

    return root->val + max(left, right);  // return max path *going up*
}

int main() {
    Node* root         = new Node(1);
    root->left         = new Node(2);
    root->right        = new Node(3);
    root->left->left   = new Node(4);
    root->left->right  = new Node(5);
    root->right->left  = new Node(6);
    root->right->right = new Node(7);

    vector<int> preorder;
    preOrder_traversal(root, preorder);
    cout << "PreOrder Traversal : ";
    for (auto i : preorder) {
        cout << i << " -> ";
    }
    cout << endl;

    vector<int> inorder;
    inOrder_traversal(root, inorder);
    cout << "Inorder Traversal : ";
    for (auto i : inorder) {
        cout << i << " -> ";
    }
    cout << endl;

    Node* tree = buildTree_PreOrder(preorder, inorder, 0, inorder.size() - 1);
    vector<int> arr;
    levelOrder_traversal(tree, arr);
    for (auto i : arr) {
        cout << i << ',';
    }
    cout << endl << "No. of nodes " << countNodes(tree) << endl;
    cout << "Sum of Nodes " << sumNodes(tree) << endl;
    cout << "Height of Tree " << treeHeight(tree) << endl;
    cout << "Diameter of Tree " << treeDiameter(tree) << endl;
    int height = 0;
    cout << "Diameter of tree " << treeDiameter(tree, height) << endl;
    display(root);
    sum_replacement(root);
    display(root);
    height = 0;
    cout << isBalanced(root, height) << endl;

    cout << dist_nodes(root, 11, 6) << endl << endl;

    cout << "Top view of Binary Tree: ";
    top_view(root);
    cout << endl;
    cout << "Bottom view of Binary Tree: ";
    bottom_view(root);
    cout << endl;

    cout << "MAX Path Sum : ";
    int max = INT_MIN;
    max_pathSum(root, max);
    cout << max << endl;

    return 0;
}
