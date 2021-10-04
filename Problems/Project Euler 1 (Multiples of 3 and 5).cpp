#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>> t;
	for (int i=0;i<t;i++)
	{
		long n;
		cin>>n;
		long sum=0;
		/*
		O(1) Solution : say N= 100 so, 
		max multiple of 3 here below N is 99 
		i.e. 3*33 so, sum of all multiples of 3 
		has a pattern 3(1+2+3+....+33) use this
		*/
		long three =(n-1)/3;
		long five =(n-1)/5;
		long fifteen =(n-1)/15;
		
		sum=3*(three*(three+1)/2)+5*(five*(five+1)/2)-15*(fifteen*(fifteen+1)/2);

		cout<<sum<<endl;
	}
	return 0;
}
