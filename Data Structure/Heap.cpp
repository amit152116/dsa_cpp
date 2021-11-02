#include<bits/stdc++.h>
using namespace std;
/*
*            Arr[(i-1)/2]	Returns the parent node
*            Arr[(2*i)+1]	Returns the left child node
*            Arr[(2*i)+2]	Returns the right child node
*/
class minHeap{
private:
    int *arr;
    int size;
    int capacity;
public:
    minHeap(int x){
        size=0;
        capacity=x;
        arr=new int[x];
    }
    int parent(int i){
        return arr[(i-1)/2];
    }
    int left(int i){
        return arr[(2*i)+1];
    }
    int right(int i){
        return arr[(2*i)+2];
    }
    void minHeapify(){
        
    }
};
int main(){
    
    return 0;
}