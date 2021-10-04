#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string st;
        cin>>st;
        vector<string> vect;
        for (int j=0;j<st.size();j++)
        {
            for(int k=1;k<=st.size();k++)
            {
                vect.insert(vect.end(),st.begin()+j,st.begin()+k);
            }
        }
        for(auto i=vect.begin();i!=vect.end();i++)
        {
        	cout << *i <<endl;
        	
		}
    }
    
}
