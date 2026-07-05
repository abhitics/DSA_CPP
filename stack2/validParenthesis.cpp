#include<iostream>
#include<stack>
using namespace std;

/*
Problem:
20. Valid Parentheses

Approach:
Use stack.

Opening bracket:
push

Closing bracket:
check top matches

If mismatch:
return false

At end:
stack must be empty

Time: O(n)
Space: O(n)
*/

bool isValid(string s){
    if(s.length()%2!=0) return false;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')  st.push(s[i]);
        else{
            if(st.empty()) return false;
            if((s[i]==')'&&st.top()!='(') || (s[i]=='}'&&st.top()!='{') || (s[i]==']'&&st.top()!='['))
                return false;
            st.pop();
        }
    }
    return st.empty();
}

int main(){
    string s;
    cin>>s;
    if(isValid(s)) cout<<"true";
    else cout<<"false";

    return 0;
}