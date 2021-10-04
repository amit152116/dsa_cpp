#include<iostream>
#include<vector>

using namespace std;
int main(){

    vector<int> arr(101,0);
    int count=1;
    while(count<=100)
    {
        for(int i=count;i<=100;i++){
        arr[i]=1;
    }
        count++;
        if(count==100){
            break;
        }
    for(int i=count;i<=100;i+=2){
        arr[i]=0;
    }
        count++;
        if(count==100){
            break;
        }
    for(int i=count;i<=100;i+=3){
        if(arr[i]==0){
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }
        count++;
        if(count==100){
            break;
        }
    }
    int sum =0;
    for(int i=1;i<=100;i++){
        if(arr[i]==1){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}