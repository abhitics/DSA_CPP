#include <iostream>
using namespace std;

/*
    Problem:
    Remove nodes having a greater
    value somewhere on the right.

    APPROACH:
    ----------
    1. Reverse list
    2. Maintain maximum seen
    3. Remove smaller nodes
    4. Reverse again

    TIME : O(n)
    SPACE: O(n)   // recursion stack
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

ListNode* reverse(ListNode* head){
    if (head == NULL ||head->next == NULL)  return head;

    ListNode* newHead =reverse( head->next );
    head->next->next =head;
    head->next = NULL;
    return newHead;
}

/*
    Remove Nodes
*/

ListNode* removeNodes(ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    /*
        Reverse
    */
    head = reverse(head);
    ListNode* temp = head;
    int mx = temp->val;
    while (temp && temp->next){
        if (temp->next->val < mx){
            temp->next = temp->next->next;
        }else{
            temp = temp->next;
            mx = temp->val;
        }
    }
    /*
        Reverse back
    */
    return reverse(head);
}
void display(ListNode* head){
    while (head) {
        cout<< head->val;
        if (head->next)  cout<< " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    /*
        5 → 2 → 13 → 3 → 8
    */
    ListNode* head = new ListNode(5);
    head->next = new ListNode(2);
    head->next->next = new ListNode(13);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(8);
    cout<< "Original List:\n";
    display(head);
    head =removeNodes(head);
    cout<< "\nAfter Removal:\n";
    display(head);
    return 0;
}