#include <iostream>
using namespace std;

/*
    Problem: Partition List

    APPROACH:
    ----------
    Create two lists:

    lo → nodes < x
    hi → nodes >= x

    Traverse:
        append node to correct list

    Finally:
        low list + high list

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
    Print List
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
        1 → 4 → 3 → 2 → 5 → 2
    */

    ListNode* head = new ListNode(1);

    head->next = new ListNode(4);

    head->next->next = new ListNode(3);

    head->next->next->next = new ListNode(2);

    head->next->next->next->next = new ListNode(5);

    head->next->next->next->next->next =
        new ListNode(2);

    int x = 3;

    cout << "Original List:\n";

    print(head);

    /*
        Partition Logic
    */

    if (head != NULL &&
        head->next != NULL) {

        ListNode* lo = new ListNode(100);

        ListNode* hi = new ListNode(100);

        ListNode* tempL = lo;

        ListNode* tempH = hi;

        ListNode* temp = head;

        while (temp != NULL) {

            if (temp->val < x) {

                tempL->next = temp;

                tempL = tempL->next;

            }

            else {

                tempH->next = temp;

                tempH = tempH->next;
            }

            temp = temp->next;
        }

        tempH->next = NULL;

        tempL->next = hi->next;

        head = lo->next;
    }

    cout << "\nPartitioned List:\n";

    print(head);

    return 0;
}