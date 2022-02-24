#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;


// Min no. of squares whose sum equal to given No.
vector<int> arr;
int MinSquare(int x){

    if(arr[x]!=INT_MAX){
        return arr[x];
    }

    for(int i=1;i*i<=x;i++){
        arr[x]=min(arr[x],1+MinSquare(x-i*i));
    }
    return arr[x];
}
int main(){
    int x=51;
    arr = vector<int>(x+1,INT_MAX);
    arr[0]=0;
    arr[1]=1;
    arr[2]=2;
    arr[3]=3;
    // Recursive Approach
    cout<<MinSquare(x)<<endl;

    // Iterative Approach
    for(int i=0;i*i<=x;i++){

        for(int j=0;i*i+j<=x;j++){
            arr[i*i+j]=min(arr[i*i+j],1+arr[j]);
        }
    }
    cout<<arr[x]<<endl;
    

    return 0;
}