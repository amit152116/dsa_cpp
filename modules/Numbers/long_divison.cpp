#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

int main() {
    fast;
    string   number  = "3132313231";
    long int divisor = 31;
    string   ans;

    long int idx  = 0;
    long int temp = number[idx] - '0';
    while (temp < divisor) temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx) {
        ans += (temp / divisor) + '0';
        if (number.size() > ++idx)
            temp = (temp % divisor) * 10 + number[idx] - '0';
    }
    temp = temp % divisor;
    cout << temp << endl;
    cout << ans << endl;
    return 0;
}