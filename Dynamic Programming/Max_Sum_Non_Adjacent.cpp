#include<bits/stdc++.h>

using namespace std;

namespace my
{
    int count = 0;
} // namespace counter

// https://leetcode.com/problems/maximum-sum-of-subsequence-with-non-adjacent-elements/description/

// -----------------------------------------  Recursion ----------------------------------------------------
int max_sum(vector<int> arr, int idx, int n){
    if(idx>=n){
        return 0;
    }

    int maxi = INT_MIN;

    for(int i=idx;i<n;i++){
        int ans = max_sum(arr,i+2,n);
        maxi = max(maxi, ans+arr[i]);
    }
    my::count++;
    return maxi;
}
// ----------------------------------------   Memoization  ------------------------------------------------
int max_sum_memo(vector<int> arr, int idx, int n, vector<int>& dp){

    if(idx>=n){
        return 0;
    }
    my::count++;
    if(dp[idx]!=-1)return dp[idx];

    int maxi = INT_MIN;

    for(int i=idx;i<n;i++){
        int ans = max_sum_memo(arr, i+2, n, dp);
        maxi = max(maxi, ans+arr[i]);
    }
    dp[idx] = maxi;
    return maxi;

}

int max_sum2(vector<int> arr,int n, vector<int>& dp){

    if(n<0)return 0;
    if(n==0)return arr[0];my::count++;
    if(dp[n]!=-1)return dp[n];

    int incl = max_sum2(arr, n-2, dp) + arr[n];
    int excl = max_sum2(arr, n-1, dp) + 0;

    dp[n] =  max(incl,excl);
    
    return dp[n];
}

// ------------------------------------------   Tabulation  -------------------------------------------------
int max_sum_tab(vector<int> arr, int n){
    my::count = 0;
    vector<int> dp = vector(n,0);
    dp[0] = arr[0];
    dp[1] = arr[1];

    for(int i=2;i<n;i++){
        for(int j = i-2;j>=0;j--){
            dp[i] = max(dp[j]+arr[i], dp[i] );
            my::count++;
        }
    }   
    cout<<"No. of loops :"<<my::count<<endl;
    return max(dp[n-1],dp[n-2]);
}

int max_sum_tab2(vector<int> arr, int n){
    my::count = 0;
    vector<int> dp = vector(n,0);
    dp[0] = arr[0];

    for(int i=1;i<n;i++){
        int incl = dp[i-2]+arr[i];
        int excl = dp[i-1];

        dp[i] = max(incl,excl);

        my::count++;
    }
     cout<<"No. of loops :"<<my::count<<endl;
    return dp[n-1];
}
int main(){
    vector<int> arr = {3,4};
    vector<int> arr2 = {82, 95, 75, 60, 113, 82, 85, 93, 87, 105, 76, 70, 60, 125, 98, 73, 120, 55, 80, 69, 115, 67, 78, 96, 89, 106};
    int ans = max_sum(arr,0,arr.size());
    cout<<ans<<endl;
    cout<<"no. of recursion call : "<<my::count<<endl;

    my::count = 0;


    // -------------------------
    vector<int> dp = vector(arr.size(),-1);

    cout<<max_sum_memo(arr, 0, arr.size(),dp)<<endl;
    cout<<"no. of recursion call : "<<my::count<<endl;

    my::count = 0;

    vector<int> dp2 = vector(arr.size(),-1);

    cout<<max_sum2(arr, arr.size()-1, dp2)<<endl;
    cout<<"no. of recursion call : "<<my::count<<endl;

    cout<<max_sum_tab(arr, arr.size())<<endl;

    cout<<max_sum_tab2(arr,arr.size())<<endl;
    
    return 0;
}