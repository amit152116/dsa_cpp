#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

struct node{
    public:
    int val;
    node* left;
    node* right;

    node(int key){
        val=key;
        left=NULL;
        right=NULL;
    }
};

node* insertInBST(node* root, int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->val){
        root->left=insertInBST(root->left,val);
    }
    else{
        root->right=insertInBST(root->right,val);
    }
    return root;
}

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



// -----------------------------    Search in BST     ----------------------------

node* searchInBST(node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->val==key){
        return root;
    }
    if(root->val>key){
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}


node* inOrderSuccesor(node* root){
    node* curr=root;
    while(curr && curr->left){
        curr=curr->left;
    }
    return curr;
}
// -----------------------------    Delete node in BST     ----------------------------

node* deleteInBST(node* root,int key){
    if(root->val>key){
        root->left=deleteInBST(root->left,key);
    }
    else if(root->val<key){
        root->right=deleteInBST(root->right,key);
    }
    else{
        if(!root->left){
            node* temp=root->right;
            delete(root);
            return temp;
        }
        else if(!root->right){
            node* temp=root->left;
            delete(root);
            return temp;
        }
        node* temp=inOrderSuccesor(root->right);
        root->val=temp->val;
        root->right=deleteInBST(root->right,temp->val);
    }
    return root;
}


// -----------------------------    Build a BST from Preorder     ----------------------------
node* buildTree_preorder(vector<int> arr,int min=INT_MIN, int max=INT_MAX){
    static int i=0;
    node* curr=nullptr;
    if(arr[i]>=min && arr[i]<=max){
        curr=new node(arr[i]);
        i++;
        if(i<arr.size()){
            if(curr->val>=arr[i]){
                curr->left=buildTree_preorder(arr,min,curr->val);
            }
        }
        if(i<arr.size()){
            if(curr->val<=arr[i]){
                curr->right=buildTree_preorder(arr,curr->val,max);
            }
        }
        
    }
    return curr;
}


// -----------------------------    Valid Binary Search Tree     ----------------------------

bool isValidBST(node* root,node* min=NULL,node* max=NULL) {
    if(!root)return true;
    if(max && root->val>=max->val || min&&root->val<=min->val)return false;
    bool left=isValidBST(root->left,min,root);
    bool right=isValidBST(root->right,root,max);
    return left&&right;
}


// -----------------------------    Build a BST from Inorder/Sorted Array     ----------------------------
node* buildTree_Sorted(vector<int> arr,int start,int end){
    if(start>end){
        return nullptr;
    }
    int mid=start+(end-start)/2;
    node* curr=new node(arr[mid]);
    curr->left=buildTree_Sorted(arr,start,mid-1);
    curr->right=buildTree_Sorted(arr,mid+1,end);
    return curr;
}

// -----------------------------    No. of Unique BST from n nodes     ----------------------------
vector<node*> generate_BST(int start, int end)
{
    vector<node*> list;
    if (start > end){
        list.push_back(NULL);
        return list;
    }

    for (int i = start; i <= end; i++){
        vector<node*> leftSubtree  = generate_BST(start, i - 1);        
        vector<node*> rightSubtree = generate_BST(i + 1, end);

        for (int j = 0; j < leftSubtree.size(); j++){
            node* left = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++){
                node* right = rightSubtree[k];
                node* curr = new node(i);
                curr->left = left;             
                curr->right = right;            
                list.push_back(curr);           
            }
        }
    }
    return list;
}

// -----------------------------    Recover Binary Tree     ----------------------------

//*         https://leetcode.com/problems/recover-binary-search-tree/

node* recover_tree(node* root){
    return NULL;
}

//  -------------------------    Insert and Delete in AVL Tree   -------------------------
// ! Incomplete
node* left_rotate(node* &root){
    node* left=root->left;
    root->left=left->right;
    left->right=root;
    return left;
}
node* right_rotate(node* & root){
    node* right=root->right;
    root->right=right->left;
    right->left=root;
    return right;   
}
node* avl_tree(node* root,int &height){
    if(!root)return nullptr;
    int lh,rh;
    node* left=avl_tree(root->left,lh);
    node* right=avl_tree(root->right,rh);
    if(abs(lh-rh)>1){
        if(lh>rh){
            if(root->val){}
        }
        else{
            if(root->val){}
        }
    } 
    height=1+max(lh,rh);
    return root;
    
}

int main(){

    node* root=new node(50);
    insertInBST(root,40);
    insertInBST(root,70);
    insertInBST(root,60);
    insertInBST(root,90);
    display(root);

    display(deleteInBST(root,50));

    vector<int> arr={7,5,4,6,8,9,8,12};
    node* tree=buildTree_preorder(arr);
    display(tree);

    vector<int> sorted={1,2,3,4,5,6,7};
    root=buildTree_Sorted(sorted,0,sorted.size()-1);
    display(root);

    cout<<"Is Tree is valid BST? "<<isValidBST(root)<<endl;
    

    vector<node*> trees=generate_BST(1,7);
    for(auto i:trees){
        display(i);
        cout<<endl<<endl<<endl;
    }
    
    return 0;

}