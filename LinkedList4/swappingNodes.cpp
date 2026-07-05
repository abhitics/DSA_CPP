#include <iostream>
using namespace std;

/*
    Problem:
    Swap kth node from beginning
    with kth node from end

    APPROACH:
    ----------
    1. Count total nodes
    2. Reach kth node → a
    3. Reach kth node from end → b
    4. Swap values

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

void display(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

ListNode* swapNodes(ListNode* head,int k) 
    {
        if (head == NULL || head->next == NULL) return head;
        int n = 0;
        ListNode* temp =head;
        /*
            Count nodes
        */
        while (temp) {
            n++;
            temp = temp->next;
        }
        ListNode* a =head;
        ListNode* b =head;
        /*
            kth node from start
        */
        for (int i = 1;i < k;i++)  a =a->next;
        /*
            kth node from end
        */
        for (int i = 0;i < n - k;i++) b = b->next;
        /*
            Swap values
        */
        int t = a->val;
        a->val = b->val;
        b->val = t;
        return head;
    }
int main() {
    /*
        1 → 2 → 3 → 4 → 5
    */
    ListNode* head =new ListNode(1);
    head->next =new ListNode(2);
    head->next->next =  new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next =new ListNode(5);
    cout<< "Original List:\n";
    display(head);

    int k = 2;

    head =swapNodes(head,k);
    cout<< "\nAfter Swap:\n";
    display(head);

    return 0;
}