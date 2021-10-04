#include<iostream>
using namespace std;

struct node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

node* insertBST(node* root, int val){
    if(root==NULL){
        return new node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}
void inOrder(node* root){
    if (root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
    
}
node* searchInBST(node* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data<key){
        return searchInBST(root->left,key);
    }
    return searchInBST(root->right,key);
}

node* deleteInBST(node* root,int key){
    if(root->data<key){
        root->left=deleteInBST(root->left,key);
    }
    else if(root->data>key){
        root->right=deleteInBST(root->right,key);
    }
    else{
    }
}

int main(){

    node* root=new node(5);
    insertBST(root,7);
    insertBST(root,3);
    insertBST(root,2);
    insertBST(root,4);
    insertBST(root,1);
    
    inOrder(root);
    cout<< endl;

    node* searchKey=searchInBST(root,5);
    cout<<searchKey->data;


    return 0;

}