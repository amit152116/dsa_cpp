#include<bits/stdc++.h>
#include<time.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

// ----------------------------------------------       Memoization     ----------------------------------------------
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

// -----------------------------------------------      Tabulation      ------------------------------------------------
int min_coin_tab(int sum, vector<int> coins){

    vector<int> dp = vector(sum+1,INT_MAX);
    dp[0] = 0;
    for(int i = 1;i<=sum;i++){
        for(int j =0;j<coins.size();j++){
            if(i-coins[j]<0 || dp[i-coins[j]]==INT_MAX)continue;
            dp[i] = min(dp[i],1+dp[i-coins[j]]);
        }

    }
    return dp[sum];
}
int main(){
    vector<int> coins = {3,43};
    int sum=100;

    vector<int> arr(sum+1,-1);
    int ans = min_coin(sum,coins,arr);
  
    cout<<ans<<endl;



    cout<<min_coin_tab(sum,coins)<<endl;
 

    return 0;
}