#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){

    vector<vector<int>> arr = {{10,20},{12,15},{20,30}};

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    for(auto i:arr){
        pq.push({i[1],i[0]});
    }
    int total=0;
    int event=0;
    while(!pq.empty()){
        int start=pq.top().second;
        int end=pq.top().first;
        cout<<start<<' '<<end<<endl;
        pq.pop();
        if(event<=start){
            total++;
            event=end;
        }
    }
    cout<<total<<endl;
    return 0;
}