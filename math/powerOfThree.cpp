#include<iostream>
using namespace std;

/*
Problem: Power of Three

Approach:
Largest power of 3 inside
32-bit integer = 3^19

3^19 = 1162261467

If n divides 3^19 exactly,
then n must also be a power of 3.

Time: O(1)
Space: O(1)
*/

bool isPowerOfThree(int n){
    return n>0 && 1162261467%n==0;
}

int main(){

    int n;

    cout<<"Enter number: ";
    cin>>n;

    if(isPowerOfThree(n))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    return 0;
}