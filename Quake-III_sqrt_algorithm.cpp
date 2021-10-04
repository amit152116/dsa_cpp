#include<iostream>
using namespace std;

int main(){
    float n;
    cin>>n;
    long i;
    i=*(long *) &n;
    cout<<i<<endl;
}