#include <bits/stdc++.h>

using namespace std;

// Ciruclar array house robbery
int solve(vector<int> nums, int start, int n) {
    vector<int> dp = vector(n, 0);
    dp[start]      = nums[start];
    for (int i = start + 1; i < n; i++) {
        int incl = nums[i];
        if (i - 2 >= 0) {
            incl += dp[i - 2];
        }
        int excl = dp[i - 1];

        dp[i] = max(incl, excl);
    }

    return dp[n - 1];
}

int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1)
        return nums[0];
    return max(solve(nums, 0, n - 1), solve(nums, 1, n));
}

int main() {
    return 0;
}
