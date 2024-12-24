
#include<bits/stdc++.h>

using namespace std;
struct node
{
    int data;
    node* next;

    node(int data){
        this->data = data;
    }
};

int* iteratorArray(int** start){
    
    return (int *)start+1;
}

int* iteratorLinkedList(int** start){
    return *(start+1);
}

bool myComparator(int* a, int* b){
    return *a>*b;
}


void mutator(int* a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


void sorting(int* start, int*(*iterator)(int**),int size){

    for(int i=0;i<size;i++){
        int* current = start;
        for(int i=0;i<size;i++){
            int* next = iterator((int**)current);
            if(next ==nullptr)break;
            if(myComparator(current,next)){
                mutator(current,next);
            }
            current = next;
        }
    }
}


int main(){
    int arr[8] = {4,6,23,8,57,23,447,432};


    node* head = new node(-1);
    node* temp = head;

    for(auto it:arr){
        node* curr = new node(it);
        temp->next = curr;
        temp = temp->next;
    }

    int* arrayStart = arr;

    int* nodestart = (int*)head->next;

    mutator(arr,arr+4);

    for(int i=0;i<8;i++){
        cout<<*arrayStart<<endl;
        arrayStart = iteratorArray((int**)arrayStart);
    }

    for(int i=0;i<8;i++){
        cout<<*nodestart<<endl;
        nodestart = iteratorLinkedList((int **)nodestart);
    }

    arrayStart = arr;

    nodestart = (int*)head->next;

    sorting(arrayStart, iteratorArray,8);
    sorting(nodestart,iteratorLinkedList,8);


    for(int i=0;i<8;i++){
        arrayStart = iteratorArray((int**)arrayStart);
        cout<<*arrayStart<<endl;
    }

    for(int i=0;i<8;i++){
        cout<<*nodestart<<endl;
        nodestart = iteratorLinkedList((int **)nodestart);
    }

    return 0;
}



