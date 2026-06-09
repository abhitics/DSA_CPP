#include <iostream>
#include <vector>
using namespace std;

/*
    Problem: Merge K Sorted Linked Lists

    APPROACH:
    ----------
    1. Take first two lists
    2. Merge them
    3. Push merged list back
    4. Repeat until one list remains

    mergeTwoLists():
        Standard merge of two sorted lists

    TIME:
        O(N × K)

    SPACE:
        O(1)
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

/*
    Merge two sorted lists
*/

ListNode* mergeTwoLists(ListNode* a, ListNode* b) {

    ListNode* c = new ListNode(100);

    ListNode* temp = c;

    while (a != nullptr && b != nullptr) {

        if (a->val >= b->val) {

            temp->next = b;

            b = b->next;

        } else {

            temp->next = a;

            a = a->next;
        }

        temp = temp->next;
    }

    if (a == nullptr)
        temp->next = b;

    else
        temp->next = a;

    return c->next;
}

/*
    Merge K Lists
*/

ListNode* mergeKLists(vector<ListNode*>& arr) {

    if (arr.size() == 0)
        return NULL;

    while (arr.size() > 1) {

        ListNode* a = arr[0];

        arr.erase(arr.begin());

        ListNode* b = arr[0];

        arr.erase(arr.begin());

        ListNode* c = mergeTwoLists(a, b);

        arr.push_back(c);
    }

    return arr[0];
}

int main() {

    /*
        List 1:
        1 → 4 → 7
    */

    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(7);

    /*
        List 2:
        2 → 5 → 8
    */

    ListNode* l2 = new ListNode(2);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(8);

    /*
        List 3:
        3 → 6 → 9
    */

    ListNode* l3 = new ListNode(3);
    l3->next = new ListNode(6);
    l3->next->next = new ListNode(9);

    vector<ListNode*> arr;

    arr.push_back(l1);
    arr.push_back(l2);
    arr.push_back(l3);

    ListNode* result = mergeKLists(arr);

    cout << "Merged K Lists:\n";

    print(result);

    return 0;
}