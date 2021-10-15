#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    string a,b;
    cin>>t;
    while(t--)
    {
        cin>>a;
        cin>>b;
        int total=0;
        for(int i=0;i<a.size();i++)
        {
            for(int j=0;j<b.size();j++)
            {
                if(a[i]==b[j])
                {
                    total++;
                    a.erase(a.begin()+i);
                    b.erase(b.begin()+j);
                    i--;
                    j--;
                    break;
                }
            }
        }
        total=a.size()+b.size();
        cout << total << endl;
    }
    
}
