#include<iostream>
#include<vector>

using namespace std;

/*
                             ------    MERGE SORT   ------
            Merge Sort is a Divide and Conquer algorithm. It divides the input array 
            into two halves, calls itself for the two halves, and then merges the two sorted halves.
*           Time Complexity : O(n.Logn)
*           Auxiliary Space: O(n) 
*/
int swaps=0;
void merge(vector<int>& arr, int start,int mid,int end){
    vector<int> brr;
    int i=start;
    int j=mid+1;
    while(i<=mid && j<=end){
        if(arr[i]<=arr[j]){
            brr.push_back(arr[i]);
            i++;
        }
        else{
            brr.push_back(arr[j]);
            j++;
        }
        swaps++;
    }
    while(i<=mid){
        brr.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        brr.push_back(arr[j]);
        j++;
    }
    for(int k=start;k<=end;k++){
		arr[k]=brr[k-start];
	}
    return;
}

void merge_Sort(vector<int>& arr,int start,int end){
    if(start<end){
        int mid=start+(end-start)/2;
        merge_Sort(arr,start,mid);
        merge_Sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
    return;
}
int main(){
    vector<int> arr={375,274,339,471,239,187,176,15,71,116,296,355,491,81,85,329,195,253,11,3,174,48,84,395,261,224,23,466,345,272,492,489,243,257,60,11,87,44,400,64,156,473,175,343,15,345,412,16,407,85,438,175,306,356,197,422,476,109,482,204,207,434,60,409,131,112,111,63,129,121,137,398,494,383,387,110,177,349,409,208,493,100,424,421,329,103,76,87,291,178,317,221,412,360,259,90,147,447,149,153};
    int n= arr.size();
    cout<<"Size : "<<n<<endl;
    int start=0;
    int end=n-1;
    merge_Sort(arr,start,end);

    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"No. of swaps : "<<swaps;
    return 0;
}

/*
?                      Application of Merge Sort:

    ->  Merge Sort is useful for sorting linked lists in O(nLogn) time. 
        In the linked list, we can insert items in the middle in O(1) 
        extra space and O(1) time. Therefore, the merge operation of merge 
        sort can be implemented without extra space for linked lists.
    ->  Inversion Count Problem
    ->  Used in External Sorting

!                      Drawbacks of Merge Sort:

    ->  Slower comparative to the other sort algorithms for smaller tasks.
    ->  Merge sort algorithm requires an additional memory space of 0(n) for the temporary array.
    ->  It goes through the whole process even if the array is sorted.


*/