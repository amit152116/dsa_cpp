#include "utils/randomNumbers.hpp"

#include <iostream>
#include <vector>

using namespace std;

/*
                             ------    MERGE SORT   ------
            Merge Sort is a Divide and Conquer algorithm. It divides the input
array into two halves, calls itself for the two halves, and then merges the two
sorted halves.
*           Time Complexity : O(n.Logn)
*           Auxiliary Space: O(n)
*/
int swaps = 0;

void merge(vector<int>& arr, int start, int mid, int end) {
    vector<int> brr;
    int         i = start;
    int         j = mid + 1;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            brr.push_back(arr[i]);
            i++;
        } else {
            brr.push_back(arr[j]);
            j++;
        }
        swaps++;
    }
    while (i <= mid) {
        brr.push_back(arr[i]);
        i++;
    }
    while (j <= end) {
        brr.push_back(arr[j]);
        j++;
    }
    for (int k = start; k <= end; k++) {
        arr[k] = brr[k - start];
    }
    return;
}

void merge_Sort(vector<int>& arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;
        merge_Sort(arr, start, mid);
        merge_Sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    return;
}

int main() {
    int  n   = 1000;
    auto arr = generateRandomNums(n, 42, 1000);
    cout << "Size : " << n << endl;
    int start = 0;
    int end   = n - 1;
    merge_Sort(arr, start, end);

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "No. of swaps : " << swaps;
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
    ->  Merge sort algorithm requires an additional memory space of 0(n) for the
temporary array.
    ->  It goes through the whole process even if the array is sorted.


*/
