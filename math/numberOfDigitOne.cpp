#include<iostream>
using namespace std;

/*
Problem: Count Digit One

Count total occurrences of digit '1'
from 1 to n

Approach:
Check each digit position separately

Time: O(log10(n))
Space: O(1)
*/

int countDigitOne(int n){

    long factor=1;
    long count=0;

    while(factor<=n){

        long lower=n%factor;

        long current=(n/factor)%10;

        long higher=n/(factor*10);

        if(current==0)
            count+=higher*factor;

        else if(current==1)
            count+=higher*factor+lower+1;

        else
            count+=(higher+1)*factor;

        factor*=10;
    }

    return count;
}

int main(){

    int n;

    cout<<"Enter n: ";
    cin>>n;

    cout<<"Count of digit 1: "
        <<countDigitOne(n)
        <<endl;

    return 0;
}