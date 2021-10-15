#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;

    node(int val){
        this->data=val;
        next=NULL;
    }
    void insertAtTail(int val){
        node* n =new node(val);
        node* temp=this;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
    }
    void displayList(){
        node* temp =this;
        while(temp!=NULL){
            cout<< temp->data <<" -> ";
            temp=temp->next;
        }
        cout<< "NULL\n";
    }
    node* insertAtHead(int val){
        node* n =new node(val);
        n->next=this;
        return n;
    }
    bool search(int key){
        node* temp=this;
        while (temp!=NULL){
            if(temp->data==key){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }
    
int length(){
    node* head=this;
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}



};