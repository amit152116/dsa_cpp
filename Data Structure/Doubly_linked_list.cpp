#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
    void insertAtTail(int val){
        node* n = new node(val);
        node* temp =this;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=n;
        n->prev=temp;
    }
    void display(){
        node* temp=this;
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL\n\n";
    }
    node* insertAtHead(int val){
        node* n=new node(val);
        n->next=this;
        this->prev=n;
        return n;
    }
};

void deleteAtHead(node* &head){
    node* todelete=head;
     head=head->next;
     head->prev=NULL;
     delete todelete;
}

void delete_node(node* & head,int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }
    node* temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
    temp->next->prev=temp->prev;
    }

    delete temp;

}
int length(node* head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}


int main(){
    node* head =new node(5);
    head->insertAtTail(6);
    head->insertAtTail(7);
    head->insertAtTail(8);
    head->insertAtTail(9);
    head->insertAtTail(10);
    head->display();

    head=head->insertAtHead(4);
    head->display();

    delete_node(head,4);
    cout<<"After Deleting Node at position 4 :\n";
    head->display();

    delete_node(head,1);
    cout<<"After Deleting Node at position 1 :\n";
    head->display();

   
}