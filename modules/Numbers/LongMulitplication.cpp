#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

string long_multiplication(string a, string b) {
    int         m    = a.length();
    int         n    = b.length();
    int         size = m + n;
    vector<int> result(size, 0);
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            int x = (a[i] - '0') * (b[j] - '0');
            result[i + j + 1] += x;
            result[i + j] += result[i + j + 1] / 10;
            result[i + j + 1] %= 10;
        }
    }
    int i = 0;
    while (i < size && result[i] == 0) i++;
    string ans = "";
    for (i; i < size; i++) {
        ans += result[i] + '0';
    }
    cout << endl;
    return ans;
}

int main() {
    fast;
    string a;
    cin >> a;
    string b     = a;
    int    count = 0;
    int    len   = a.size();
    while (true) {
        b = long_multiplication(a, b);
        count++;
        string c = b.substr(b.size() - len, len);
        cout << c << endl;
        if (c == a)
            break;
    }

    cout << "Count : " << count << endl;

    return 0;
}