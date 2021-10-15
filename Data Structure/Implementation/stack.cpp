#include<iostream>
#include<queue>
#include"linked_list.cpp"
/*
*    -----------------------------    Implementing Stack using Linked List      ---------------------------
*/
class Stack{
    private:
    node* head;

    public:
    Stack(){
        head=NULL;
    }
    void push(int x){
        node* temp=new node(x);
        temp->next=head;
        head=temp;
    }
    int pop(){
        if(head==NULL){
            cout<<"No element remaining.\n";
            return -1;
        }
        int res=head->data;
        node* todel=head;
        head=head->next;
        delete todel;
        return res;
    }
    bool is_empty(){
        return head==NULL;
    }
    int top(){
        if(head==NULL){
            cout<<"NO element";
            return -1;
        }
        return head->data;
    }
    
};

/*
*    -----------------------------    Implementing Stack using Queue     ---------------------------
*       There are two methods for this :
*       1. Making the Push method costly
*       2. Making the Pop method costly

todo       We can also implement stack using one queue only -> https://leetcode.com/problems/implement-stack-using-queues/
*/
class stackQueue{
    private:
    queue<int> qu1,qu2;
    public:
    stackQueue(){
    }
    void push(int val){
        qu2.push(val);
        while(!qu1.empty()){
            qu2.push(qu1.front());
            qu1.pop();
        }
        queue<int> temp=qu1;
        qu1=qu2;
        qu2=temp;

    }
    void pop(){
        if(qu1.empty()){
            cout<<"Stack is empty "<<endl;
        }
        qu1.pop();
    }
};