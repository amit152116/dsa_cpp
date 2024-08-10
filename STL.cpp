#include<bits/stdc++.h>
#define fast   ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
    complex<float> num (5,7);
    cout<<abs(num)<<endl;

    multimap<string,string> mp;
    mp.insert("japan","tokyo");
    mp.insert("india","delhi");
    mp.insert("japan","hiroshima");
    mp.insert("india","abohar");

    for(auto it:mp){
        cout<<it.first<<endl<<it.second<<endl;
    }
    return 0;
}