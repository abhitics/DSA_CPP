#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Stack{
public:
    vector<int>st;  //it would never had the problem of stack overflow
    Stack(){
    }
    void push(int val){
        st.push_back(val);
    }
    void pop(){
        if(st.size()==0) cout<<"Stack Underflow!"<<endl;
        st.pop_back();
    }
    int size(){
        return st.size();
    }
    int top(){
        if(st.size()==0) cout<<"Stack is Empty!"<<endl;
        return st[st.size()-1];
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