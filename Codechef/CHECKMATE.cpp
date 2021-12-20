#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
	    pair<int,int> king,a,b;
	    cin>>king.first>>king.second;
	    cin>>a.first>>a.second;
	    cin>>b.first>>b.second;
		string ans="No";
		if(king.first==8 ||king.first==1 ||king.second==8 ||king.second==1){
			if(king.first==8){
				if((b.first==7||a.first==7) &&a.second!=b.second){
					if(abs(king.second-a.second)>1 && abs(king.second-b.second)>1){
						ans="YES";
					}
				}
			}
			if(king.first==1){
				if((b.first==2||a.first==2) &&a.second!=b.second){
					if(abs(king.second-a.second)>1 && abs(king.second-b.second)>1){
						ans="YES";
					}
				}
			}
			if(king.second==8){
				if((b.second==7||a.second==7) && a.first!=b.first ){
					if( abs(king.first-a.first)>1 && abs(king.first-b.first)>1){
						ans="YES";
					}
				}
				
			}
			if(king.second==1){
				if((b.second==2||a.second==2) && a.first!=b.first ){
					if( abs(king.first-a.first)>1 && abs(king.first-b.first)>1){
						ans="YES";
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
