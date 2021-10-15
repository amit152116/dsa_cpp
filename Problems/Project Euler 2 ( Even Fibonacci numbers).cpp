#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		long n,a1=2,a2=8,a3,sum=0;
		cin>>n;
		while(a1<n)
		{
			sum+=a1;
			a3=4*a2+a1;
			a1=a2;
			a2=a3;
		}
		cout<<sum<<endl;
		
	}
    return 0;
} 

