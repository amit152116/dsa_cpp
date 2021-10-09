#include<iostream>
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