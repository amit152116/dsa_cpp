#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){

    vector<int> arr= {1,5,6,2,9,8};
    priority_queue<int,vector<int>,greater<int>> st;

    for(auto i:arr){
        st.push(i);
    }

    int sum=0;
    int time=0;
    while(st.size()!=1){
        int first=st.top();
        st.pop();
        int second=st.top();
        st.pop();
        time=first+second;
        sum+=time;
        st.push(time);
    }
    cout<<sum<<endl;
    cout<<time<<endl;
    return 0;
}