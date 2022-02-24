#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
// https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/
int main(){
    
    // To check if given no is power of 2
    int n=256;

    if((n&n-1)==0){
        cout<<"Given no is power of 2 ";
    }


    // All Possible Subset from Set using Bit manipulation

    vector<int> arr = {1,2,3,4};
    n=arr.size();

    for(int i=0;i<1<<n;i++){

        for( int j=0;j<n;j++){
            if(i &(1<<j)){
                cout<<arr[j]<<' ';
            }
        }
        cout<<endl;
    }

    // Find single unique element in k times repeating element

    arr={1,2,1,2,1,2,4,4,4,6};
    int k=3;
    n=arr.size();
    int no=0;
    for(int i=0;i<32;i++){
        int bits=0;
        for(int j=0;j<n;j++){
            if(arr[j]&(1<<i)){
                bits++;
            }
        }
        if(bits%3){
            no+=1<<i;
        }
    }
    cout<<no<<endl;
    return 0;
}