#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

/*
    Karatsuba Multiplication
    A(x) = ax+b;
    B(x) = cx+d;
    C(x) = A(x)*B(x) = acx^2 +((a+b)(c+d)-ac-bd)x+bd
*/
string findSum(string a, string b) {}

string findDiff(string a, string b) {}

string karatsuba(string A, string B) {
    int n = A.length();
    if (n == 1) {
        int ans = stoi(A) * stoi(B);
        return to_string(ans);
    }
    if (n % 2 == 1) {
        n++;
        A = "0" + A;
        B = "0" + B;
    }
    int half = n / 2;

    string a = A.substr(0, half);
    string b = A.substr(half, n);

    string c = B.substr(0, half);
    string d = B.substr(half, n);

    string p = karatsuba(a, c);
    string q = karatsuba(b, d);

    string r = findDiff(karatsuba(findSum(a, b), findSum(c, d)), findSum(p, q));
    for (int i = 0; i < n; i++) {
        p += "0";
    }
    for (int i = 0; i < n / 2; i++) {
        r += "0";
    }
    string ans = findSum(p, findSum(r, q));
    return ans;
}

int main() {
    fast;
    string A = "123456789";
    string B = "987654321";
    cout << karatsuba(A, B);
    return 0;
}