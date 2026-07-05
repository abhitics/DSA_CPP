#include <iostream>
using namespace std;

/*
    Problem: Reverse Linked List II

    APPROACH:
    ----------
    a → node before left
    b → left node
    c → right node
    d → node after right

    Cut:
        a → NULL
        c → NULL

    Reverse:
        reverse(b)

    Connect:
        a → reversed
        b → d

    TIME: O(n)
    SPACE: O(right-left) recursion stack
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

/*
    Recursive reverse
*/

ListNode* reverseList(ListNode* head) {

    if (head == NULL ||
        head->next == NULL)
        return head;

    ListNode* newHead =
        reverseList(head->next);

    head->next->next = head;

    head->next = NULL;

    return newHead;
}

/*
    Print list
*/

void print(ListNode* head) {

    while (head != NULL) {

        cout << head->val << " ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    /*
        Create:
        1 → 2 → 3 → 4 → 5
    */

    ListNode* head =
        new ListNode(1);

    head->next =
        new ListNode(2);

    head->next->next =
        new ListNode(3);

    head->next->next->next =
        new ListNode(4);

    head->next->next->next->next =
        new ListNode(5);

    int left = 2;

    int right = 4;

    cout << "Original List:\n";

    print(head);

    ListNode* a = NULL;

    ListNode* b = NULL;

    ListNode* c = NULL;

    ListNode* d = NULL;

    ListNode* temp = head;

    int n = 1;

    while (temp) {

        if (n == left - 1)
            a = temp;

        if (n == left)
            b = temp;

        if (n == right)
            c = temp;

        if (n == right + 1)
            d = temp;

        temp = temp->next;

        n++;
    }

    if (a)
        a->next = NULL;

    c->next = NULL;

    c = reverseList(b);

    if (a)
        a->next = c;

    b->next = d;

    if (!a)
        head = c;

    cout << "\nReversed List:\n";

    print(head);

    return 0;
}