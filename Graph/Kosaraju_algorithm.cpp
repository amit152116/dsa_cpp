#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
map<int,set<int>> graph,reverse_graph;


//* Time Complexity : O(V+E)
void dfs(vector<bool>& visit,stack<int>& st,int node){
    visit[node]=true;

    for(auto i:graph[node]){
        if(!visit[i])dfs(visit,st,i);
    }
    st.push(node);
}

void kosaraju(int node,vector<bool>& visit){
    visit[node]=true;
    for(auto i:reverse_graph[node]){
        if(!visit[i])kosaraju(i,visit);
    }
    return;
}
int main(){
    vector<vector<int>> edges={{0,1},{1,2},{2,0},{3,0},{3,2},{3,4},{4,5},{5,0},{5,3},{6,4},{6,7},{7,5},{7,6}};
    int count=0;
    int n=8;
    for(auto i:edges){
        int u=i[0];
        int v=i[1];

        graph[u].insert(v);
        reverse_graph[v].insert(u);
    }

    vector<bool> visit(n);
    stack<int> st;
    for(int i=0;i<n;i++){
        if(!visit[i]){
            dfs(visit,st,i);
        }
    }
    visit=vector<bool>(n,false);
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visit[node]){
            count++;
            kosaraju(node,visit);
        }
    }
    cout<<"No of Strongly Connected Components (SCC) : "<<count<<endl;
   
    return 0;
}