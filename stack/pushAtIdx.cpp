#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    stack<int>st;
    stack<int>temp;
    int x,idx;
    cout<<"Enter number to push: ";
    cin>>x;
    cout<<"Enter idx where to push: ";
    cin>>idx;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    if(idx==st.size()-1) st.push(x);
    for(int i=0;i<=st.size()-idx+1;i++){
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while(temp.size()){
        st.push(temp.top());
        temp.pop();
    }
    while(st.size()){
        cout<<st.top()<<" ";
        st.pop();
    }

}