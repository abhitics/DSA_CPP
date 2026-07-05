#include <iostream>
using namespace std;

/*
    Problem: Middle of Linked List (LeetCode 876)

    APPROACH (Two Pointers - Slow & Fast):
    --------------------------------------
    1. Use two pointers:
        - slow → moves 1 step at a time
        - fast → moves 2 steps at a time

    2. When fast reaches end (NULL),
       slow will be at middle node.

    WHY THIS WORKS:
    ---------------
    - fast moves twice as fast as slow
    - so when fast finishes list,
      slow has covered half the distance

    TIME COMPLEXITY: O(n)
    SPACE COMPLEXITY: O(1)
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

int main() {

    /*
        Creating linked list:
        1 -> 2 -> 3 -> 4 -> 5
    */

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Two pointers
    ListNode* slow = head;
    ListNode* fast = head;

    /*
        MOVE POINTERS:
        - slow moves 1 step
        - fast moves 2 steps
    */

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    /*
        slow is at middle node
    */

    cout << "Middle Node Value: " << slow->val << endl;

    return 0;
}