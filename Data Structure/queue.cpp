#include<bits/stdc++.h>
using namespace std;

struct comparator{
    bool operator()(const int a,const int b){
        return a>b;
    }
};

int main(){
    
    priority_queue<int,vector<int>, comparator> q;
    q.push(5);
    q.push(4);
    q.push(9);
    cout<<q.top()<<endl;
    q.pop();
    cout<<q.top();

    stack<int> st;
    st.push(2);
    st.push(3);

    for(auto i:st){
        cout<<i<<endl;
    }
    return 0;
}