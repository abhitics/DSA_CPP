#include <iostream>
using namespace std;

/*
    Problem: Rotate Linked List Right by K

    APPROACH:
    ----------
    1. Find length of list (n)s
    2. Store tail node
    3. Reduce rotations:
            k = k % n
    4. Move to new tail:
            position = n - k
    5. Connect tail → head
    6. New head = temp->next
    7. Break circular connection

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

    int k = 2;

    cout << "Original List: ";
    print(head);

    /*
        Edge cases
    */

    if (head != nullptr &&
        head->next != nullptr &&
        k != 0) {

        ListNode* temp = head;
        ListNode* tail = NULL;

        int n = 0;

        /*
            Find length and tail
        */

        while (temp != NULL) {

            if (temp->next == nullptr)
                tail = temp;

            temp = temp->next;

            n++;
        }

        /*
            Reduce unnecessary rotations
        */

        k = k % n;

        if (k != 0) {

            temp = head;

            /*
                Move to new tail
            */

            for (int i = 1; i < n - k; i++) {
                temp = temp->next;
            }

            /*
                Make circular
            */

            tail->next = head;

            /*
                New head
            */

            head = temp->next;

            /*
                Break circle
            */

            temp->next = NULL;
        }
    }

    cout << "Rotated List: ";
    print(head);

    return 0;
}