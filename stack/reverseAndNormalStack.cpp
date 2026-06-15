#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
int main(){
    stack<int>st;
    stack<int>temp;
    stack<int>temp2;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<st.size()<<endl;
    //this will print top to down (in REVERSE order)
    while(st.size()){
        cout<<st.top()<<endl;
        temp.push(st.top()); //st->temp
        st.pop();
    }
    cout<<endl;
    //for reversing the content of st-> three stack st,temp,temp2
    
    while(temp.size()){
        temp2.push(temp.top()); //temp->temp2
        temp.pop();
    }
    while(temp2.size()){
        st.push(temp2.top()); //temp2->st
        temp2.pop();
    }
    while(st.size()){
        cout<<st.top()<<endl;
        st.pop();
    }
    
    //for printing in normal order take assist of a extra stack
    //but by this content of st will not change it would save the content of st in normal order and then display it
   
    // while(temp.size()){
    //     st.push(temp.top());
    //     cout<<temp.top()<<endl;
    //     temp.pop();
    // }
}