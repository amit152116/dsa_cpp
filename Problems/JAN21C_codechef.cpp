#include<iostream>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k,x,y;
	    cin>>n >> k >> x >> y ;
	    if(x>=y){
	    	for(x,y;x<n && y<n;++x,++y);
		    k--;
		    if(x==n && y==n){
		    	cout<< x <<" " <<y <<"\n";
				continue;
			}
		    k=k%4;
		    while(k){
				if(x==n){
					for(x,y;x>0 && y<n;--x,++y);
					k--;
				}
				else if(y==n){
					for(x,y;x>0 && y>0;--x,--y);
			    	k--;
				}
				else if(x==0){
					for(x,y;x<n && y>0;++x,--y);
			    	k--;
				}
				else if(y==0){
					for(x,y;x<n && y<n;++x,++y);
			    	k--;
				}	
			}
			cout<< x <<" " <<y <<"\n";
		}
		else {
			for(x,y;x<n && y<n;++x,++y);
		    k--;
		    if(x==n && y==n){
		    	cout<< x <<" " <<y <<"\n";
				continue;
			}
		    k=k%4;
		    while(k){
				 if(x==n){
					for(x,y;x>0 && y>0;--x,--y);
					k--;
				}
				else if(y==n){
					for(x,y;x<n && y>0;++x,--y);
			    	k--;
				}
				else if(x==0){
					for(x,y;x<n && y<n;++x,++y);
			    	k--;
				}
				else if(y==0){
					for(x,y;x>0 && y<n;--x,++y);
			    	k--;
				}
			}
			cout<< x <<" " <<y <<"\n";
		}
	    
	
	}
	return 0;
}
	
