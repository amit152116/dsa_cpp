#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

bool primality_test_naive(long int n) {
    if (n == 2 || n == 3) {
        cout << n << " is a Prime No." << endl;
        return true;
    }
    if (n < 2 || n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    long int root = sqrt(n);
    for (long int i = 5; i <= root; i += 6) {
        if (n % i == 0) {
            return false;
        }
        if (n % (i + 2) == 0) {
            return false;
        }
    }

    cout << n << " is a Prime No." << endl;
    return true;
}

void sieve_eratosthenes(int n) {
    /*
        Time Complexity: O(n*log(log(n)))
        Auxiliary Space: O(n)
    */
    int count    = 0;
    int prime[n] = {0};
    cout << "Primes less than " << n << " are :" << endl;
    for (int i = 2; i < n; i++) {
        if (prime[i] == 0) {
            cout << i << " ";
            count++;
            for (int j = i * i; j < n; j += i) {
                prime[j] = 1;
            }
        }
    }
    cout << endl << "No. of Primes : " << count << endl;
    return;
}

bool is_palindrome(int n) {
    string a     = to_string(n);
    int    start = 0, end = a.length() - 1;
    while (start < end) {
        if (a[start++] != a[end--]) {
            return false;
        }
    }
    return true;
}

int main() {
    fast;
    long int n = INTMAX_MAX;
    cout << n << endl;
    long int k = (n + 1) % 6 == 0 ? (n + 1) / 6 : (n - 1) / 6;
    while (k > 0) {
        if (primality_test_naive(6 * k + 1) == true) {
            // break;
        }
        if (primality_test_naive(6 * k - 1) == true) {
            // break;
        }
        k--;
    }
    // sieve_eratosthenes(n);
}