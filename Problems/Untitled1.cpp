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
	    string n;
	    cin>>n;
	    int a=0,A=0,num=0,sym=0;
	    string copy=n;
	    string symbol="@#%&?";
	    string alpha="abcdefghijklmnopqrstuvwxyz";
	    string halpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	    string numb="01234567890";
	    for (int i=0;i<n.length();i++)
	    {
	    	for(int j=0;j<symbol.length();j++)
	    	{
	    		if(n[i]==symbol[j]){
	    			sym++;
	    			n.erase(i,1);
	    			break;
				}
			}
			for(int j=0;j<alpha.length();j++)
	    	{
	    		if(n[i]==alpha[j]){
	    			a++;
	    			n.erase(i,1);
	    			break;
				}
			}
			for(int j=0;j<halpha.length();j++)
	    	{
	    		if(n[i]==halpha[j]){
	    			A++;
	    			n.erase(i,1);
	    			break;
				}
			}
			for(int j=0;j<numb.length();j++)
	    	{
	    		if(n[i]==numb[j]){
	    			num++;
	    			n.erase(i,1);
	    			break;
				}
			}
			
		}
		if(a==A==num==sym==1){
			cout<<"YES"<<"\n";
			continue;
		}
		
		cout<<"NO"<<"\n";
		
		
	    
	    
	}
	return 0;
}

