#include<bits/stdc++.h>
using namespace std;

int main(){
    srand(time(0));
    vector<int> arr(50);
    int n=arr.size();
    // Generating the Random numbers in range(0,9)
    for(int i=0;i<n;i++){
        arr[i]=rand()%10;
    }
    // count vector to store the repetition of the number
    vector<int> count(10,0);
    for(auto i:arr){
        count[i]++;
    }
    // add the prev element to curr index 
    for(int i=1;i<count.size();i++){
        count[i]+=count[i-1];
    }
    // Sorting
    vector<int> result(n);
    for(int i=n-1;i>=0;i--){
        result[--count[arr[i]]]=arr[i];
    }
    for(auto i:result){
        cout<<i<<' ';
    }
    return 0;
}