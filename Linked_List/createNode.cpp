#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std; 
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
int main(){
    Node a(10);
    Node b(12);
    Node c(23);
    a.next=&b;
    b.next=&c;
    c.next=NULL;
    cout<<a.val;
}