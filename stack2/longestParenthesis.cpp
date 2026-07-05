#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
Problem:
32. Longest Valid Parentheses

Approach:
Use stack of indices.

Push -1 initially.

'(' → push index
')' → pop

If stack becomes empty:
push current index

Else:
length=i-st.top()

Store maximum.

Time: O(n)
Space: O(n)
*/

int longestValidParentheses(string s){
    stack<int> st;
    st.push(-1);
    int mx=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') st.push(i);
        else{
            st.pop();
            if(st.empty()) st.push(i);
            else mx=max(mx,i-st.top());
        }
    }
    return mx;
}

int main(){
    string s;
    cin>>s;
    cout<<longestValidParentheses(s);
    return 0;
}