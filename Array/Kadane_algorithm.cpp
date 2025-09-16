#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

int kadane(vector<int> arr, int n) {
    int sum    = 0;
    int maxSum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        sum    = max(arr[i], sum + arr[i]);
        maxSum = max(maxSum, arr[i]);
    }
    return maxSum;
}

/*
    Case 1: The elements that contribute to the maximum sum are
            arranged such that no wrapping is there.
            Kadane’s algorithm will produce the result.

    Case 2: The elements which contribute to the maximum sum are
            arranged such that wrapping is there. In this case,
            we change wrapping to non-wrapping. Let us see how.
            Wrapping of contributing elements implies non-wrapping
            of non-contributing elements, so find out the sum of
            non-contributing elements and subtract this sum from
            the total sum. To find out the sum of non-contributions,
            invert the sign of each element and then run Kadane’s algorithm.
        Our array is like a ring and we have to eliminate the maximum continuous
        negative that implies maximum continuous positive in the inverted
   arrays. Finally, we compare the sum obtained in both cases and return the
   maximum of the two sums.
*/
void circular_kadane(vector<int> arr, int n) {
    int nonWrapingSum = kadane(arr, n);
    int totalSum      = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
        arr[i] = -arr[i];
    };
    int wrapingSum = totalSum + kadane(arr, n);
    int maxSum     = max(wrapingSum, nonWrapingSum);
    cout << "MAX Circular Sum Subarray " << maxSum << endl;
}

int main() {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int n = arr.size();
    cout << "Max Sum Subarray" << kadane(arr, n) << endl << endl;

    circular_kadane(arr, n);
    return 0;
}
