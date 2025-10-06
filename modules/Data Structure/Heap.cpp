#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

/*
 *            Arr[(i-1)/2]	Returns the parent node
 *            Arr[(2*i)+1]	Returns the left child node
 *            Arr[(2*i)+2]	Returns the right child node
 */
class MinHeap {
   private:
    vector<int> arr;
    int         size;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i) + 1;
    }

    int right(int i) {
        return (2 * i) + 2;
    }

    void print() {
        for (auto it : arr) {
            cout << it << ',';
        }
        cout << endl;
    }

   public:
    MinHeap() {
        size = 0;
    }

    int top() {
        cout << arr[0] << endl;
        return arr[0];
    }

    void pop() {
        if (size == 0)
            return;
        swap(arr[0], arr[size - 1]);
        arr.pop_back();
        size--;
        int idx = 0;

        while (idx < size) {
            int left   = this->left(idx);
            int right  = this->right(idx);
            int minIdx = idx;
            if (left < size && arr[minIdx] > arr[left])
                minIdx = left;
            if (right < size && arr[minIdx] > arr[right])
                minIdx = right;
            if (minIdx != idx) {
                swap(arr[minIdx], arr[idx]);
                idx = minIdx;
            } else
                break;
        }

        print();
    }

    void push(int x) {
        arr.push_back(x);
        size++;
        int idx = size - 1;
        while (idx > 0) {
            int parent = this->parent(idx);
            if (arr[parent] > arr[idx]) {
                swap(arr[parent], arr[idx]);
                idx = parent;
            } else
                break;
        }
        print();
    }

    auto minHeapify(vector<int> heap) -> vector<int> {
        for (int i = size - 1; i >= 0; i--) {
            int parent = this->parent(i);
            if (heap[i] < heap[parent])
                swap(heap[i], heap[parent]);
        }
        return heap;
    }
};

int main() {
    MinHeap heap;
    heap.push(25);
    heap.push(24);
    heap.push(358);
    heap.push(398);
    heap.push(15);
    heap.push(9);
    heap.push(7);
    heap.pop();
    heap.pop();
    heap.pop();
    heap.pop();
    heap.pop();
    heap.pop();
    return 0;
}
