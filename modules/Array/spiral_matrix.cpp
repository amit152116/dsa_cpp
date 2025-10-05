#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    int n = matrix.size();
    int m = matrix[0].size();

    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = m - 1;

    while (rowStart <= rowEnd && colStart <= colEnd) {
        for (int i = colStart; i <= colEnd; i++) {
            cout << matrix[rowStart][i] << "  ";
        }
        rowStart++;
        for (int i = rowStart; i <= rowEnd; i++) {
            cout << matrix[i][colEnd] << "  ";
        }
        colEnd--;
        for (int i = colEnd; i >= colStart; i--) {
            cout << matrix[rowEnd][i] << "  ";
        }
        rowEnd--;
        for (int i = rowEnd; i >= rowStart; i--) {
            cout << matrix[i][colStart] << "  ";
        }
        colStart++;
    }
    return 0;
}
