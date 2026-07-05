#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList {

public:
    Node* head;
    Node* tail;

    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void display() {

        Node* temp = head;

        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int Size() {

        int count = 0;

        Node* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // O(1)
    void InsertEnd(int val) {

        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;

        tail = newNode;
    }

    // O(1)
    void InsertBegin(int val) {

        Node* newNode = new Node(val);

        if (head == NULL) {
            head = tail = newNode;
            return;
        }

        newNode->next = head;

        head = newNode;
    }

    // O(n)
    void insertAt(int idx, int val) {

        int sz = Size();

        if (idx < 0 || idx > sz) {
            cout << "Invalid Index\n";
            return;
        }

        if (idx == 0) {
            InsertBegin(val);
            return;
        }

        if (idx == sz) {
            InsertEnd(val);
            return;
        }

        Node* temp = head;

        for (int i = 1; i <= idx - 1; i++) {
            temp = temp->next;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;

        temp->next = newNode;
    }

    // O(n)
    int getElement(int idx) {

        int sz = Size();

        if (idx < 0 || idx >= sz) {
            cout << "Invalid Index\n";
            return -1;
        }

        if (idx == 0)
            return head->val;

        if (idx == sz - 1)
            return tail->val;

        Node* temp = head;

        for (int i = 0; i < idx; i++) {
            temp = temp->next;
        }

        return temp->val;
    }
    
    void deleteAtBeg(){
        int size=Size();
        if(size==0)  cout<<"List is empty!!";
        if(size==1){
            head=tail=NULL;
            size--;
        } 
        if(size>1){
            head=head->next;
            size--;
        }
    }
    
    void deleteAtEnd(){
        int size=Size();
        if(size==0) cout<<"Invalid Linked list!!";
         if(size==1){
            head=tail=NULL;
            size--;
        } 
        if(size>1){
            Node* temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            temp->next=NULL;
            tail=temp;
            size--;
        }
    }
    
    void deleteAt(int idx){
        int sz = Size();

        if (idx < 0 || idx > sz) {
            cout << "Invalid Index\n";
            return;
        }
        if (idx == 0) {
            deleteAtBeg();
            return;
        }
        if (idx == sz) {
            deleteAtEnd();
            return;
        }
        Node* temp=head;
        for(int i=1;i<idx-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        sz--;
        
    }
};

int main() {

    LinkedList ll;

    ll.InsertEnd(12);
    ll.InsertEnd(22);

    cout << "Size: " << ll.Size() << endl;

    ll.InsertBegin(45);

    cout << "Size: " << ll.Size() << endl;

    ll.InsertEnd(89);

    cout << "List: ";
    ll.display();

    ll.insertAt(3, 456);

    cout << "After Insert: ";
    ll.display();
    cout << "Size: " << ll.Size() << endl;

    cout << "Element at index 4: ";
    cout << ll.getElement(4) << endl;
    ll.deleteAtBeg();
    ll.display();
    cout << "After deletion Size: " << ll.Size() << endl;
    ll.deleteAtEnd();
    ll.display();
    cout << "After deletion Size: " << ll.Size() << endl;
    ll.deleteAt(1);
    ll.display();
    return 0;
}