#include <iostream>
using namespace std;

class Node {
   public:
    int   data;
    Node* next;

    Node(int val) {
        this->data = val;
        next       = NULL;
    }

    void insertAtTail(int val) {
        Node* n    = new Node(val);
        Node* temp = this;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

    void displayList() {
        Node* temp = this;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    Node* insertAtHead(int val) {
        Node* n = new Node(val);
        n->next = this;
        return n;
    }

    bool search(int key) {
        Node* temp = this;
        while (temp != NULL) {
            if (temp->data == key) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    int length() {
        Node* head  = this;
        int   count = 0;
        while (head != NULL) {
            head = head->next;
            count++;
        }
        return count;
    }
};

/*---------------------      Delete the Node of the Linked List
 * ---------------------------*/
void deleteNode(Node*& head, int val) {
    Node* temp = head;
    while (temp->next->data != val) {
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next    = temp->next->next;
    delete delNode;
}

/*-------------------------  Reverse the Linked List in Iterative way
 * --------------------*/
// * Linked list can also be reversed by using Stack.

Node* reverseList(Node*& head) {
    Node* previous = NULL;
    Node* current  = head;
    Node* forward;
    while (current != NULL) {
        forward       = current->next;
        current->next = previous;
        previous      = current;
        current       = forward;
    }
    return previous;
}

/* --------------------      Reverse the Linked List Recursively
 * ------------------------*/

Node* reverseRecursively(Node*& head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    Node* newhead    = reverseRecursively(head->next);
    head->next->next = head;
    head->next       = NULL;

    return newhead;
}

/*---------------------      Reverse the kth node in Linked List
 * -----------------------*/

Node* reverseK(Node*& head, int k) {
    int   count    = 0;
    Node* previous = NULL;
    Node* current  = head;
    Node* next;
    while (current != NULL && count < k) {
        next          = current->next;
        current->next = previous;
        previous      = current;
        current       = next;
        count++;
    }
    if (next != NULL) {
        head->next = reverseK(next, k);
    }
    return previous;
}

/* -------------------     Detection & Removal of Cycle in Linked List
 * -------------------*/
/*-----------------------------     (Floyd's Cycle Algorithm)
 * -------------------------------*/

void make_cycle(Node*& head, int pos) {
    Node* temp = head;
    Node* startNode;
    int   count = 1;
    while (temp->next != NULL) {
        if (count = pos) {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detect_cycle(Node*& head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

void remove_cycle(Node*& head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            fast = head;
            if (slow == fast) {
                while (slow->next != fast) {
                    slow = slow->next;
                }
            } else {
                while (fast->next != slow->next) {
                    fast = fast->next;
                    slow = slow->next;
                }
            }
            slow->next = NULL;
            break;
        }
    }
}

/*-------------------------   Intersection point in 2 Linked List
 * ---------------------------------*/

void intersect(Node*& head1, Node*& head2, int pos) {
    pos--;
    Node* temp1 = head1;
    Node* temp2 = head2;
    while (pos--) {
        temp1 = temp1->next;
    }
    while (temp2->next != NULL) {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

int intersection_point(Node* head1, Node* head2) {
    int   l1 = head1->length();
    int   l2 = head2->length();
    Node* ptr1;
    Node* ptr2;
    int   d = 0;
    if (l1 > l2) {
        ptr1 = head1;
        ptr2 = head2;
        d    = l1 - l2;
    } else {
        ptr1 = head2;
        ptr2 = head1;
        d    = l2 - l1;
    }
    while (d--) {
        ptr1 = ptr1->next;
        if (ptr1 == NULL) {
            return -1;
        }
    }
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

/* --------------------------      Merge two Sorted Linked List
 * ----------------------------*/

Node* merge(Node* head1, Node* head2) {
    Node* dummyNode = new Node(-1);
    Node* temp1     = head1;
    Node* temp2     = head2;
    Node* temp3     = dummyNode;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data <= temp2->data) {
            temp3->next = temp1;
            temp1       = temp1->next;
        } else {
            temp3->next = temp2;
            temp2       = temp2->next;
        }
        temp3 = temp3->next;
    }
    while (temp1 != NULL) {
        temp3->next = temp1;
        temp1       = temp1->next;
        temp3       = temp3->next;
    }
    while (temp2 != NULL) {
        temp3->next = temp2;
        temp2       = temp2->next;
        temp3       = temp3->next;
    }
    return dummyNode->next;
}

/* -------------------------------       Merge Sorted List Recursively
 * ---------------------------------*/
Node* merge_recursively(Node*& head1, Node*& head2) {
    if (head1 == NULL && head2 == NULL) {
        return NULL;
    }

    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    Node* result;
    if (head1->data <= head2->data) {
        result       = head1;
        result->next = merge_recursively(head1->next, head2);
    } else {
        result       = head2;
        result->next = merge_recursively(head1, head2->next);
    }
    return result;
}

/* ---------------------------       Even position Node after Odd position Node
 * -------------------------*/
void evenAfterOdd(Node*& head) {
    Node* odd       = head;
    Node* even      = head->next;
    Node* evenStart = even;
    while (odd->next != NULL && even->next != NULL) {
        odd->next  = even->next;
        odd        = odd->next;
        even->next = odd->next;
        even       = even->next;
    }
    odd->next = evenStart;
}

/* ------------------------       Append Last K nodes to start of Linked List
 * ---------------*/
Node* append(Node*& head, int k) {
    Node* tail = head;
    Node* newTail;
    Node* newHead;
    int   l     = head->length();
    int   count = 1;
    while (tail->next != NULL) {
        if (count == l - k) {
            newTail = tail;
        }
        if (count == l - k + 1) {
            newHead = tail;
        }
        count++;
        tail = tail->next;
    }
    newTail->next = NULL;
    tail->next    = head;
    return newHead;
}

/* --------------------------     Sorting Linked List Using Merge Sort
 * ----------------------------*/
void merge_Sorting(Node** head) {
    if (!head || !(*head)->next) {
        return;
    }
    Node *first = *head, *second;
    Node *fast = first->next, *slow = *head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    second     = slow->next;
    slow->next = NULL;
    merge_Sorting(&first);
    merge_Sorting(&second);
    *head = merge(first, second);
}

int main() {
    Node* head = new Node(10);
    head->insertAtTail(20);
    head->insertAtTail(30);
    head->insertAtTail(40);
    head->displayList();

    head = head->insertAtHead(5);
    head->displayList();

    // cout<< head->search(5)<< "\n";
    // cout<< head->search(25)<< "\n";

    // head->deleteNode(20);
    // head->displayList();

    // head=head->reverseList();
    // head->displayList();

    head = reverseRecursively(head);
    cout << "After Recursion of Linked List: " << endl;
    head->displayList();

    head = reverseK(head, 3);
    cout << "Reverse K node :\n";
    head->displayList();

    // make_cycle(head,0);
    // cout<<detect_cycle(head)<<"\n";
    // remove_cycle(head);
    // cout<<detect_cycle(head)<<"\n";
    // head->displayList();

    Node* head2 = new Node(20);
    head2->insertAtTail(25);
    head2->insertAtTail(30);
    head2->displayList();
    intersect(head, head2, 3);
    head2->displayList();
    cout << "Intersection point : " << intersection_point(head, head2)
         << "\n\n";

    Node* list1 = new Node(1);
    list1->insertAtTail(4);
    list1->insertAtTail(6);
    list1->insertAtTail(8);
    list1->insertAtTail(12);
    list1->displayList();

    Node* list2 = new Node(3);
    list2->insertAtTail(7);
    list2->insertAtTail(9);
    list2->insertAtTail(13);
    list2->insertAtTail(17);
    list2->displayList();

    Node* sorted = merge_recursively(list1, list2);
    cout << "After Merging two Linked List: ";
    sorted->displayList();

    evenAfterOdd(sorted);
    cout << "After Even Odd Linked List: ";
    sorted->displayList();

    merge_Sorting(&sorted);
    cout << "After Merge Sort : ";
    sorted->displayList();

    head->displayList();
    head = append(head, 2);
    head->displayList();
    return 0;
}
