#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;


/*
You are trapped in a 3D dungeon and need to find the quickest way out! 
The dungeon is composed of unit cubes which may or may not be filled with rock. 
It takes one minute to move one unit north, south, east, west, up or down. You 
cannot move diagonally and the maze is surrounded by solid rock on all sides.


*/
int main(){
    // In grid, path whose value is 1 is possible path.
    vector<vector<int>> grid ={
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
        { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
        { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
        { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
        { 1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }
    };
    int n=grid.size();
    int m=grid[0].size();
    // Direction vector for north, west, south and east
    vector<int> dr={1,-1,0,0};
    vector<int> dc={0,0,1,-1};

    // Source and Destination
    int sx=0,sy=0;
    int dx=8,dy=1;

    vector<vector<bool>> visit(n,vector<bool>(m));

    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m));
    int level=0;
    bool reach=false;
    queue<pair<int,int>> st;
    st.push({sx,sy});
    visit[sx][sy]=true;

    while(!st.empty()){
        int size=st.size();

        while(size--){
            int curx=st.front().first;
            int cury=st.front().second;
            st.pop();
            if(curx==dx && cury==dy){
                reach=true;
                break;
            }

            for(int i=0;i<4;i++){
                int nextx=curx+dr[i];
                int nexty=cury+dc[i];   
                
                if(nextx<0 || nexty<0 )continue;
                if(nextx>=n ||nexty>=m)continue;
                
                if(grid[nextx][nexty]==0)continue;
                if(visit[nextx][nexty])continue;
                
                parent[nextx][nexty]={curx,cury};
                
                st.push({nextx,nexty});
                visit[nextx][nexty]=true;

            }
        }
        if(reach)break;
        level++;
    }
    if(reach==true){
        cout<<"Steps :"<<level<<endl;
        vector<pair<int,int>> st;
        st.push_back({dx,dy});

        while(true){
            auto node = parent[dx][dy];
            dx=node.first;
            dy=node.second;
            st.push_back({dx,dy});
            if(dx==sx && dy==sy)break;
        }
        sort(st.begin(),st.end());
        int row=0,col=0;
        for(auto i:st){
            int x=i.first;
            int y=i.second;
            if(row!=x){
                cout<<endl;
                row=x;
                col=0;
            }
            int diff=y-col;
            col=y;
            while(diff>0){
                cout<<"\t";
                diff--;
            }
            printf("(%d,%d)",x,y);
        }
        
    }
    else{
        cout<<"Not possible"<<endl;
    }
    

    // for(auto i: parent){
    //     for(auto j:i){
    //         cout<<j.first<<' '<<j.second<<"\t";
    //     }
    //     cout<<endl;
    // }

    return 0;
    
}