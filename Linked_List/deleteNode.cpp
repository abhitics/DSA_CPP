#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

void display(ListNode* head) {
    while (head != NULL) {
        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    // Create list: 4 -> 5 -> 1 -> 9

    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Original List:\n";
    display(head);

    // Delete node 5
    ListNode* node = head->next;

    node->val = node->next->val;

    ListNode* temp = node->next;

    node->next = node->next->next;

    delete temp;

    cout << "\nAfter Deletion:\n";
    display(head);

    return 0;
}