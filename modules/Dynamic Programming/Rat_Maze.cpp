#include <time.h>

#include <chrono>
#include <iostream>
#include <vector>
using namespace std;
using namespace std::chrono;

long long int solve_maze(int n, int m, int x, int y,
                         vector<vector<long long int>>& memo) {
    if (x > n || y > m)
        return 0;

    if (x == 0 && y == 0) {
        return 1;
    }
    if (x == 0 || y == 0) {
        memo[x][y] = 1;
        return 1;
    }
    if (memo[x][y] != -1) {
        return memo[x][y];
    }
    long long int count = 0;
    count +=
        solve_maze(n, m, x - 1, y, memo) + solve_maze(n, m, x, y - 1, memo);
    memo[x][y] = count;

    return count;
}

int main() {
    int                           n = 20, m = 20;
    int                           x = n - 1, y = m - 1;
    vector<vector<long long int>> memo(n, vector<long long int>(m, -1));
    auto                          start = high_resolution_clock::now();

    solve_maze(n, m, x, y, memo);

    auto end = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(end - start);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "[" << i << "," << j << "] - " << memo[i][j] << endl;
        }
    }

    cout << "Time Taken : " << duration.count() << "ms" << endl;
    return 0;
}
