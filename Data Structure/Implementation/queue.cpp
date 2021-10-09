#include<iostream>
#include"linked_list.cpp"
using namespace std;

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
            front=front->next;
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