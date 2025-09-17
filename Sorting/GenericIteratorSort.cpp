// ============================================================================
//  Generic Iterator and Sorting Example
// ============================================================================
//  This program demonstrates how to implement generic traversal (iterator-like
//  functions) and sorting over different data structures (array and linked
//  list) using a uniform interface.
//
//  Key ideas:
//  - Iterator abstraction for arrays and linked lists.
//  - Comparator and mutator (swap) functions for sorting.
//  - Generic sorting function that works with different iterators.
// ============================================================================

#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------------------------------
// Node definition for Linked List
// ---------------------------------------------------------------------------
struct Node {
    int   data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// ---------------------------------------------------------------------------
// Iterator Functions
// ---------------------------------------------------------------------------

// Iterator for arrays: moves to the next integer in memory.
int* iteratorArray(int** start) {
    return (int*)start + 1;
}

// Iterator for linked list: moves to the next node's data.
int* iteratorLinkedList(int** start) {
    return *(start + 1);
}

// ---------------------------------------------------------------------------
// Comparator and Mutator
// ---------------------------------------------------------------------------

// Comparator: returns true if *a > *b (descending order).
bool myComparator(int* a, int* b) {
    return *a > *b;
}

// Mutator: swaps two values in memory.
void mutator(int* a, int* b) {
    int temp = *a;
    *a       = *b;
    *b       = temp;
}

// ---------------------------------------------------------------------------
// Generic Sorting Function
// ---------------------------------------------------------------------------
// start     : pointer to first element/node
// iterator  : function to move to the next element
// size      : total elements to sort
//
// Implements a bubble-sort-like logic using iterators.
// ---------------------------------------------------------------------------
void sorting(int* start, int* (*iterator)(int**), int size) {
    for (int i = 0; i < size; i++) {
        int* current = start;
        for (int j = 0; j < size; j++) {
            int* next = iterator((int**)current);
            if (next == nullptr)
                break;
            if (myComparator(current, next)) {
                mutator(current, next);
            }
            current = next;
        }
    }
}

// ---------------------------------------------------------------------------
// Main Function
// ---------------------------------------------------------------------------
int main() {
    // Example input array
    int arr[8] = {4, 6, 23, 8, 57, 23, 447, 432};

    // Construct linked list with array values
    Node* head = new Node(-1);  // dummy head
    Node* temp = head;
    for (auto it : arr) {
        Node* curr = new Node(it);
        temp->next = curr;
        temp       = temp->next;
    }

    // Array and linked list start pointers
    int* arrayStart = arr;
    int* nodeStart  = (int*)head->next;

    // Example: swap first and fifth element in array
    mutator(arr, arr + 4);

    // Traverse array using iteratorArray
    cout << "Array Traversal:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << *arrayStart << endl;
        arrayStart = iteratorArray((int**)arrayStart);
    }

    // Traverse linked list using iteratorLinkedList
    cout << "\nLinked List Traversal:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << *nodeStart << endl;
        nodeStart = iteratorLinkedList((int**)nodeStart);
    }

    // Reset start pointers
    arrayStart = arr;
    nodeStart  = (int*)head->next;

    // Sort array and linked list
    sorting(arrayStart, iteratorArray, 8);
    sorting(nodeStart, iteratorLinkedList, 8);

    // Print sorted array
    cout << "\nSorted Array:" << endl;
    for (int i = 0; i < 8; i++) {
        arrayStart = iteratorArray((int**)arrayStart);
        cout << *arrayStart << endl;
    }

    // Print sorted linked list
    cout << "\nSorted Linked List:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << *nodeStart << endl;
        nodeStart = iteratorLinkedList((int**)nodeStart);
    }

    return 0;
}
