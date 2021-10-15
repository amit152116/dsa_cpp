#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    print_queue(st);
    return 0;
}