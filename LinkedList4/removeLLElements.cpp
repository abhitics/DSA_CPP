#include <iostream>
using namespace std;

/*
    Problem:
    Remove all nodes whose value = val

    APPROACH:
    ----------
    1. Remove matching nodes from beginning
    2. Traverse list
    3. Skip nodes having target value

    TIME : O(n)
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
    Remove Elements
*/

ListNode* removeElements(
    ListNode* head,
    int val
) {

    /*
        Remove from beginning
    */

    while (
        head &&
        head->val == val
    ) {
        head = head->next;
    }

    ListNode* temp =
        head;

    /*
        Traverse
    */

    while (
        temp &&
        temp->next
    ) {

        if (
            temp->next->val ==
            val
        ) {

            temp->next =
                temp->next->next;

        } else {

            temp =
                temp->next;
        }
    }

    return head;
}

/*
    Print
*/

void print(
    ListNode* head
) {

    while (head) {

        cout
            << head->val;

        if (head->next)
            cout
                << " -> ";

        head =
            head->next;
    }

    cout << endl;
}

int main() {

    /*
        Create:
        1→2→6→3→4→5→6
    */

    ListNode* head =
        new ListNode(1);

    head->next =
        new ListNode(2);

    head->next->next =
        new ListNode(6);

    head->next->next->next =
        new ListNode(3);

    head->next->next->next->next =
        new ListNode(4);

    head->next->next->next->next->next =
        new ListNode(5);

    head->next->next->next->next->next->next =
        new ListNode(6);

    cout
        << "Original List:\n";

    print(head);

    int val =
        6;

    head =
        removeElements(
            head,
            val
        );

    cout
        << "\nAfter Removal:\n";

    print(head);

    return 0;
}