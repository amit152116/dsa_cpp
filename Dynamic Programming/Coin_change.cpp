#include<bits/stdc++.h>
#include<time.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int min_coin(int sum,vector<int>& coins,vector<int>& dp){
    if(sum==0){
        dp[sum] = 0;
        return 0;
    }
    if(sum<0){
        return INT_MAX;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    int mini = INT_MAX;
    for(auto it:coins){
        int ans = min_coin(sum-it,coins,dp);
        if(ans!=INT_MAX){
            mini = min(mini,1+ans);
        }
    }
    if(mini!=INT_MAX)dp[sum] = mini;

    return mini;
}

int main(){
    vector<int> coins = {3,43};
    int sum=100;


    vector<int> arr(sum+1,-1);

    clock_t start,end;
    start = clock();
    int ans = min_coin(sum,coins,arr);
    end = clock();
    
    double time_taken = double(end-start)/ double(CLOCKS_PER_SEC);

    for(int i=0;i<arr.size();i++){
        cout<<i<<" - "<<arr[i]<<endl;
    }

    cout<<time_taken<<endl;

    return 0;
}