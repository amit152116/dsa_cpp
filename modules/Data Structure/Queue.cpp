#include <bits/stdc++.h>
using namespace std;

/*
 *    -----------------------------    Implementing Queue using Linked List
 * ---------------------------
 */
struct Node {
    int   val;
    Node* next;

    Node(int val) {
        this->val = val;
        next      = nullptr;
    }
};

class queue {
   private:
    Node* front;
    Node* back;

   public:
    queue() {
        front = NULL;
        back  = NULL;
    }

    void push(int val) {
        Node* temp = new Node(val);
        if (front) {
            back->next = temp;
            back       = temp;
        } else {
            front = temp;
            back  = temp;
        }
    }

    void pop() {
        if (front) {
            Node* toDelete = front;
            front          = front->next;
            delete toDelete;
        } else {
            back = NULL;
            cout << "Queue is empty";
        }
    }

    bool empty() {
        if (!front) {
            return true;
        } else {
            return false;
        }
    }

    int front_element() {
        return front->val;
    }

    void print() {
        Node* temp = front;
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    int back_element() {
        return back->val;
    }
};

/*
 *    -----------------------------    Implementing Queue using Stack
 * ---------------------------
 */
class queueStack {
   private:
    stack<int> st1;
    stack<int> st2;

   public:
    queueStack() = default;

    void push(int val) {
        st1.push(val);
    }

    void pop() {
        if (st1.empty() && st2.empty()) {
            cout << "Queue is empty" << '\n';
            return;
        }
        peek();
        st2.top();
    }

    auto peek() -> int {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }

    auto empty() -> bool {
        return st1.empty() && st2.empty();
    }
};

auto main() -> int {
    priority_queue<int, vector<int>, std::greater<>> q;
    q.push(5);
    q.push(4);
    q.push(9);
    cout << q.top() << endl;
    q.pop();
    cout << q.top();

    stack<int> st;
    st.push(2);
    st.push(3);
    return 0;
}
