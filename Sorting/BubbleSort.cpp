#include "../utils/randomNumbers.hpp"

#include <iostream>
#include <vector>

using namespace std;

/*
 *               Worst & Average Case Time Complexity : O(n^2)
 *               Best Case Time Complexity : O(n)
 *               Auxiliary Space: O(1)
 */

int main() {
    int  n     = 1000;
    auto arr   = generateRandomNums(n, 1000, 42);
    int  count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                count++;
            }
        }
    }
    cout << "No of swaps required : " << count << endl;
    for (int i = 0; i < n; i++) {
        if (i % 5 == 0) {
            cout << endl;
        }
        cout << arr[i] << "\t";
    }
}
