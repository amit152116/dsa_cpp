#include<iostream>

using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin>>t;
	for (int i = 10; i > 0; i--)
	{
		if (t%i==0)
		{
			cout<<i<<endl;
			break;
		}
		
	}
	
	return 0;
}
