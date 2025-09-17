#include <bits/stdc++.h>

#include "../utils/randomNumbers.hpp"
using namespace std;

int main() {
    int  n     = 1000;
    auto arr   = generateRandomNums(n, 1000, 42);
    int  count = 0;

    for (int i = 1; i < n; i++) {
        int j   = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key) {
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
}
