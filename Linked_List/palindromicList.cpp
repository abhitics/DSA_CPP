#include <iostream>
using namespace std;

/*
    Problem: Check if Linked List is Palindrome

    APPROACH:
    ----------
    1. Find middle using slow + fast
    2. Reverse second half (Recursion)
    3. Compare first half and reversed half

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

ListNode* reverse(ListNode* head) {

    if (head == NULL || head->next == NULL)
        return head;

    ListNode* newHead =
        reverse(head->next);

    head->next->next = head;

    head->next = NULL;

    return newHead;
}

/*
    Palindrome Check
*/

bool isPalindrome(ListNode* head) {

    if (head == NULL ||
        head->next == NULL)
        return true;

    /*
        Find middle
    */

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

    slow = reverse(slow);

    /*
        Compare both halves
    */

    ListNode* temp = head;

    while (slow != NULL) {

        if (temp->val != slow->val)
            return false;

        temp = temp->next;

        slow = slow->next;
    }

    return true;
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

int main() {

    /*
        Create:
        1 → 2 → 3 → 2 → 1
    */

    ListNode* head =
        new ListNode(1);

    head->next =
        new ListNode(2);

    head->next->next =
        new ListNode(3);

    head->next->next->next =
        new ListNode(2);

    head->next->next->next->next =
        new ListNode(1);

    cout << "Original List:\n";

    print(head);

    if (isPalindrome(head))
        cout << "\nPalindrome\n";

    else
        cout << "\nNot Palindrome\n";

    return 0;
}