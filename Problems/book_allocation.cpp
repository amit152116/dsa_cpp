#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

bool possible(vector<int> arr, int n, int m, int max) {
    int students = 1;
    int cur_sum  = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max)
            return false;
        if (arr[i] + cur_sum > max) {
            students++;
            cur_sum = arr[i];
            if (students > m)
                return false;
        } else {
            cur_sum += arr[i];
        }
    }
    return true;
}

int main() {
    vector<int> books    = {12, 34, 67, 90, 39};
    int         students = 3;
    int         n        = books.size();
    int         sum      = 0;
    int         result;
    for (int i = 0; i < n; i++) {
        sum += books[i];
    }

    int start = 0, end = sum;
    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (possible(books, n, students, mid)) {
            result = mid;
            end    = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    cout << "Max Pages one Student get : " << result << endl;
    return 0;
}