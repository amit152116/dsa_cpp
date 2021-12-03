#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int catalan(int n){
    if(n<=1){
        return 1;
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=catalan(i)*catalan(n-i-1);
    }
    return ans;
}
int catalan2(int n){
    vector<int> ans(n+1,0);
    ans[0]=1;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            ans[i]+=ans[j]*ans[i-j-1];
        }
        cout<<ans[i]<<endl;
    }
    return ans[n];

}
int main(){
    int n=15;
    cout<<catalan(n)<<endl;
    catalan2(n);
    return 0;
}