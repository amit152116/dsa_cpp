#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

// Question : Divide the array into n/2 & Find max and 
//              min of difference between two array.

int main(){
    fast;

    vector<int> arr = {2,-1,5,10,20,-3};
    int n=arr.size();
    sort(arr.begin(),arr.end());
    
    int max=0,min=0;

    for(int i=0;i<n/2;i++){

        max+=(arr[i+n/2]-arr[i]);
        min+=(arr[2*i+1]-arr[2*i]);
    }
    cout<<"MAX Differnece : "<<max<<endl;
    cout<<"MIN Diffrence : "<<min<<endl;
    return 0;
}