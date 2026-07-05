#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout<<endl;
}
void display(Node* head) {
    if (head == NULL) return;
    cout << head->val << " ";
    display(head->next);
}
void displayReverseRec(Node* head) {
    if (head == NULL) return;
    displayReverseRec(head->next);
    cout << head->val << " ";
}
void displayReverse(Node* tail) {
    if (tail == NULL) return;
    cout << tail->val << " ";
    displayReverse(tail->prev);
}
int main() {
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    b->prev=a;
    c->prev=b;
    d->prev=c;
    display(a);
    displayReverseRec(a);
    cout<<endl;
    displayReverse(d);
}