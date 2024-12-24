#include<bits/stdc++.h>

using namespace std;


struct TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        this->data = ch;
        this->isTerminal = false;

        for(int i=0;i<26;i++){
            this->children[i] = NULL;
        }
    }
};


void dfs(TrieNode* root){
    if(!root)return;

    printf("%c %d\n",root->data,root->isTerminal);

    for(int i=0;i<26;i++){
        dfs(root->children[i]);
    }
}

void insert(TrieNode* &root, string word){
    if(word.length()==0){
        root->isTerminal = true;
        return ;
    }

    int idx = word[0]-'a';
    TrieNode* child ;
    if(root->children[idx]!=nullptr){
        child = root->children[idx];
    }
    else{
        child = new TrieNode(word[0]);
        root->children[idx] = child;
    }
    insert(child, word.substr(1));


}

bool search(TrieNode* root, string word){
    
    if(word.length()==0)return root->isTerminal;
    if(!root)return false;
    int idx = word[0]-'a';

    return search(root->children[idx],word.substr(1));
    

}

void delete_word(TrieNode* &root, string word){

    if(word.length()==0){
        root->isTerminal = false;
        return;
    }
    if(!root)return;

    int idx = word[0]-'a';
    delete_word(root->children[idx],word.substr(1));

    return;

}


int main(){
    
    TrieNode* root = new TrieNode('\0');


    insert(root, "amit");
    insert(root, "kumar");
    insert(root, "akhil");
    insert(root,"akhilesh");
    dfs(root);

    cout<<search(root, "ajay");
    cout<<search(root, "amit");
    cout<<search(root, "kumar");
    cout<<search(root,"akhilesh");

    delete_word(root, "akhil");

    cout<<search(root, "akhil");



    return 0;
}