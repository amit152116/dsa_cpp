#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
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
    return -1;
}

int findpos(vector<int> arr, int target) {
    int lo  = 0;
    int hi  = 1;
    int val = arr[0];
    while (val < target) {
        lo  = hi;
        hi  = 2 * hi;
        val = arr[hi];
    }
    return Binary_Search(arr, target, lo, hi);
}

int main() {
    vector<int> arr = {
        3,   11,  11,  15,  15,  16,  23,  44,  48,  60,  60,  63,  64,
        71,  76,  81,  84,  85,  85,  87,  87,  90,  100, 103, 109, 110,
        111, 112, 116, 121, 129, 131, 137, 147, 149, 153, 156, 174, 175,
        175, 176, 177, 178, 187, 195, 197, 204, 207, 208, 221, 224, 239,
        243, 253, 257, 259, 261, 272, 274, 291, 296, 306, 317, 329, 329,
        339, 343, 345, 345, 349, 355, 356, 360, 375, 383, 387, 395, 398,
        400, 407, 409, 409, 412, 412, 421, 422, 424, 434, 438, 447, 466,
        471, 473, 476, 482, 489, 491, 492, 493, 494};
    int target = 197;
    cout << findpos(arr, target);
    return 0;
}
