#include <iostream>
#include <vector>
using namespace std;

/*
    Problem:
    Split Linked List into K Parts

    APPROACH:
    ----------
    1. Count total nodes
    2. Compute:
        splitSize = size / k
        extra = size % k
    3. First "extra" parts get one extra node
    4. Disconnect each part

    TIME : O(n)
    SPACE: O(k)
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
    Print linked list
*/

void print(ListNode* head) {

    if (head == NULL) {
        cout << "NULL";
    }

    while (head != NULL) {
        cout << head->val;

        if (head->next)
            cout << " -> ";

        head = head->next;
    }

    cout << endl;
}

/*
    Split Function
*/

vector<ListNode*> splitListToParts(
    ListNode* head,
    int k
) {

    vector<ListNode*> ans(k);

    int size = 0;

    ListNode* current = head;

    while (current != NULL) {

        size++;

        current = current->next;
    }

    /*
        Minimum size per part
    */

    int splitSize =
        size / k;

    /*
        Extra nodes
    */

    int numRemainingParts =
        size % k;

    current = head;

    ListNode* prev =
        current;

    for (int i = 0; i < k; i++) {

        ListNode* newPart =
            current;

        int currentSize =
            splitSize;

        if (numRemainingParts > 0) {

            currentSize++;

            numRemainingParts--;
        }

        int j = 0;

        while (j < currentSize) {

            prev = current;

            if (current != NULL)
                current =
                    current->next;

            j++;
        }

        /*
            Disconnect
        */

        if (prev != NULL)
            prev->next = NULL;

        ans[i] = newPart;
    }

    return ans;
}

/*
    Main
*/

int main() {

    /*
        Create:
        1→2→3→4→5→6→7→8
    */

    ListNode* head =
        new ListNode(1);

    head->next =
        new ListNode(2);

    head->next->next =
        new ListNode(3);

    head->next->next->next =
        new ListNode(4);

    head->next->next->next->next =
        new ListNode(5);

    head->next->next->next->next->next =
        new ListNode(6);

    head->next->next->next->next->next->next =
        new ListNode(7);

    head->next->next->next->next->next->next->next =
        new ListNode(8);

    int k = 3;

    vector<ListNode*> result =
        splitListToParts(head, k);

    cout << "Split Parts:\n\n";

    for (int i = 0; i < k; i++) {

        cout << "Part "
             << i + 1
             << ": ";

        print(result[i]);
    }

    return 0;
}