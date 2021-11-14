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
	    int x,y,a,b,k;
	    cin>>x>>y>>a>>b>>k;
	    if(x==y && a==b){
	        cout<<"SAME PRICE"<<endl;
	        continue;
	    }
	    x+=a*k;
	    y+=b*k;
	    if(x>y){
	        cout<<"PETROL"<<endl;
	        
	    }
	    else if(x<y){
	        cout<<"DIESEL"<<endl;
	        continue;
	    }
	    else{
	        cout<<"SAME PRICE"<<endl;
	        continue;
	    }
	}
	return 0;
}
