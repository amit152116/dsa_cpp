#include<bits/stdc++.h>
#include<time.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int min_coin(int sum,vector<int>& coins,vector<int>& memo){
    if(sum==0){
        memo[sum] = 0;
        return 0;
    }
    if(memo[sum]!=-1){
        return memo[sum];
    }
    int ans = INT_MAX;
    for(auto it:coins){
        int subsum = sum-it;
        if(subsum<0)continue;
        ans = min(ans,1+min_coin(subsum,coins,memo));
    }
    memo[sum] = ans;

    return ans;
}

int main(){
    vector<int> coins = {1,3,43};
    int sum=5000;


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