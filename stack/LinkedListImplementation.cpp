#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        next=NULL;
    }
};
class Stack{
public:
    Node* head;  
    Stack(){
        head=NULL;
    }
    void push(int val){
        Node* temp=new Node(val);
        temp->next=head;
        head=temp;
    }
    void pop(){
    if(head==NULL){
        cout<<"Stack Underflow!"<<endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
}
    int size(){
        Node* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
    }
    int top(){
    if(head==NULL){
        cout<<"Stack is Empty!"<<endl;
        return -1;
    }
        return head->val;
    }
};
int main(){
    Stack st;
    cout<<st.size()<<endl;
    // st.top();  ->Stack is Empty!
    // st.pop();  ->Stack Underflow!
    st.push(12);
    st.push(22);
    st.pop();
    cout<<st.size()<<endl;
    st.push(21);
    cout<<st.size()<<endl;
    st.push(21);
    st.push(21);
    st.push(21);
    cout<<st.size()<<endl;
}