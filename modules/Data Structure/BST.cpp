#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

struct Node {
   public:
    int   val;
    Node* left;
    Node* right;

    Node(int key) {
        val   = key;
        left  = NULL;
        right = NULL;
    }
};

Node* insertInBST(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->val) {
        root->left = insertInBST(root->left, val);
    } else {
        root->right = insertInBST(root->right, val);
    }
    return root;
}

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

// -----------------------------    Search in BST ----------------------------

Node* searchInBST(Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->val == key) {
        return root;
    }
    if (root->val > key) {
        return searchInBST(root->left, key);
    }
    return searchInBST(root->right, key);
}

Node* inOrderSuccesor(Node* root) {
    Node* curr = root;
    while (curr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

// -----------------------------    Delete node in BST
// ----------------------------

Node* deleteInBST(Node* root, int key) {
    if (root->val > key) {
        root->left = deleteInBST(root->left, key);
    } else if (root->val < key) {
        root->right = deleteInBST(root->right, key);
    } else {
        if (!root->left) {
            Node* temp = root->right;
            delete (root);
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete (root);
            return temp;
        }
        Node* temp  = inOrderSuccesor(root->right);
        root->val   = temp->val;
        root->right = deleteInBST(root->right, temp->val);
    }
    return root;
}

// -----------------------------    Build a BST from Preorder
// ----------------------------
Node* buildTree_preorder(vector<int> arr, int min = INT_MIN,
                         int max = INT_MAX) {
    static size_t i    = 0;
    Node*         curr = nullptr;
    if (arr[i] >= min && arr[i] <= max) {
        curr = new Node(arr[i]);
        i++;
        if (i >= arr.size())
            return curr;
        if (curr->val >= arr[i]) {
            curr->left = buildTree_preorder(arr, min, curr->val);
        }
        if (curr->val <= arr[i]) {
            curr->right = buildTree_preorder(arr, curr->val, max);
        }
    }
    return curr;
}

// -----------------------------    Valid Binary Search Tree
// ----------------------------

bool isValidBST(Node* root, int min = INT_MIN, int max = INT_MAX) {
    if (!root)
        return true;
    if (root->val >= max || root->val <= min)
        return false;
    bool left  = isValidBST(root->left, min, root->val);
    bool right = isValidBST(root->right, root->val, max);
    return left && right;
}

// -----------------------------    Build a BST from Inorder/Sorted Array
// ----------------------------
Node* buildTree_Sorted(vector<int> arr, int start, int end) {
    if (start > end) {
        return nullptr;
    }
    int   mid   = start + (end - start) / 2;
    Node* curr  = new Node(arr[mid]);
    curr->left  = buildTree_Sorted(arr, start, mid - 1);
    curr->right = buildTree_Sorted(arr, mid + 1, end);
    return curr;
}

// -----------------------------    No. of Unique BST from n nodes
// ----------------------------
vector<Node*> generate_BST(int start, int end) {
    vector<Node*> list;
    if (start > end) {
        list.push_back(NULL);
        return list;
    }

    for (int i = start; i <= end; i++) {
        vector<Node*> leftSubtree  = generate_BST(start, i - 1);
        vector<Node*> rightSubtree = generate_BST(i + 1, end);

        for (size_t j = 0; j < leftSubtree.size(); j++) {
            Node* left = leftSubtree[j];
            for (size_t k = 0; k < rightSubtree.size(); k++) {
                Node* right = rightSubtree[k];
                Node* curr  = new Node(i);
                curr->left  = left;
                curr->right = right;
                list.push_back(curr);
            }
        }
    }
    return list;
}

// -----------------------------    Recover Binary Tree
// ----------------------------

//*         https://leetcode.com/problems/recover-binary-search-tree/

Node* recover_tree(Node* root) {
    return NULL;
}

//  -------------------------    Insert and Delete in AVL Tree
//  -------------------------
// ! Incomplete
Node* left_rotate(Node*& root) {
    Node* left  = root->left;
    root->left  = left->right;
    left->right = root;
    return left;
}

Node* right_rotate(Node*& root) {
    Node* right = root->right;
    root->right = right->left;
    right->left = root;
    return right;
}

Node* avl_tree(Node* root, int& height) {
    if (!root)
        return nullptr;
    int   lh, rh;
    Node* left  = avl_tree(root->left, lh);
    Node* right = avl_tree(root->right, rh);
    if (abs(lh - rh) > 1) {
        if (lh > rh) {
            if (root->val) {
            }
        } else {
            if (root->val) {
            }
        }
    }
    height = 1 + max(lh, rh);
    return root;
}

int main() {
    Node* root = new Node(50);
    insertInBST(root, 40);
    insertInBST(root, 70);
    insertInBST(root, 60);
    insertInBST(root, 90);
    display(root);

    display(deleteInBST(root, 50));

    vector<int> arr  = {7, 5, 4, 6, 8, 9, 8, 12};
    Node*       tree = buildTree_preorder(arr);
    display(tree);

    vector<int> sorted = {1, 2, 3, 4, 5, 6, 7};
    root               = buildTree_Sorted(sorted, 0, sorted.size() - 1);
    display(root);

    cout << "Is Tree is valid BST? " << isValidBST(root) << endl;

    vector<Node*> trees = generate_BST(1, 7);
    for (auto i : trees) {
        display(i);
        cout << endl << endl << endl;
    }

    return 0;
}
