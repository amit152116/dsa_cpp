#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
#define INF 99999

// It is only used for directed graph.
//* Time Complexity : O(V^3)
int main(){
    fast;
    vector<vector<int>> graph = { { 0, 5, INF, 10 },
                                { INF, 0, 3, INF },
                                { INF, INF, 0, 1 },
                                { INF, 2, INF, 0 } };
    int V=graph.size();
    vector<vector<int>> dist=graph;
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][j]>(dist[i][k]+dist[k][j])){
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    // To detect negative cycle:
    // we will check its distance from itself, if it is negative then negative cycle present.
    bool cycle=false;
    for(int i=0;i<V;i++){
        if(graph[i][i]<0){
            cycle=true;
            break;
        }
    }
    if(cycle)cout<<"Negative Cycle present."<<endl;
    for(auto i:dist){
        for(auto j:i){
            cout<<j<<' ';
        }
        cout<<endl;
    }
}