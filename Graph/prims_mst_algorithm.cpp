#include<bits/stdc++.h>
#include"../Data Structure/disjoint_set.cpp"
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;


map<int,set<pair<int,int>>> graph;

int prims_MST(){
    vector<int> parent(100);
    vector<int> 
}

int main(){
    // {weight,vertex1,vertex2}
    vector<vector<int>> edges={{5,1,2},{6,2,3},{2,4,3},{9,1,4},{5,3,5},{10,5,6},{7,6,7},{1,7,8},{1,8,5}};

    for(auto i:edges){
        int w=i[0];
        int u=i[1];
        int v=i[2];

        graph[u].insert({v,w});
        graph[v].insert({u,w});
    }

    for(auto i:graph){
        cout<<i.first<<" -> ";
        for(auto j:i.second){
            cout<<j.first<<' '<<j.second<<"\t";
        }
        cout<<endl;
    }

    cout<<"Cost of MST : "<<prims_MST()<<endl;
    return 0;
}