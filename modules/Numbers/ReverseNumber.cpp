#include <climits>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int rev = 0;
    while (n > 0) {
        int remainder = n % 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && remainder > 7)) {
            cout << "0";
            return 0;
        }
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && remainder < -8)) {
            cout << "0";
            return 0;
        }
        n   = n / 10;
        rev = rev * 10 + remainder;
    }
    cout << rev;
    return 0;
}