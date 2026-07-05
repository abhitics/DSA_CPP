#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

/*
    Problem:
    Basic Calculator

    Supports:
    +  -  ( )

    APPROACH:
    ----------
    Use stack

    stack stores:
    [previous_result, sign]

    On '(':
        save current state

    On ')':
        solve inside bracket
        multiply by sign
        add previous result

    TIME : O(n)
    SPACE: O(n)
*/

int calculate(string s) {

    stack<long long> st;

    long long result = 0;

    long long number = 0;

    long long sign = 1;

    for (char ch : s) {

        /*
            Build number
        */

        if (isdigit(ch)) {

            number =
                number * 10 +
                (ch - '0');
        }

        /*
            Addition
        */

        else if (ch == '+') {

            result +=
                sign * number;

            number = 0;

            sign = 1;
        }

        /*
            Subtraction
        */

        else if (ch == '-') {

            result +=
                sign * number;

            number = 0;

            sign = -1;
        }

        /*
            Open bracket
        */

        else if (ch == '(') {

            st.push(result);

            st.push(sign);

            result = 0;

            number = 0;

            sign = 1;
        }

        /*
            Close bracket
        */

        else if (ch == ')') {

            result +=
                sign * number;

            number = 0;

            result *=
                st.top();

            st.pop();

            result +=
                st.top();

            st.pop();
        }
    }

    return
        result +
        sign * number;
}

int main() {

    string s =
        "(1+(4+5+2)-3)+(6+8)";

    cout
        << "Expression:\n"
        << s
        << endl;

    cout
        << "\nResult:\n"
        << calculate(s)
        << endl;

    return 0;
}