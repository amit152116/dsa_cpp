#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
map<int,set<int>> graph;


// Using DFS
//* Time Complexity : O(V+E)

void tarjan(vector<bool> &visit,vector<int> &low_link, stack<int> &st,vector<bool>& onStack ,int node,int &count){
    st.push(node);
    visit[node]=true;
    low_link[node]=node;
    onStack[node]=true;
    for(auto i:graph[node]){
        if(!visit[i]){
            tarjan(visit,low_link,st,onStack,i,count);
        }
        if(onStack[i]){
            low_link[node]=min(low_link[node],low_link[i]);
        }
    }

    if(low_link[node]==node){
        while(!st.empty()){
            int curr=st.top();
            st.pop();
            onStack[curr]=false;
            if(curr==node)break;
        }
        count++;
    }
    return;
}

int main(){
    vector<vector<int>> edges={{0,1},{1,2},{2,0},{3,0},{3,2},{3,4},{4,5},{5,0},{5,3},{6,4},{6,7},{7,5},{7,6}};

    int n=8;
    for(auto i:edges){
        int u=i[0];
        int v=i[1];

        graph[u].insert(v);
    }
    vector<bool> visit(n);
    vector<int> low_link(n);
    stack<int> st;
    vector<bool> onStack(n);
    int count=0;
    for(int i=0;i<n;i++){
        if(!visit[i]){
            tarjan(visit,low_link,st,onStack,i,count);
        }
    }
    cout<<"No of Strongly Connected Components (SCC) : "<<count<<endl;
    return 0;
}