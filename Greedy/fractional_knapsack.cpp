#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){

    // {Weight,Value}
    vector<vector<int>> arr = {{7,21},{4,24},{6,12},{5,40},{6,30}};
    int max_weight = 20;
    priority_queue<pair<int,int>> st;

    for(auto i:arr){
        st.push({i[1]/i[0],i[0]});
    }
    int total = 0;
    while(max_weight && !st.empty()){
        int value=st.top().first;
        int wt = st.top().second;
        st.pop();
        if(max_weight>=wt){
            max_weight-=wt;
            total+=wt*value;
        }
        else{
            wt=max_weight;
            total+=wt*value;
            max_weight=0;
        }
    }
    cout<<total<<endl;
    return 0;
}