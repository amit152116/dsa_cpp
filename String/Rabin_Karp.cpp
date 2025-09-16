#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

// https://chat.openai.com/share/33006054-0c84-44c9-8656-d27a5896321c

/*
There is a really easy trick to get better probabilities. We can just compute
two different hashes for each string (by using two different p, and/or different
m, and compare these pairs instead. If m  is about   10^9 for each of the two
hash functions than this is more or less equivalent as having one hash function
with   m ≈ 10^18 . When comparing 10^6  strings with each other, the probability
that at least one collision happens is now reduced to ≈10^-6 .
*/

int main() {
    string text    = "geeksforgeeks";
    string pattern = "geeks";

    long long p   = 31;
    long long mod = 1e9 + 7;

    vector<long long> power(text.size(), 1);
    for (size_t i = 1; i < text.size(); i++) {
        power[i] = (power[i - 1] * p) % mod;
    }

    //  Finding hash of text
    vector<long long> hash(text.size() + 1, 0);
    for (size_t i = 0; i < text.size(); i++) {
        hash[i + 1] = (hash[i] + (text[i] - 'a' + 1) * power[i]) % mod;
    }

    //  Finding Pattern hash
    long long target_hash = 0;
    for (size_t i = 0; i < pattern.size(); i++) {
        target_hash = (target_hash + (pattern[i] - 'a' + 1) * power[i]) % mod;
    }

    //  Searching Same Hash
    int n = pattern.size();
    for (size_t i = 0; i < text.size() - n + 1; i++) {
        long long cur_hash = (hash[i + n] + mod - hash[i]) % mod;
        if (cur_hash == (target_hash * power[i]) % mod) {
            cout << i << "->" << i + n << endl;
        }
    }

    return 0;
}
