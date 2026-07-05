#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s="aabbbbcddejaaa";
    stack<char>st;
    for(int i=0;i<s.length();i++){
        if(!st.empty() && st.top()==s[i]) continue;
        else{
            st.push(s[i]);
        }
    }
    string ans="";
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
}