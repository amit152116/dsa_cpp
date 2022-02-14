#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    int sum=0;
    int maxSum=0;
    int start=0,end=0;
    int n=arr.size();

    for(int i=0;i<n;i++){
        sum+=arr[i];

        if(sum>maxSum){
            end=i;
            maxSum=sum;
        }
        if(sum<0){
            sum=0;
            start=i+1;
        }
    }
    cout<<"Max Sum Subarray : "<<maxSum<<endl;
    for(int i=start;i<=end;i++){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
    return 0;
}