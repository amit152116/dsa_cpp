#include <bits/stdc++.h>

#include <vector>

using namespace std;

long long int coin_change(int sum, vector<int> coins,
                          vector<long long int>& arr) {
    if (sum == 0) {
        arr[sum] = 1;
        return 1;
    }
    if (sum < 0) {
        return INT_MAX;
    }
    if (arr[sum] != -1) {
        return arr[sum];
    }
    long long int count = 0;
    for (int i = 0; i < coins.size(); i++) {
        int ans = coin_change(sum - coins[i], coins, arr);
        if (ans == INT_MAX)
            continue;
        count += ans;
    }
    arr[sum] = count;
    return count;
}

int main() {
    vector<int>           coins = {1, 2, 5};
    int                   sum   = 5;
    vector<long long int> arr(sum + 1, -1);
    clock_t               start, end;
    start             = clock();
    int ans           = coin_change(sum, coins, arr);
    end               = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    for (int i = 0; i < arr.size(); i++) {
        cout << i << " - " << arr[i] << endl;
    }

    cout << time_taken << endl;

    return 0;
}
