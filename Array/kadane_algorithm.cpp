#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int kadane(vector<int> arr,int n){
    int sum=0;
    int maxSum=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(sum>maxSum){
            maxSum=sum;
        }
        if(sum<0){
            sum=0;
        }
    }
    return maxSum;
}

void circular_kadane(vector<int> arr,int n){

    int nonWrapingSum=kadane(arr,n);
    int totalSum=0;
    for(int i=0;i<n;i++){
        totalSum+=arr[i];
        arr[i]=-arr[i];
    };
    int wrapingSum = totalSum + kadane(arr,n);
    int maxSum=max(wrapingSum,nonWrapingSum);
    cout<<"MAX Circular Sum Subarray "<<maxSum<<endl;
}

int main(){
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    int n=arr.size();
    cout<<"Max Sum Subarray"<<kadane(arr,n)<<endl<<endl;

    circular_kadane(arr,n);
    return 0;
}