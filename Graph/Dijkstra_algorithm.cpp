#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
#define Graph vector<set<pair<int,int>>>

// Cons : 1. Doesn't work for Negative edge weight cycle .
//        2. For dense graphs, Not good algorithm. Because if E becomes V^2.
//           Time complexity O(V^3.logV). Floyd Warshall is good for dense graph.
// Dijkstra Algorithm is same as bfs. It can be used for directed and undirected graph.
//* Time Complexity : O((V+E)logV)

void dijkstra_algorithm(Graph graph,int n){

     // Source from where to measure the shortest distance
    int source=1;
    vector<int> dist(n,INT_MAX);
    dist[source]=0;
    set<pair<int,int>> st;
    // {weight,vertex}
    st.insert({0,source});
    int count=0;
    while(!st.empty()){
        auto x=*st.begin();
        int node=x.second;
        int min=x.first;
        st.erase(x);
        for(auto i:graph[node]){
            int child=i.first;
            int weight=i.second;
            count++;
            if(dist[child]>dist[node]+weight){
                if(dist[child]!=INT_MAX){  
                    st.erase({dist[child],child});
                }
                dist[child]=dist[node]+weight;
                st.insert({dist[child],child});
            }
        }
    }
    cout<<count<<endl;
    for(int i=1;i<n;i++){
        cout<<dist[i]<<' ';
    }
    return;
}
int main(){
    vector<vector<int>> edges={{5,1,2},{6,2,3},{2,4,3},{9,1,4},{5,3,5},{10,5,6},{7,6,7},{1,7,8},{1,8,5},{-3,6,8}};
    int m=edges.size();
    int n=9;
    Graph graph(n);
    for(int i=0;i<m;i++){
        int u=edges[i][1];
        int v=edges[i][2];
        int w=edges[i][0];
        // {vertex,weight}
        graph[u].insert({v,w});
    }

    dijkstra_algorithm(graph,n); 
    


    return 0;
}