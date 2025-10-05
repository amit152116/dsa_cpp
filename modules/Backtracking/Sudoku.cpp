#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

bool safe(vector<vector<int>> arr, int x, int y, int num, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[x][i] == num)
            return false;
        if (arr[i][y] == num)
            return false;
    }
    int row = x - x % 3;
    int col = y - y % 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i + row][j + col] == num)
                return false;
        }
    }
    return true;
}

bool solve_sudoku(vector<vector<int>>& arr, int n) {
    int  row = -1, col = -1;
    bool full = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                row  = i;
                col  = j;
                full = false;
            }
        }
        if (!full)
            break;
    }
    if (full)
        return true;

    for (int i = 1; i <= n; i++) {
        if (safe(arr, row, col, i, n)) {
            arr[row][col] = i;
            if (solve_sudoku(arr, n)) {
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

int main() {
    // Sudoku Solving Problem
    vector<vector<int>> arr = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1}, {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5}, {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    if (!solve_sudoku(arr, arr.size())) {
        cout << endl << "There is no Solution." << endl;
    }

    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0) {
            cout << endl;
        }
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0) {
                cout << "\t";
            }
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}
