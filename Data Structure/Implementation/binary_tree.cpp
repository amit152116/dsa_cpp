#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
class node
{ 
public:
    int val;
    node* left;
    node* right;
    node(int val){
        this->val =val;
        left=NULL;
        right=NULL;
    }
    
};
void display(node* root, string prefix = "", bool isLeft = true) {
        if (root == nullptr) {
            cout << "Empty tree";
            return;
        }

        if(root->right) {
            display(root->right, prefix + (isLeft ? "│   " : "    "), false);
        }

        cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(root->val) + "\n";

        if (root->left) {
            display(root->left, prefix + (isLeft ? "    " : "│   "), true);
        }
    }
// ------------------------------------     Inorder Traversal     ---------------------------------------
void inOrder_traversal(node* root, vector<int> &arr){
    if(!root){
        return;
    }
    inOrder_traversal(root->left,arr);
    arr.push_back(root->val);
    inOrder_traversal(root->right,arr);
}

// ------------------------------------     Preorder Traversal     ---------------------------------------
void preOrder_traversal(node* root,vector<int> &arr){
    if(root==NULL){
        return;
    }
    arr.push_back(root->val);
    preOrder_traversal(root->left,arr);
    preOrder_traversal(root->right,arr);
}

// ------------------------------------     Postorder Traversal     ---------------------------------------
void postOrder_traversal(node* root,vector<int> &arr){
    if(root==NULL){
        return;
    }
    postOrder_traversal(root->left,arr);
    postOrder_traversal(root->right,arr);
    arr.push_back(root->val);
}
// ------------------------------------     Level Order Traversal     ---------------------------------------
void levelOrder_traversal(node* root,vector<int> &arr){
    queue<node*> st;
    st.push(root);
    int level=1;
    while(!st.empty()){
        int n=st.size();
        for(int i=0;i<n;i++){
            root=st.front();
            st.pop();
            arr.push_back(root->val);
            if(root->left)st.push(root->left);
            if(root->right)st.push(root->right);
        }
        level++;
    }
    cout<<"Levels: "<<level<<endl;
}

// -----------------------------    Build Tree using Inorder and Preorder     ----------------------------
int search(vector<int> inorder,int start,int end,int key){
    for(int i=start;i<=end;i++){
        if(inorder[i]==key){
            return i;
        }
    }
    return -1;
}
node* buildTree_PreOrder(vector<int> preorder,vector<int> inorder,int start,int end){
    if(start>end){
        return NULL;
    }
    static int idx=0;
    int curr=preorder[idx];
    idx++;
    node* Node=new node(curr);
    int pos=search(inorder,start,end,curr);
    Node->left=buildTree_PreOrder(preorder,inorder,start,pos-1);
    Node->right=buildTree_PreOrder(preorder,inorder,pos+1,end);
    return Node;
}

// -----------------------------    Build Tree using Inorder and Postorder     ----------------------------
node* buildTree_PostOrder(vector<int> postorder,vector<int> inorder, int start, int end){
    if(start>end){
        return NULL;
    }
    static int idx=6;
    int curr=postorder[idx];
    idx--;
    node* Node=new node(curr);
    int pos=search(inorder,start,end,curr);
    
    Node->right=buildTree_PostOrder(postorder,inorder,pos+1,end);
    Node->left=buildTree_PostOrder(postorder,inorder,start,pos-1);
    return Node;

}

// -----------------------------    NO. of Nodes of Tree     ----------------------------
int countNodes(node* root){
    if(!root){
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

// -----------------------------    Sum of Nodes of Tree     ----------------------------
int sumNodes(node* root){
    if(!root){
        return 0;
    }
    return root->val+sumNodes(root->left)+sumNodes(root->right);
}

// -----------------------------    Height of Binary Tree     ----------------------------
int treeHeight(node* root){
    if(!root){
        return 0;
    }
    int left=treeHeight(root->left);
    int right=treeHeight(root->right);
    return max(left,right)+1;
}
// -----------------------------    Diameter of Binary Tree     ----------------------------
// Time complexity = O(n^2)
int treeDiameter(node* root){
    if(!root){
        return 0;
    }
    int lh=treeHeight(root->left);
    int rh=treeHeight(root->right);

    int ldia=treeDiameter(root->left);
    int rdia=treeDiameter(root->right);
    return max(lh+rh+1,max(ldia,rdia));

}

// -----------------------------    Diameter of Binary Tree     ----------------------------
// Time complexity = O(n)
int treeDiameter(node* root,int &height){
    if(!root){
        height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ldia=treeDiameter(root->left,lh);
    int rdia=treeDiameter(root->right,rh);
    height=max(lh,rh)+1;
    return max(lh+rh+1,max(ldia,rdia));
}

// -----------------------------    Sum Replacement of Binary Tree     ----------------------------

void sum_replacement(node* &root){
    if(!root){
        return;
    }
    sum_replacement(root->left);
    sum_replacement(root->right);
    if(root->left){
        root->val+=root->left->val;
    }
    if(root->right){
        root->val+=root->right->val;
    }
    return;
    
}

// -----------------------------    Check Balanced Binary Tree     ----------------------------
bool isBalanced(node* root,int &height){
    if(!root)return true;
    int lh=0,rh=0;
    if(isBalanced(root->left,lh)==false)return false;
    if(isBalanced(root->right,rh)==false)return false;
    height=max(lh,rh)+1;
    int diff=abs(lh-rh);
    return diff>1?false:true;
}


// -----------------------------    Right View of Binary Tree     ----------------------------

void right_view(node* root){
    queue<node*> st;
    st.push(root);
    int sum=0;
    while(!st.empty()){
        int n=st.size();
        for(int i=0;i<n;i++){
            root=st.front();
            st.pop();
            if(root->left)st.push(root->left);
            if(root->right)st.push(root->right);
            if(i==n-1)sum+=root->val;
        }
    }
}
int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    vector<int> preorder={1,2,4,5,3,6,7};
    vector<int> inorder={4,2,5,1,6,3,7};

    node* tree=buildTree_PreOrder(preorder,inorder,0,inorder.size()-1);
    vector<int> postorder={4,5,2,6,7,3,1};
    tree=buildTree_PostOrder(postorder,inorder,0,inorder.size()-1);
    vector<int> arr;
    levelOrder_traversal(tree,arr);
    for(auto i:arr){
        cout<<i<<',';
    }
    cout<<endl<<"No. of nodes "<<countNodes(tree)<<endl;
    cout<<"Sum of Nodes "<<sumNodes(tree)<<endl;
    cout<<"Height of Tree "<<treeHeight(tree)<<endl;
    cout<<"Diameter of Tree "<<treeDiameter(tree)<<endl;
    int height=0;
    cout<<"Diameter of tree "<<treeDiameter(tree,height)<<endl;
    display(root);
    sum_replacement(root);
    display(root);
    height=0;
    cout<<isBalanced(root,height)<<endl;


    
    return 0;
}   