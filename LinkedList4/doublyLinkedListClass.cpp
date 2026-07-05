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
class DoublyLinkedList{
public:
    Node* head;
    Node* tail;
    int size;
    DoublyLinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void insertAtHead(int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
        size++;
    }
    void insertAtTail(int data){
        Node* newNode=new Node(data);
        if(tail==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
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
        temp->next->prev=newNode;
        temp->next=newNode;
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
            head->prev=NULL;
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
            tail->next=NULL;
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
    int getAtIdx(int index){
        if(index<0 || index>=size){
            cout<<"Invalid index"<<endl;
            return -1;
        }
        Node* temp=head;
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->data;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    DoublyLinkedList dll;
    dll.insertAtHead(10);
    dll.insertAtTail(20);
    dll.insertAtTail(70);
    dll.insertAtTail(22);    
    dll.insertAtHead(10);
    dll.insertAtPosition(15,2);
    dll.display();
    dll.deleteAtBeg();
    dll.display();
    dll.deleteAtEnd();
    dll.display();
    dll.deleteAtPosition(2);
    dll.display();
    return 0;
}