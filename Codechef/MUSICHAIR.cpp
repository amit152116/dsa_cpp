#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    n--;
	    unordered_set<int> st;
	   
	    for(int i=1;i*i<=n;i++){
	        if(n%i==0){
	            st.insert(n/i);
	            st.insert(i);
	        }
	    }
	    
        cout<<st.size()<<endl;
	}
	return 0;
}