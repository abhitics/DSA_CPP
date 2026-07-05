#include <iostream>
using namespace std;

/*
    Problem:
    Add Two Numbers (Linked List)

    APPROACH:
    ----------
    Recursive

    Add:
    current digit +
    carry +
    recurse for next nodes

    Example:

    2 → 4 → 3
    5 → 6 → 4

    342 + 465 = 807

    Output:

    7 → 0 → 8

    TIME : O(max(n,m))
    SPACE: O(max(n,m))
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
    Recursive Addition
*/

ListNode* solve(
    ListNode* l1,
    ListNode* l2,
    int carry
) {

    /*
        Base case
    */

    if (
        l1 == NULL &&
        l2 == NULL &&
        carry == 0
    )
        return NULL;

    int sum = carry;

    if (l1)
        sum += l1->val;

    if (l2)
        sum += l2->val;

    /*
        Current digit
    */

    ListNode* node =
        new ListNode(
            sum % 10
        );

    /*
        Next recursion
    */

    node->next =
        solve(
            l1 ? l1->next : NULL,
            l2 ? l2->next : NULL,
            sum / 10
        );

    return node;
}

/*
    Add function
*/

ListNode* addTwoNumbers(
    ListNode* l1,
    ListNode* l2
) {
    return solve(l1, l2, 0);
}

/*
    Print
*/

void print(ListNode* head) {

    while (head) {

        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    /*
        2 → 4 → 3
    */

    ListNode* l1 =
        new ListNode(2);

    l1->next =
        new ListNode(4);

    l1->next->next =
        new ListNode(3);

    /*
        5 → 6 → 4
    */

    ListNode* l2 =
        new ListNode(5);

    l2->next =
        new ListNode(6);

    l2->next->next =
        new ListNode(4);

    cout << "List 1:\n";

    print(l1);

    cout << "\nList 2:\n";

    print(l2);

    ListNode* result =
        addTwoNumbers(l1, l2);

    cout << "\nResult:\n";

    print(result);

    return 0;
}