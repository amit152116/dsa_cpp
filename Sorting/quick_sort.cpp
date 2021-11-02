#include<bits/stdc++.h>
using namespace std;
int swaps=0;
int partition(vector<int> &arr, int start, int end){
    
    int i=start-1;
    int pivot=arr[end];
    for(int j=start;j<end;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
            swaps++;
        }
    }
    swap(arr[i+1],arr[end]);
    swaps++;
    return i+1;
}

void quick_sort(vector<int> &arr,int start,int end){

    if(start<end){
        int random = start + rand() % (end - start+ 1);
        swap(arr[end], arr[random]);
        swaps++;
        int pivot=partition(arr,start,end);

        quick_sort(arr,start,pivot-1);
        quick_sort(arr,pivot+1,end);
    }
}

int main(){
    vector<int> arr={375,274,339,471,239,187,176,15,71,116,296,355,491,81,85,329,195,253,11,3,174,48,84,395,261,224,23,466,345,272,492,489,243,257,60,11,87,44,400,64,156,473,175,343,15,345,412,16,407,85,438,175,306,356,197,422,476,109,482,204,207,434,60,409,131,112,111,63,129,121,137,398,494,383,387,110,177,349,409,208,493,100,424,421,329,103,76,87,291,178,317,221,412,360,259,90,147,447,149,153};
    int end= arr.size()-1;
    cout<<"Size : "<<end+1<<endl;
    int start=0;
    quick_sort(arr,start,end);
    for(auto i:arr){
        cout<<i<<' ';
    }
    cout<<endl<<"No.of swaps : "<<swaps<<endl;

    return 0;
}