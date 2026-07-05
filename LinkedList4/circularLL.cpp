#include<iostream>
#include<algorithm>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
class Circular{
public:
    Node* head;
    Node* tail;
    int size;
    Circular(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void insertAtHead(int data){
        Node* newNode = new Node(data);

        if(head == NULL){
            head = newNode;
            tail = newNode;
            head->next = head;
            head->prev = head;
        }
        else{
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
            tail->next = newNode;
            head = newNode;
        }         
        size++;
    }
    void insertAtTail(int data){
        Node* newNode=new Node(data);
        if(tail==NULL){
            head=newNode;
            tail=newNode;
            head->next = head;
            head->prev = head;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            newNode->next=head;
            head->prev=newNode;
            tail=newNode;
        }
        size++;
    }
    void insertAtPosition(int data,int position){
        if(position<1 || position>size+1){
            cout<<"Invalid position"<<endl;
            return;
        }
        if(position==1){
            insertAtHead(data);
            return;
        }
        if(position==size+1){
            insertAtTail(data);
            return;
        }
        Node* newNode=new Node(data);
        Node* temp=head;
        for(int i=1;i<position-1;i++){
            temp=temp->next;
        }
        newNode->next=temp->next;
        newNode->prev=temp;
        temp->next=newNode;
        newNode->next->prev=newNode;
        size++;
    }
    void deleteAtBeg(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(size==1) {
            delete head;
            head=NULL;
            tail=NULL;
        }
        else{
            Node* temp=head;
            head=head->next;
            head->prev=tail;
            tail->next=head;
            delete temp;
        }        size--;
    }
    void deleteAtEnd(){
        if(tail==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(size==1) {
            delete tail;
            head=NULL;
            tail=NULL;
        }
        else{
            Node* temp=tail;
            tail=tail->prev;
            tail->next=head;
            head->prev=tail;
            delete temp;
        }        size--;
    }
    void deleteAtPosition(int position){
        if(position<1 || position>size){
            cout<<"Invalid position"<<endl;
            return;
        }
        if(position==1){
            deleteAtBeg();
            return;
        }
        if(position==size){
            deleteAtEnd();
            return;
        }
        Node* temp=head;
        for(int i=1;i<position;i++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
        size--;
    }
    void display(){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=head;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
};
int main(){
    Circular cll;
    cll.insertAtHead(10);
    cll.insertAtTail(20);
    cll.insertAtTail(70);
    cll.insertAtTail(22);    
    cll.insertAtHead(10);
    cll.display();
    cll.insertAtPosition(15,2);
    cll.deleteAtBeg();
    cll.display();
    cll.deleteAtEnd();
    cll.display();
    cll.deleteAtPosition(2);
    cll.display();
    return 0;
}