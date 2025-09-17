#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;

//------------------  Implementing Stack using Linked List -------------------
struct Node {
    int   val;
    Node* next;

    Node(int val) {
        this->val = val;
        next      = nullptr;
    }
};

class Stack {
   private:
    Node* head;

   public:
    Stack() {
        head = NULL;
    }

    void push(int x) {
        Node* temp = new Node(x);
        temp->next = head;
        head       = temp;
    }

    int pop() {
        if (head == NULL) {
            cout << "No element remaining.\n";
            return -1;
        }
        int   res   = head->val;
        Node* todel = head;
        head        = head->next;
        delete todel;
        return res;
    }

    bool is_empty() {
        return head == NULL;
    }

    int top() {
        if (head == NULL) {
            cout << "NO element";
            return -1;
        }
        return head->val;
    }
};

/*
 *    ----------------    Implementing Stack using Queue ------------------
 *       There are two methods for this :
 *       1. Making the Push method costly
 *       2. Making the Pop method costly
 */

/*TODO : We can also implement stack using one queue only->
  https://leetcode.com/problems/implement-stack-using-queues/
 */
class stackQueue {
   private:
    queue<int> qu1, qu2;

   public:
    stackQueue() {}

    void push(int val) {
        qu2.push(val);
        while (!qu1.empty()) {
            qu2.push(qu1.front());
            qu1.pop();
        }
        queue<int> temp = qu1;
        qu1             = qu2;
        qu2             = temp;
    }

    void pop() {
        if (qu1.empty()) {
            cout << "Stack is empty " << endl;
        }
        qu1.pop();
    }
};

//  ---------------------------- Reversing the word ---------------------------
void reverse_Sentence(string s) {
    stack<string> result;
    for (int x = 0; x < s.length(); x++) {
        string word = "";
        while (s[x] != ' ' && x < s.length()) {
            word += s[x];
            x++;
        }
        result.push(word);
    }
    while (!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }
    cout << "\n\n";
}

//     ------------------ Reverse the String ---------------------------
string reverse_string(string s) {
    string result = s;
    int    start = 0, end = result.length() - 1;
    while (start < end) {
        char temp     = result[start];
        result[start] = result[end];
        result[end]   = temp;
        start++;
        end--;
    }
    return result;
}

//  ---------------------------- Reverse the Stack ---------------------------
void insert_At_Bottom(stack<int>& st, int data) {
    if (st.empty()) {
        st.push(data);
        return;
    }
    int topelement = st.top();
    st.pop();
    insert_At_Bottom(st, data);
    st.push(topelement);
}

void reverse_Stack(stack<int>& st) {
    if (st.empty()) {
        return;
    }
    int data = st.top();
    st.pop();
    reverse_Stack(st);
    insert_At_Bottom(st, data);
}

// ----------------------- Infix to Postfix Expression ------------------------
int operator_rank(char c) {
    if (c == '^') {
        return 3;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

string postfix_expression(string s) {
    stack<char> st;
    string      result;
    for (auto i : s) {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) {
            result += i;
        } else if (i == '(') {
            st.push(i);

        } else if (i == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }

        } else {
            while (!st.empty() && operator_rank(i) < operator_rank(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    return result;
}

// -------------------------- Infix to Prefix Expression -----------------------
string prefix_expression(string s) {
    stack<char> st;
    string      result;
    s = reverse_string(s);
    for (auto i : s) {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) {
            result += i;
        } else if (i == ')') {
            st.push(i);

        } else if (i == '(') {
            while (!st.empty() && st.top() != ')') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) {
                st.pop();
            }

        } else {
            while (!st.empty() && operator_rank(i) < operator_rank(st.top())) {
                result += st.top();
                st.pop();
            }
            st.push(i);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    result = reverse_string(result);
    return result;
}

void print_Stack(stack<int> st) {
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << "\n\n";
}

int main() {
    string s = "Hello, How are you?";
    reverse_Sentence(s);

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    print_Stack(st);
    reverse_Stack(st);
    cout << "After reversing the Stack: " << endl;
    print_Stack(st);

    string expression = "(a+b/c)*(a*d-g)";
    cout << "Infix Expression : " << expression << endl;
    cout << "Postfix Expression : " << postfix_expression(expression) << endl;
    cout << "Prefix Expression : " << prefix_expression(expression) << endl;

    return 0;
}
