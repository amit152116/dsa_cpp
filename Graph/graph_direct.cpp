#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
#define Graph map<int,set<int>>
#define Visit unordered_map<int,bool>

// -----------------------------    BFS in Graph    ----------------------------
void bfs(Graph graph){
    fast;
    cout<<endl<<" BFS : ";
    Visit visited;
    queue<int> st;
    for(int item=0;item<graph.size();item++){
        if(visited[item]==false){
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
        }
    }
    
    return ;
}


// -----------------------------    DFS in Graph    ----------------------------
void dfs_util(Graph graph,int item,Visit& visited){
    cout<<item<<' ';
    visited[item]=true;
    for(auto i:graph[item]){
        if(!visited[i]){
            dfs_util(graph,i,visited);   
        }
    }
    return;
}

void dfs(Graph graph,Visit visited){
    for(int i=0;i<graph.size();i++){
        if(visited[i]==false){
            dfs_util(graph,i,visited);
        }
    }
    return;
}


// -----------------------------    Topological Sort in DAG   ----------------------------
    // Topological sort can also be implemented using indegree of node and queue(Kahn's Algorithm).

void topological_dfs(Graph graph,int node,stack<int>& st,Visit &visited){
    visited[node] = true;
    for(auto i:graph[node]){
        if(!visited[i]){
            topological_dfs(graph,i,st,visited);
        }
    }
    st.push(node);
}
void topological_sort(Graph graph){
    cout<<" Topological Sort :";
    stack<int> st;
    Visit visited;
    for(int i=0;i<graph.size();i++){
        if(visited[i]==false){
            topological_dfs(graph,i,st,visited);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<' ';
        st.pop();
    }
    cout<<endl;
    return;
}
// --------------------------------------- [Indegree Sorting] [Kahn's Algorithms] ------------------------------
// It is implemented using BFS
void topological_sort_indegree(Graph graph){

    vector<int> degree(graph.size(),0);
    for(auto it:graph){
        for(auto ele:it.second)
        degree[ele]++;
    }

    queue<int> q;
    for(int i=0;i<graph.size();i++){
        if(degree[i]==0)q.push(i);
    }
    vector<int> sorted;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        sorted.push_back(node);

        for(auto it:graph[node]){
            degree[it]--;
            if(degree[it]==0)q.push(it);
        }
    }
    cout<<"Topological Sort: ";
    for(auto it:sorted){
        cout<<it<<' ';
    }
    cout<<endl;

    
}


// -----------------------------    Cycle detection in Graph    ----------------------------
bool cycle_detect(Graph graph,Visit& visited,int node,vector<bool>& stack){
    stack[node]=true;

    visited[node]=true; 
    for(auto i:graph[node]){
        if(stack[i])return true;
        if(!visited[i] && cycle_detect(graph,visited,i,stack)){
            return true;
        }
    }
    
    stack[node]=false;
    return false;

}

// ----------------------------------------   Eulerian Path  ---------------------------------------
void eulerian_path(){

}


// ---------------------------------------   Eulerian Circuit   --------------------------------------
void eulerian_circuit(){

}



int main(){
    int arr1[][2]={{0,1},{0,6},{0,5},{1,2},{1,4},{2,6},{3,2},{5,3},{4,3}};
    int m=sizeof(arr1)/sizeof(arr1[0]);
    int n=7;
    Graph graph;
    for(int i=0;i<m;i++){
        int x=arr1[i][0];
        int y=arr1[i][1];
        graph[x].insert(y);
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
    topological_sort(graph);
    cout<<endl;
    topological_sort_indegree(graph);

// ------------------        Graph 2      -----------------------
    int arr2[][2]={{2,0},{2,1},{1,3},{0,3},{4,0},{4,3},{4,5},{3,7},{3,6},{6,8},{7,8},{7,9},{5,10},{5,9},{10,9},{9,12},{9,11},{8,11}};
    m=sizeof(arr2)/sizeof(arr2[0]);
    n=13;
    graph.clear();
    for(int i=0;i<m;i++){
        int x=arr2[i][0];
        int y=arr2[i][1];
        graph[x].insert(y);
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
    topological_sort(graph);
    topological_sort_indegree(graph);
    vector<bool> stack(n,false);
    visit2.clear();
    for(int i=0;i<n;i++){
        if(!visit2[i] && cycle_detect(graph,visit2,i,stack)){
            cout<<" Cycle Detected "<<endl;
            break;
        }
    }

    return 0;
}