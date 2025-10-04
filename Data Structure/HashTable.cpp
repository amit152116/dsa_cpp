#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct Node {
    T     val;
    Node* next;

    Node(T val) {
        this->val = val;
        next      = nullptr;
    }
};

template <typename T>
class HashTable {
   private:
    vector<Node<T>*> arr;
    int              capacity;

   public:
    HashTable(int capacity) {
        this->capacity = capacity;
        arr.resize(capacity);
        for (auto& node : arr) {
            node = new Node(T());
        }
    }

    void push(T val) {
        auto node = arr[hashCode(val)];
        while (node->next) {
            if (node->val == val)
                return;
            node = node->next;
        }
        node->next = new Node(val);
    }

    void pop(T val) {
        auto node = arr[hashCode(val)];
        while (node->next->val != val) {
            node = node->next;
        }
        auto delElement = node->next;
        node->next      = node->next->next;
        delete delElement;
        return;
    }

    bool contain(T val) {
        auto node = arr[hashCode(val)];

        while (node) {
            if (node->val == val)
                return true;
            node = node->next;
        }
        return false;
    }

    int hashCode(int val) {
        return val % capacity;
    }

    int hashCode(string str) {
        static const int prime = 53;

        long long hash_val = 0;
        long long power    = 1;
        for (auto ch : str) {
            int val  = ch - 'a' + 1;
            hash_val = (hash_val + val * power) % capacity;
            power    = (power * prime) % capacity;
        }
        cout << hash_val << endl;
        return hash_val;
    }
};

int main() {
    HashTable<string> set(1000);

    set.push("amit");
    set.push("akhil");
    set.push("ajay");
    set.push("cpp");
    set.push("python");
    set.push("flutter");
    set.push("java");
    set.push("experiment");

    return 0;
}
