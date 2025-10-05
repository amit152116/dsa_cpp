#include <bits/stdc++.h>

#include "utils/randomNumbers.hpp"

using namespace std;

/*
                           ------    SELECTION SORT   ------
                The selection sort algorithm sorts an array by repeatedly
finding the minimum element from unsorted part and putting it at the beginning.
*               Time Complexity : O(n^2)
*               Auxiliary Space: O(1)
?               It can be useful when memory write is a costly operation
*/
auto main() -> int {
    int  n   = 1000;
    auto arr = generateRandomNums(n, 42, 1000);
    cout << n << '\n';

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (i != min_idx) {
            swap(arr[i], arr[min_idx]);
            count++;
        }
    }

    cout << "No of swaps required : " << count << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ",";
    }
}
