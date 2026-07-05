#include<iostream>
#include<climits>
using namespace std;

/*
Problem: Divide Two Integers

Without:
/ * %

Approach:
Use bit manipulation and left shift

Time: O((log n)^2)
Space: O(1)
*/

int divideNumbers(int dividend,int divisor){

    if(dividend==INT_MIN && divisor==-1)
        return INT_MAX;

    long long a=abs((long long)dividend);
    long long b=abs((long long)divisor);

    long long quotient=0;

    while(a>=b){

        int shift=0;

        while(a>=(b<<(shift+1))){
            shift++;
        }

        quotient+=(1LL<<shift);

        a-=(b<<shift);
    }

    if((dividend<0)^(divisor<0))
        quotient=-quotient;

    return quotient;
}

int main(){

    int dividend,divisor;

    cout<<"Enter dividend: ";
    cin>>dividend;

    cout<<"Enter divisor: ";
    cin>>divisor;

    int ans=divideNumbers(dividend,divisor);

    cout<<"Quotient: "<<ans<<endl;

    return 0;
}