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
    stack<node*> st;
    while(!st.empty() || root){
        while(root){
            st.push(root);
            root=root->left;
        }
        root=st.top();
        st.pop();
        arr.push_back(root->val);
        root=root->right;
    }
}

// ------------------------------------     Preorder Traversal     ---------------------------------------
void preOrder_traversal(node* root,vector<int> &arr){
    stack<node*> st;
    while(!st.empty() || root){
        while(root){
            if(root->right)st.push(root->right); 
            arr.push_back(root->val);
            root=root->left;
        }
        if(!st.empty())
        {
            root=st.top();
            st.pop();
        }
    }
    return ;
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
    static int idx=postorder.size()-1;
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


// -----------------------------    Top View of Binary Tree     ----------------------------
void top_view(node* root){
    if(!root)return;

        vector<int> arr;
        queue<pair<node*,int>> q;
        q.push({root,0});
        while (!q.empty())
        {
            root=q.front().first;
            int val=q.front().second;
            q.pop();
            if(find(arr.begin(),arr.end(),val)==arr.end()){
                cout<<root->val<<" ";
                arr.push_back(val);
            }
            if(root->left){
                q.push({root->left,val-1});
            }
            if(root->right){
                q.push({root->right,val+1});
            }
        }
        return ;
}

// -----------------------------    Lowest Common Ancestor Recursively     ----------------------------
//*     Soution 2: Can also be solved be storing the path to both nodes and finding last common path node. 
//*     Time Complexity=O(n)

node* LCA(node* root,int n1,int n2){
    if(!root){
        return NULL;
    }
    if(root->val==n1 || root->val==n2){
        return root;
    }
    node* left=LCA(root->left,n1,n2);
    node* right=LCA(root->right,n1,n2);
    if(left && right){
        return root;
    }
    if(!left && !right){
        return NULL;
    }
    return left?left:right;
}

// -----------------------------    Shortest Distance b/w 2 Nodes     ----------------------------

int find_dist(node* root,int k,int dist){
    if(!root)return -1;
    if(root->val==k){
        return dist;
    }
    int left=find_dist(root->left,k,dist+1);
    if(left!=-1){
        return left;
    }
    return find_dist(root->right,k,dist+1);
}

int dist_nodes(node* root,int n1,int n2){
    node* lca=LCA(root,n1,n2);

    int d1=find_dist(lca,n1,0);
    int d2=find_dist(lca,n2,0);
    
    return d1+d2;
}
// -----------------------------    Flatten the Binary Tree     ----------------------------

node* flatten_tree(node* head){
    stack<node*> st;
    node* dummy=new node(-1);
    node* temp=dummy;
    node* root=head;
    while(!st.empty() || root){
        while(root){
            if(root->right)st.push(root->right);
            dummy->left=root;
            dummy->right=nullptr;
            dummy=dummy->left;
            root=root->left;
        }
        if(!st.empty()){
            root=st.top();
            st.pop();
        }
        
    }
    return temp->left;
}
// -----------------------------    Max Path Sum in Binary Tree     ----------------------------

int max_pathSum(node* root,int &maxi){
    if(!root){
        return 0;
    }
    int left=max_pathSum(root->left,maxi);
    int right=max_pathSum(root->right,maxi);
    int ans=max(root->val,root->val+left);
    ans=max(ans,root->val+right);
    maxi=max(maxi,max(ans,root->val+right+left));
    return ans;
}   

int main(){
    node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);

    vector<int> preorder;
    preOrder_traversal(root,preorder);
    cout<<"PreOrder Traversal : ";
    for(auto i: preorder){
        cout<<i<<" -> ";
    }
    cout<<endl;


    vector<int> inorder;
    inOrder_traversal(root,inorder);
    cout<<"Inorder Traversal : ";
    for(auto i: inorder){
        cout<<i<<" -> ";
    }
    cout<<endl;


    node* tree=buildTree_PreOrder(preorder,inorder,0,inorder.size()-1);
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

    cout<<dist_nodes(root,11,6)<<endl<<endl;

    cout<<"Top view of Binary Tree: ";
    top_view(root);
    cout<<endl;

    cout<<"MAX Path Sum : ";
    int max=INT_MIN;
    max_pathSum(root,max);
    cout<<max<<endl;

    
    return 0;
}   