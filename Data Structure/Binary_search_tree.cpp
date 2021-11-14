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
void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);
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

int main(){

    node* root=new node(4);
    insertBST(root,7);
    insertBST(root,3);
    insertBST(root,2);
    insertBST(root,5);
    insertBST(root,1);
    insertBST(root,6);
    
    inOrder(root);
    cout<< endl;

    preOrder(root);


    return 0;

}