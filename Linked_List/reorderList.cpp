#include <iostream>
using namespace std;

/*
    Problem: Reorder List

    APPROACH:
    ----------
    1. Find middle
    2. Reverse second half
    3. Merge:
        first → second → first → second

    Example:

    1 → 2 → 3 → 4 → 5

    becomes

    1 → 5 → 2 → 4 → 3

    TIME: O(n)
    SPACE: O(n) recursion stack
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
    Recursive Reverse
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
    Print List
*/

void print(ListNode* head) {

    while (head != NULL) {

        cout << head->val << " ";

        head = head->next;
    }

    cout << endl;
}

/*
    Reorder
*/

void reorderList(ListNode* head) {

    if (head == NULL ||
        head->next == NULL)
        return;

    ListNode* slow = head;

    ListNode* fast = head;

    while (
        fast != NULL &&
        fast->next != NULL
    ) {

        slow = slow->next;

        fast = fast->next->next;
    }

    /*
        Reverse second half
    */

    ListNode* b =
        reverseList(slow->next);

    ListNode* a = head;

    slow->next = NULL;

    /*
        Build reordered list
    */

    ListNode* c =
        new ListNode(100);

    ListNode* tempC = c;

    while (a && b) {

        tempC->next = a;

        a = a->next;

        tempC = tempC->next;

        tempC->next = b;

        b = b->next;

        tempC = tempC->next;
    }

    if (a)
        tempC->next = a;

    /*
        Update original head
    */

    head->val = c->next->val;

    head->next = c->next->next;
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

    cout << "Original List:\n";

    print(head);

    reorderList(head);

    cout << "\nReordered List:\n";

    print(head);

    return 0;
}