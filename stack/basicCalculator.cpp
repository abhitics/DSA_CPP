#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*
Problem:
224. Basic Calculator

Supports:
+  -
( )

Approach:
Use stack to store:
1. Previous result
2. Previous sign

When '(':
save current state

When ')':
finish current expression
multiply by stored sign
add previous result

Time: O(n)
Space: O(n)
*/

int calculate(string s){

    stack<long long> st;

    long long result=0;

    long long number=0;

    long long sign=1;

    for(char ch:s){

        if(isdigit(ch)){

            number=
                number*10+
                (
                    ch-'0'
                );
        }

        else if(ch=='+'){

            result+=
                sign*
                number;

            number=0;

            sign=1;
        }

        else if(ch=='-'){

            result+=
                sign*
                number;

            number=0;

            sign=-1;
        }

        else if(ch=='('){

            st.push(result);

            st.push(sign);

            result=0;

            number=0;

            sign=1;
        }

        else if(ch==')'){

            result+=
                sign*
                number;

            number=0;

            result*=
                st.top();

            st.pop();

            result+=
                st.top();

            st.pop();
        }
    }

    return
        (
            int
        )
        (
            result+
            sign*
            number
        );
}

int main(){

    string s;

    cout<<"Enter expression: ";

    getline(cin,s);

    cout<<calculate(s);

    return 0;
}