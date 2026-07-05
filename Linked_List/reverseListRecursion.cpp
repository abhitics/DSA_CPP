#include <iostream>
using namespace std;

/*
    Problem: Reverse Linked List (Recursion)

    APPROACH:
    ----------
    1. Go till last node recursively
    2. While returning:
            next node points back
    3. Break old connection

    Example:

    1 → 2 → 3 → 4 → 5

    Recursive calls:
    reverse(1)
        reverse(2)
            reverse(3)
                reverse(4)
                    reverse(5)

    Backtracking:
    5→4→3→2→1

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

    // Base case
    if (head == NULL || head->next == NULL)
        return head;

    /*
        Reverse remaining list
    */

    ListNode* newHead = reverseList(head->next);

    /*
        Reverse current connection
    */

    head->next->next = head;

    /*
        Remove old connection
    */

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

    cout << "Original List:\n";

    print(head);

    head = reverseList(head);

    cout << "\nReversed List:\n";

    print(head);

    return 0;
}