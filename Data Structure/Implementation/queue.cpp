#include<iostream>
#include<stack>
#include"linked_list.cpp"
using namespace std;

/*
*    -----------------------------    Implementing Queue using Linked List      ---------------------------
*/
class queue{
    private:
    node* front;
    node* back;
    public:
    queue(){
        front=NULL;
        back=NULL;
    }
    void push(int val){
        
        node* temp= new node(val);
        if(front){
            back->next=temp;
            back=temp;
        }
        else{
            front=temp;
            back=temp;
        }
    }
    void pop(){
        if(front){
            node* toDelete front;
            front=front->next;
            delete toDelete;
        }
        else{
            back=NULL;
            cout<<"Queue is empty";
        }
    }
    bool empty(){
        if(!front){
            return true;
        }
        else{
            return false;
        }
    }
    int front_element(){
        return front->data;
    }
    void print(){
        node* temp =front;
        while(temp){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int back_element(){
        return back->data;
    }
};


/*
*    -----------------------------    Implementing Queue using Stack      ---------------------------
*/
class queueStack{
    private:
    stack<int> st1;
    stack<int> st2;
    public:
    queueStack(){

    }
    void push(int val){
        st1.push(val);
    }
    void pop(){
        if(st1.empty() && st2.empty()){
            cout<<"Queue is empty"<<end;
            return;
        }
        peek();
        st2.top();
    }
    int peek(){
         if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    bool empty(){
        if(st1.empty()&& st2.empty()){
            return true;
        }
        return false;
    }
};