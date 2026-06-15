#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class Stack{
public:
    int arr[5];
    int idx;
    Stack(){
        idx=-1;
    }
    void push(int val){
        if(idx==sizeof(arr)/sizeof(arr[0])-1) cout<<"Stack Overflow";
        arr[++idx]=val;
    }
    void pop(){
        if(idx==-1) cout<<"Stack Underflow!"<<endl;
        idx--;
    }
    int size(){
        return (idx+1);
    }
    int top(){
        if(idx==-1) cout<<"Stack is Empty!"<<endl;
        return arr[idx];
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
    st.push(21); //Stack Overflow
}