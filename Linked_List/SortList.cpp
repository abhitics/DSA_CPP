#include <iostream>
using namespace std;

/*
    Problem: Sort Linked List

    APPROACH (Merge Sort):
    ----------------------

    STEP 1:
    Find middle using slow & fast

    STEP 2:
    Split into:
        left half
        right half

    STEP 3:
    Recursively sort both halves

    STEP 4:
    Merge both sorted lists

    TIME: O(n log n)
    SPACE: O(log n)
*/

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void print(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

/*
    Merge two sorted lists
*/

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

    ListNode* c = new ListNode(100);

    ListNode* temp = c;

    while (a != nullptr && b != nullptr) {

        if (a->val >= b->val) {

            temp->next = b;

            b = b->next;
        }

        else {

            temp->next = a;

            a = a->next;
        }

        temp = temp->next;
    }

    if (a == nullptr)
        temp->next = b;

    else
        temp->next = a;

    return c->next;
}

/*
    Merge Sort
*/

ListNode* sortList(ListNode* head) {

    if (head == NULL || head->next == NULL)
        return head;

    /*
        Find middle
    */

    ListNode* slow = head;

    ListNode* fast = head;

    while (fast->next != NULL &&
           fast->next->next != NULL) {

        slow = slow->next;

        fast = fast->next->next;
    }

    /*
        Split
    */

    ListNode* a = head;

    ListNode* b = slow->next;

    slow->next = NULL;

    /*
        Recursive sorting
    */

    a = sortList(a);

    b = sortList(b);

    /*
        Merge
    */

    return mergeTwoLists(a, b);
}

int main() {

    /*
        Create:
        4 → 2 → 1 → 3 → 5
    */

    ListNode* head = new ListNode(4);

    head->next = new ListNode(2);

    head->next->next = new ListNode(1);

    head->next->next->next = new ListNode(3);

    head->next->next->next->next = new ListNode(5);

    cout << "Original List:\n";

    print(head);

    head = sortList(head);

    cout << "\nSorted List:\n";

    print(head);

    return 0;
}