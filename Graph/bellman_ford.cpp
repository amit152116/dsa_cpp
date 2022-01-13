#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

// It can be used for directed and undirected graph.
// It can handle negative weight as long as there is no negative cycle.
// * Time complexity : O(V.E)
int main(){
     // {weight,vertex1,vertex2}
    vector<vector<int>> edges={{5,1,2},{6,2,3},{2,4,3},{9,1,4},{5,3,5},{10,5,6},{7,6,7},{1,7,8},{1,8,5},{-3,6,8}};
    int n=9;
    vector<int> dist(n,INT_MAX);
    int source=1;
    dist[source]=0;
    
    for(int j=0;j<n-1;j++){
        for(auto i:edges){
            int w=i[0];
            int u=i[1];
            int v=i[2];
            if(dist[u]!=INT_MAX){
                dist[v]=min(dist[v],dist[u]+w);
            }
        }
    }
    // To check for negative cycle iterate again all edges &
    // If any relaxation found then, it has negative cycle.

    bool cycle=false;
    for(int j=0;j<n-1;j++){
        for(auto i:edges){
            int w=i[0];
            int u=i[1];
            int v=i[2];
            if(dist[u]+w<dist[v]){
                cycle=true;
                dist[v]=INT_MIN;
            }
        }
    }
    if(cycle)cout<<"Negative Cycle present."<<endl;
    for(int i=1;i<n;i++){
        cout<<dist[i]<<' ';
    }
    return 0;
}