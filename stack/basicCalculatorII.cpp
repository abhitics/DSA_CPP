#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
Problem:
227. Basic Calculator II

Approach:
Use stack.

+ → push number
- → push negative number
* → calculate immediately
/ → calculate immediately

At end:
sum stack

Example:
3+2*2

stack:
[3]
[3,2]
[3,4]

sum=7

Time: O(n)
Space: O(n)
*/

int calculate(string s){

    stack<int> st;

    long long num=0;

    char op='+';

    for(int i=0;i<=s.size();i++){

        if(i<s.size() && isdigit(s[i]))
            num=num*10+(s[i]-'0');

        if(
            i==s.size() ||
            (
                s[i]!=' ' &&
                !isdigit(s[i])
            )
        ){

            if(op=='+')
                st.push(num);

            else if(op=='-')
                st.push(-num);

            else if(op=='*'){

                int x=st.top();

                st.pop();

                st.push(x*num);
            }

            else if(op=='/'){

                int x=st.top();

                st.pop();

                st.push(x/num);
            }

            op=s[i];

            num=0;
        }
    }

    int ans=0;

    while(!st.empty()){

        ans+=st.top();

        st.pop();
    }

    return ans;
}

int main(){

    string s;

    cout<<"Enter expression: ";

    getline(cin,s);

    cout<<calculate(s);

    return 0;
}