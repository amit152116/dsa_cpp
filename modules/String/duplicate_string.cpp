#include <bits/stdc++.h>

using namespace std;

uint64_t hashCode(string str) {
    static const uint64_t prime = 31;
    static const uint64_t mod   = 1e9 + 9;

    uint64_t power = 1;
    uint64_t hash  = 0;
    for (auto ch : str) {
        uint64_t val = ch - 'a' + 1;
        hash         = (hash + val * power) % mod;
        power        = (power * prime) % mod;
    }
    return hash;
}

int main() {
    vector<string>         arr = {"deshbhagat", "amit",  "akhil", "ajay",
                                  "amit",       "vikas", "ankit", "nikhil",
                                  "anki",       "nikhl", "akhil", "jay"};
    vector<pair<int, int>> hash;
    for (uint64_t i = 0; i < arr.size(); i++) {
        hash.push_back({hashCode(arr[i]), i});
    }
    sort(hash.begin(), hash.end());
    for (auto it : hash) {
    }
    return 0;
}
