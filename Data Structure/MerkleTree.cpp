#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

class TrieNode {
   private:
    uint64_t hashCode() {
        uint64_t prime  = 61;
        uint64_t mod    = 1e9 + 9;
        uint64_t power  = 1;
        uint64_t hash   = 0;
        uint64_t number = val;

        while (number) {
            auto unit = number % 2;
            number    = number / 2;
            hash      = (hash + power * unit) % mod;
            power     = (power * prime) % mod;
        }

        if (left)
            number = left->curr_hash;
        while (number) {
            auto unit = number % 10;
            number    = number / 10;
            hash      = (hash + power * unit) % mod;
            power     = (power * prime) % mod;
        }

        if (right)
            number = right->curr_hash;
        while (number) {
            auto unit = number % 10;
            number    = number / 10;
            hash      = (hash + power * unit) % mod;
            power     = (power * prime) % mod;
        }
        return hash;
    }

   public:
    uint64_t  curr_hash, left_hash, right_hash;
    TrieNode *left, *right;
    int       val;

    TrieNode(int value, TrieNode* left = NULL, TrieNode* right = NULL) {
        this->val       = value;
        this->left      = left;
        this->right     = right;
        this->curr_hash = hashCode();
    }
};

int main() {
    TrieNode* left = new TrieNode(3968306);

    cout << left->val << endl << left->curr_hash << endl;
    TrieNode* right = new TrieNode(10);
    cout << right->val << endl << right->curr_hash << endl;
    TrieNode* root = new TrieNode(11, left, right);
    cout << root->val << endl << root->curr_hash << endl;
    return 0;
}
