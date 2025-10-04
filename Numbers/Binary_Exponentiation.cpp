#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

/*
* Appplications :

    1.  Effective computation of large exponents modulo a number.

*/
long long bipow(long long int a, long long int b) {
    if (b == 0) {
        return 1;
    }
    long long res = bipow(a, b / 2);
    if (b & 1) {
        return res * res * a;
    }
    return res * res;
}

long long bipow2(long long int a, long long int b) {
    long long int res = 1;
    while (b > 0) {
        if (b & 1) {
            res *= a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    cout << bipow(8, 15) << endl;
}
