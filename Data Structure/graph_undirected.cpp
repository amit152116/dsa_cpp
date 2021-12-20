#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
#define Graph map<int,set<int>>
#define Visit unordered_map<int,bool>


// -----------------------------    BFS in Graph    ----------------------------
void bfs(Graph graph,int item=0){
    
    cout<<endl<<" BFS :";
    Visit visited;
    queue<int> st;
    st.push(item);
    visited[item]=true;
    while(!st.empty()){
        int i=st.front();
        st.pop();
        cout<<i<<' ';
        for(auto j:graph[i]){
            if(visited[j]==false){
                visited[j]=true;
                st.push(j);
            }
        }
    }
    return ;
}


// -----------------------------    DFS in Graph    ----------------------------
void dfs(Graph graph,Visit &visited,int item=0){
    cout<<item<<' ';
    visited[item]=true;
    for(auto i:graph[item]){
        if(!visited[i]){
            dfs(graph,visited,i);   
        }
    }
    return;
}


// -----------------------------    Cycle detection in Graph    ----------------------------
bool cycle_detect(Graph graph,Visit& visited,int node,int parent){
    visited[node]=true;
    for(auto i:graph[node]){
        if(i!=parent){
            if(visited[i]){
                return true;
            }
            else if(cycle_detect(graph,visited,i,node)){
                return true;
            }
        }
    }
    return false;

}

// -----------------------------    Connected Graph    ----------------------------

int connected_graph(Graph graph,Visit& visited,int node){
    int x=1;
    visited[node]=true;
    for(auto i:graph[node]){
        if(!visited[i]){
            x+=connected_graph(graph,visited,i);
        }
    }
    return x;
}


// -----------------------------    Bipartite Graph    ----------------------------

bool isBipartite_Graph(Graph graph,Visit& visited,int node,vector<int>& set,int color){
    if(set[node]!=-1 and set[node]!=color){
        return false;
    }
    set[node] = color;
    if(visited[node]){
        return true;
    }
    visited[node] = true;
    for(auto i:graph[node]){
        if(!isBipartite_Graph(graph,visited,i,set,color^1)){
            return false;
        }
    }
    return true;

}


int main(){
    int arr1[][2]={{0,1},{0,6},{1,2},{1,4},{2,6},{3,2},{5,3},{4,3}};
    int m=sizeof(arr1)/sizeof(arr1[0]);
    int n=7;
    Graph graph;
    for(int i=0;i<m;i++){
        int x=arr1[i][0];
        int y=arr1[i][1];
        graph[x].insert(y);
        graph[y].insert(x);
    }
    cout<<endl<<"Graph 1 : "<<endl;
    for(auto i:graph){
        cout<<i.first<<"-> ";
        for(auto j:i.second){
            cout<<j<<' ';
        }
        cout<<endl;
    }
    bfs(graph);
    cout<<endl<<" DFS :";
    Visit visit1;
    dfs(graph,visit1);
    cout<<endl;


    vector<int> arr;
    visit1.clear();
    for(int i=0;i<n;i++){
        if(!visit1[i]){
            arr.push_back(connected_graph(graph,visit1,i));
        }
    }
    cout<<" Connected Part :";
    for(auto i:arr){
        cout<<i<<' ';
    }
    cout<<endl;


    vector<int> set(n,-1);
    visit1.clear();
    for(int i=0;i<n;i++){
        if(!visit1[i]){
            if(!isBipartite_Graph(graph,visit1,i,set,0)){
                cout<<"Graph is not Bipartite"<<endl;
                break;
            }
        }
    }
    cout<<"Color of Graph :";
    for(auto i:set){
        cout<<i<<' ';
    }
    cout<<endl;
   


// ------------------        Graph 2      -----------------------
    
    int arr2[][2]={{2,0},{2,1},{1,3},{0,3},{4,0},{4,3},{4,5},{3,7},{3,6},{6,8},{7,8},{7,9},{5,10},{5,9},{10,9},{9,12},{9,11},{8,11}};
    m=sizeof(arr2)/sizeof(arr2[0]);
    n=13;
    graph.clear();
    for(int i=0;i<m;i++){
        int x=arr2[i][0];
        int y=arr2[i][1];
        graph[x].insert(y);
        graph[y].insert(x);
    }
    cout<<endl<<"Graph 2 : "<<endl;
    for(auto i:graph){
        cout<<i.first<<"-> ";
        for(auto j:i.second){
            cout<<j<<' ';
        }
        cout<<endl;
    } 
    
    bfs(graph);
    cout<<endl<<" DFS :";
    Visit visit2;
    dfs(graph,visit2);
    cout<<endl;
    visit2.clear();
    for(int i=0;i<n;i++){
        if(!visit2[i] && cycle_detect(graph,visit2,i,-1)){
            cout<<"Cycle Detected "<<endl;
            break;
        }
    }

    vector<int> color_set(n,-1);
    visit2.clear();
    for(int i=0;i<n;i++){
        if(!visit2[i] && !isBipartite_Graph(graph,visit2,i,color_set,0)){
            cout<<"Not Bipartite Graph"<<endl;
            break;
        }
    }
    

    
}