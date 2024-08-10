#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int hashCode(string str){
    uint64_t p = 31;
    uint64_t mod = 1e9+9;
    uint64_t power = 1;
    uint64_t hash = 0;
    for(int i=0;i<str.size();i++){
        int val = str[i]-'a'+1;
        hash = (hash+val*power)%mod;
        power = (power*p)%mod;
    }
    return hash;
}

int main(){
    vector<string> arr = {"deshbhagat","amit","akhil","ajay","amit","vikas","ankit","nikhil","anki","nikhl","akhil","jay"}; 
    vector<pair<int,int>> hash;
    for(int i=0;i<arr.size();i++){
        hash.push_back({hashCode(arr[i]),i});
    }
    sort(hash.begin(),hash.end());
    for(auto it:hash){
        cout<<arr[it.second]<<endl;
    }
    return 0;
}