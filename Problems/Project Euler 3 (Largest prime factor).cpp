#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long t;
    cin>>t;
    for(long long i=0;i<t;i++)
    {
    	long long n,maxprime;
    	cin >>n;
    	while(n%2==0)
    	{
    		n=n/2;
    		maxprime=2;
		}
		for(long long j=3;j*j<=n;j+=2)
		{
			while(n%j==0)
			{
				maxprime=j;
				n=n/j;
			}
		}
		if(n>2){
			maxprime=n;
		}
		cout<<maxprime<<endl;
	}
    return 0;
}

