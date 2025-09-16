#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

bool isSafe(vector<vector<int>> board, int row, int col, int n) {
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; i >= 0 && j < n; j++, i--)
        if (board[i][j])
            return false;

    return true;
}
bool nQueen(vector<vector<int>>& board, int n, int row) {
    if (row >= n)
        return true;

    for (int i = 0; i < n; i++) {
        if (isSafe(board, row, i, n)) {
            board[row][i] = 1;

            if (nQueen(board, n, row + 1))
                return true;
            board[row][i] = 0;
        }
    }
    return false;
}

int main() {
    // N-Queen Problem
    int                 n = 4;
    vector<vector<int>> board(n, vector<int>(n, 0));
    nQueen(board, n, 0);
    for (auto i : board) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
