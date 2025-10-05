#include "utils/randomNumbers.hpp"

#include <iostream>
#include <vector>

using namespace std;

int Binary_Search(vector<int> nums, int target, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (target > nums[mid]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start;
}

int main() {
    int  n     = 1000;
    auto arr   = generateRandomNums(n, 42, 1000);
    int  count = 0;
    for (int i = 1; i < n; i++) {
        int j   = i - 1;
        int key = arr[i];
        int loc = Binary_Search(arr, key, 0, j);
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
            count++;
        }
        arr[j + 1] = key;
    }
    for (auto i : arr) {
        cout << i << ' ';
    }
    cout << "\nNo of swap required : " << count << endl;
    return 0;
}
