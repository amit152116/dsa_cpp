#include<iostream>
#include<stack>
#include"Linked_list.cpp"

/*      
*       We can implement the stack in array also but
*       array size if not dynamic. So, we have fixed size .
*/

using namespace std;

class Stack{
    private:
    node* head;

    public:
    stack(){
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
*    -----------------------------       Reversing the String        ---------------------------
*/
void reverse_Sentence(string s){
    stack<string> result;
    for(int x=0;x<s.length();x++){
        string word="";
         while(s[x]!=' ' && x<s.length()){
             word+=s[x];
             x++;
         }
         result.push(word);
    }
    while(!result.empty()){
        cout<<result.top()<<" ";
        result.pop();
    }
    cout<<"\n\n";
}

/*
*    -----------------------------       Reverse the Stack        ---------------------------
*/

void insert_At_Bottom(stack<int>& st,int data){
    if(st.empty()){
        st.push(data);
        return;
    }
    int topelement = st.top();
    st.pop();
    insert_At_Bottom(st,data);
    st.push(topelement); 
}
void reverse_Stack(stack<int>& st){
    if(st.empty()){
        return;
    }
    int data=st.top();
    st.pop();
    reverse_Stack(st);
    insert_At_Bottom(st,data);   
}

void print_Stack(stack<int> st){
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"\n\n";
}
int main(){
    string s="Hello, How are you?";
    reverse_Sentence(s);

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    print_Stack(st);
    reverse_Stack(st);
    cout<<"After reversing the Stack: "<<endl;
    print_Stack(st);


    return 0;

}