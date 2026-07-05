#include <iostream>
using namespace std;

/*
    Problem: Odd Even Linked List

    APPROACH:
    ----------
    Separate:
        Odd position nodes
        Even position nodes

    Then attach even list at end.

    odd  → jumps by 2
    even → jumps by 2

    TIME: O(n)
    SPACE: O(1)
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
    Print linked list
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

    ListNode* head = new ListNode(1);

    head->next = new ListNode(2);

    head->next->next = new ListNode(3);

    head->next->next->next = new ListNode(4);

    head->next->next->next->next = new ListNode(5);

    cout << "Original List:\n";

    print(head);

    /*
        Edge case
    */

    if (head != NULL &&
        head->next != NULL) {

        ListNode* odd = head;

        ListNode* even = head->next;

        ListNode* temp = even;

        while (even != NULL &&
               even->next != NULL) {

            // connect odd nodes
            odd->next = even->next;

            odd = odd->next;

            // connect even nodes
            even->next = odd->next;

            even = even->next;
        }

        // attach even list
        odd->next = temp;
    }

    cout << "\nOdd Even List:\n";

    print(head);

    return 0;
}